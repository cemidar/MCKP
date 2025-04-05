#include "Table.h"

#include <cassert>

Table::Table() : rng(std::random_device{}()) {
}

// ALternative constructor
Table::Table(std::vector<std::unique_ptr<Item>> itemsToAdd) : rng(std::random_device{}()) {
    // Move items from itemsToAdd to items
    for (auto& item : itemsToAdd) {
        items.push_back(std::move(item));
    }
}

double Table::generateRandomWeight() {
    std::uniform_real_distribution<double> weightDist(1.0, 50.0);
    return weightDist(rng);
}

double Table::generateRandomPrice() {
    std::uniform_real_distribution<double> priceDist(1.0, 50.0);
    return priceDist(rng);
}

int Table::generateRandomClassId()
{
    return 10;
}

void Table::generateItems() {
    items.clear();
    auto classAmount = generateRandomClassId();

    for (int i = 0; i < classAmount; i++) {
        for (int j = 0; j < 3; j++) {
            auto name = "Item" + std::to_string(i) + "_cls" + std::to_string(j);
            auto weight = generateRandomWeight();
            auto price = generateRandomPrice();
            auto classId = i + 1; // Class ID starts from 1

            items.push_back(std::make_unique<Item>(name, price, weight, classId));
        }
    }

        /*// Generate food
        for (int i = 0; i < 3; i++) {
            auto name = "Food" + std::to_string(i);
            auto weight = generateRandomWeight();
            auto price = generateRandomPrice();


            items.push_back(std::make_unique<Food>(name, price, weight));
        }

        // Generate gadgets
        for (int i = 0; i < 3; i++) {
            auto name = "Gadget" + std::to_string(i);
            auto weight = generateRandomWeight();
            auto price = generateRandomPrice();

            items.push_back(std::make_unique<Gadget>(name, price, weight));
        }

        // Generate drinks
        for (int i = 0; i < 3; i++) {
            auto name = "Drink" + std::to_string(i);
            auto weight = generateRandomWeight();
            auto price = generateRandomPrice();

            items.push_back(std::make_unique<Drink>(name, price, weight));
        }

        // Generate hygiene products
        for (int i = 0; i < 3; i++) {
            auto name = "Hygiene" + std::to_string(i);
            auto weight = generateRandomWeight();
            auto price = generateRandomPrice();

            items.push_back(std::make_unique<Hygiene>(name, price, weight));
        }

        // Generate clothes
        for (int i = 0; i < 3; i++) {
            auto name = "Clothing" + std::to_string(i);
            auto weight = generateRandomWeight();
            auto price = generateRandomPrice();

            items.push_back(std::make_unique<Clothes>(name, price, weight));
        }
    }*/
}

void Table::generateItems(int classAmount) {
    items.clear();

    for (int i = 0; i < classAmount/20; i++) {
        for (int j = 0; j < 3; j++) {
            auto name = "Item" + std::to_string(j) + "_cls" + std::to_string(i);
            auto weight = generateRandomWeight();
            auto price = generateRandomPrice();
            auto classId = i + 1; // Class ID starts from 1

            items.push_back(std::make_unique<Item>(name, price, weight, classId));
        }
    }
}

const std::vector<std::unique_ptr<Item>>& Table::getItems() const {
    return items;
}

void Table::displayItems() const {
    if (items.empty()) {
        std::cout << "Table is empty." << std::endl;
        return;
    }

    std::cout << "There are " << items.size() << " items:" << std::endl;
    for (size_t i = 0; i < items.size(); i++) {
        std::cout << i + 1 << ". " << items[i]->getName()
                 << "(weight: " << items[i]->getWeight()
                 << " kg, price: " << items[i]->getPrice() << " CZK" << std::endl;
    }
}
