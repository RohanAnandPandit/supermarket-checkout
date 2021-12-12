#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "SupermarketCheckout.h"
#include "Stock.h"
#include "Order.h"

int main()
{
    Stock stock;
    std::ifstream stock_input("prices.txt");
    std::string item, line;
    int unit_price;

    while (getline(stock_input, line)) {
        std::istringstream ss(line);
        ss >> item;
        ss >> unit_price;
        stock.AddUnitPrice(item, unit_price);
    }

    stock_input.close();

    Order order;
    std::ifstream order_input("items.txt");
    while (getline(order_input, item)) {
        order.AddItem(item);
    }
    order_input.close();

    std::vector<std::string> discount_items{"Apple", "Book", "c"};

    SupermarketCheckout checkout(stock, discount_items);
    std::cout << checkout.Buy(order) << std::endl;
}