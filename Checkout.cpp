#include "Checkout.h"
#include <string>

Checkout::Checkout(Supermarket &supermarket, std::vector<std::string> &discount_items) : supermarket_(supermarket), 
discount_items_(discount_items_) {}

std::string Checkout::Buy(std::vector<std::string> items) {
    std::string bill = "";

    return bill;
}