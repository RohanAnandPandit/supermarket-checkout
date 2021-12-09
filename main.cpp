#include <iostream>
#include <vector>
#include "SupermarketCheckout.h"
#include "Stock.h"
#include "Order.h"

int main()
{
    std::cout << "Hello World" << std::endl;

    Stock stock;
    stock.AddItem("Book", 10);
    stock.AddItem("Apple", 1);

    Order order;
    for (int i = 0; i < 5; i++) {
        order.AddItem("Book");
        order.AddItem("Apple");
    }
    SupermarketCheckout checkout(stock);
    std::cout << checkout.Buy(order) << std::endl;
}