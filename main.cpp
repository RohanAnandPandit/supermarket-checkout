#include <iostream>
#include <vector>
#include "Supermarket.h"
#include "Checkout.h"

int main()
{
    std::cout << "Hello World" << std::endl;

    Supermarket supermarket;
    std::vector<std::string> discount_items;
    for (int i = 0; i < 3; i++) {
        discount_items.push_back(std::string("Item " + std::to_string(i)));
    }
    Checkout checkout(supermarket, discount_items);
}