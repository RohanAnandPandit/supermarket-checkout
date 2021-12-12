#include "SupermarketCheckout.h"
#include <string>
#include <unordered_map>
#include "Order.h"

SupermarketCheckout::SupermarketCheckout(Stock &stock, std::vector<std::string> &discount_items) 
    : stock_(stock), discount_items_(discount_items) {
}

std::string SupermarketCheckout::Buy(Order &order) {
    std::string bill = "*******BILL*********\n";
    int total = 0, price, freq;
    bill.append("+ Item: Unit Price x Quantity\n");

    for (auto item : order.GetItems()) {
        freq = order.GetFrequency(item);
        price = stock_.GetPrice(item) * freq;
        total += price;
        bill.append("+ " + item + ": ");
        bill.append("£" + std::to_string(stock_.GetPrice(item)) + " x " + std::to_string(freq));
        bill.append(" = £" + std::to_string(price));
        bill.append("\n");
    }

    bill.append("\n");
    bill.append("Subtotal: £" + std::to_string(total));
    bill.append("\n\n");
    bill.append("--------------------\n");
    bill.append(":) Discounts :)\n");

    std::unordered_map<std::string, int> payment_freq = order.AllFrequencies();
    int total_discount = 0;
    total_discount += BuyThreePayForTwo(order.GetItems(), payment_freq, bill);
    bill.append("\n");

    total_discount += BuyThreeCheapestIsFree(payment_freq, bill);
    bill.append("\n");
    bill.append("--------------------\n");
    bill.append("Total discounts: -£" + std::to_string( total_discount));
    bill.append("\n");
    total -= total_discount;
    bill.append("Grand total: £" + std::to_string(total));
    bill.append("\n*******************\n");
    return bill;
}

int SupermarketCheckout::BuyThreePayForTwo(std::vector<std::string> items, 
    std::unordered_map<std::string, int> &freq, std::string &bill) {
    bill.append("> Buy Three Pay for Two\n");
    int total_discount = 0, price, n, free;

    for (auto item : items) {
        n = freq[item];
        free = n / 3;
        freq[item] -= free;
        if (free > 0) {
            price = stock_.GetPrice(item);
            total_discount += free * price;
            bill.append("- " + item + " x " + std::to_string(free) + " = £" + std::to_string(free * price));
            bill.append("\n");
        }
    }

    return total_discount;
}

int SupermarketCheckout::BuyThreeCheapestIsFree(std::unordered_map<std::string, int> &freq, std::string &bill) {
    bill.append("> Buy Three from (");
    bool first = true;
    for (auto item : discount_items_) {
        if (!first) {
            bill.append(", ");
        }
        first = false;
        bill.append(item);
    }
    bill.append(") and cheapest is free\n");

    int total_discount = 0, min_price = -1, curr_price;
    std::string cheapest_item;
    int set_items = 0;

    for (auto item : discount_items_) {
        for (int i = 0; i < freq[item]; i++) {
            curr_price = stock_.GetPrice(item);
            if (min_price == -1 || curr_price < min_price) {
                cheapest_item = item;
                min_price = curr_price;
            } 
            set_items += 1;
            if (set_items == 3) {
                total_discount += min_price;
                bill.append("- £" + std::to_string(min_price) + " for " + cheapest_item);
                set_items = 0;
                min_price = -1;
            }
        }
    }

    return total_discount;
}