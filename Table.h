#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <memory>
#include <random>
#include <string>

#include "Item.h"
#include <iostream>
#include "items/Food.h"
#include "items/Gadget.h"
#include "items/Drink.h"
#include "items/Hygiene.h"
#include "items/Clothes.h"

class Table
{
private:
    std::vector<std::unique_ptr<Item>> items;
    std::mt19937 rng;
    

    std::string generateRandomName(const std::string& prefix);
    double generateRandomWeight();
    double generateRandomPrice();

public:
    Table();
    explicit Table(std::vector<std::unique_ptr<Item>> itemsToAdd);

    void generateItems();
    const std::vector<std::unique_ptr<Item>>& getItems() const;
    void displayItems() const;
    std::unique_ptr<Item> takeItem(size_t index);
};

#endif // TABLE_H