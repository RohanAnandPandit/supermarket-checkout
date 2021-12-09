#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "Supermarket.h"
#include <string>

class Checkout {
public:
    Checkout(Supermarket &supermarket, std::vector<std::string> &discount_items);

    std::string Buy(std::vector<std::string> items);

private:
    Supermarket &supermarket_;
    std::vector<std::string> &discount_items_;
};

#endif