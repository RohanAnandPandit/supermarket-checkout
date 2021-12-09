#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <vector>
#include <string>
#include "Stock.h"


class SupermarketCheckout {
public:
    SupermarketCheckout(Stock &stock);

    std::string Buy(Order &order);

private:
    Stock &stock_;
};

#endif