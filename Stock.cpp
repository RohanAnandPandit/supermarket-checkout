#include "Stock.h"
#include <unordered_map>
#include <string>

void Stock::AddItem(std::string name, int price) {
    prices_[name] = price;
}


int Stock::GetPrice(std::string name) {
    return prices_[name];
}
