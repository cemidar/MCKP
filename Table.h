#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <memory>
#include <random>
#include <string>

#include "Item.h"
#include <iostream>


class Table
{
private:
    std::vector<std::unique_ptr<Item>> items;
    std::mt19937 rng;
    

    double generateRandomWeight();
    double generateRandomPrice();
    int generateRandomClassId();

public:
    Table();
    explicit Table(std::vector<std::unique_ptr<Item>> itemsToAdd);

    void generateItems();
    void generateItems(int classAmount);

    const std::vector<std::unique_ptr<Item>>& getItems() const;
    void displayItems() const;
};

#endif // TABLE_H