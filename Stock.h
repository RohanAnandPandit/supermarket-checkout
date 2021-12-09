#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <unordered_map>
#include <string>
#include "Order.h"

class Stock {
public:
    void AddItem(std::string name, int price);

    int GetPrice(std::string);

private:
    std::unordered_map<std::string, int> prices_;
};

#endif