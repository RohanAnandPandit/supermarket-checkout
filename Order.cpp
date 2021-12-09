#include "Order.h"

Order::Order() {}

bool Order::ContainsItem(std::string item) {
    return item_freq_.count(item) == 1;
}

int Order::GetFrequency(std::string item) {
    return item_freq_[item];
}

std::vector<std::string> Order::GetItems() {
    std::vector<std::string> items;
    for (auto pair : item_freq_) {
        items.push_back(pair.first);
    }
    return items;
}

void Order::AddItem(std::string item) {
    if (!ContainsItem(item)) {
        item_freq_[item] = 0;
    }
    item_freq_[item] = item_freq_[item] + 1;
}