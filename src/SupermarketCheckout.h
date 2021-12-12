#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <vector>
#include <string>
#include "Stock.h"


class SupermarketCheckout {
public:
    SupermarketCheckout(Stock &stock, std::vector<std::string> &discount_items);

    std::string Buy(Order &order);

private:
    Stock &stock_;
    std::vector<std::string> &discount_items_;

    int BuyThreePayForTwo(std::vector<std::string> items, 
        std::unordered_map<std::string, int> &freq, std::string &bill);
        
    int BuyThreeCheapestIsFree(std::unordered_map<std::string, int> &freq, std::string &bill);

    void ApplyDiscounts(Order &order, int &total, std::string &bill);

    void AddSubtotal(Order &order, int &total, std::string &bill);
};

#endif