#include "SupermarketCheckout.h"
#include <string>

SupermarketCheckout::SupermarketCheckout(Stock &stock) 
    : stock_(stock) {
}

std::string SupermarketCheckout::Buy(Order &order) {
    std::string bill = "";
    int price = 0;
    std::vector<std::string> items = order.GetItems();
    for (auto item : items) {
        price += stock_.GetPrice(item) * order.GetFrequency(item);
    }
    bill = "The total price is: " + std::to_string(price);

    return bill;
}