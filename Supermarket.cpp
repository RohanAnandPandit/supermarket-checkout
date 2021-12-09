#include "Supermarket.h"


void Supermarket::AddItem(string name, int price) {
    prices_.insert(std::make_pair<std::string, int>(name, price));
}


int Supermarket::GetPrice(std::string name) {
    return prices_[name];
}
