#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <vector>
#include <unordered_map>
#include <string>

class Order {
public:
    Order();

    void AddItem(std::string item);

    std::vector<std::string> GetItems();

    int GetFrequency(std::string item);

    std::unordered_map<std::string, int> AllFrequencies();

private:
    std::unordered_map<std::string, int> item_freq_;

    bool ContainsItem(std::string item);
};

#endif