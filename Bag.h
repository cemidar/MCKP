
#ifndef BAG_H
#define BAG_H
#include <cassert>
#include <memory>
#include <vector>
#include <sstream>

#include "Item.h"

class Bag
{
private:
    double maxWeight;
    double currentWeight;
    double currentValue;
    std::vector<std::unique_ptr<Item>> items;

public:
    Bag(double maxWeight)
        : maxWeight(maxWeight), currentWeight(0), currentValue(0) {}

    double getMaxWeight() const { return maxWeight; }
    double getCurrentWeight() const { return currentWeight; }
    double getCurrentValue() const { return currentValue; }

    bool containsItemOfSameType(const Item& itemToCheck) const {
        const std::type_info& itemType = typeid(itemToCheck);

        for (const auto& item : items) {
            if (typeid(*item) == itemType) {
                return true;
            }
        }
        return false;
    }

    bool addItem(std::unique_ptr<Item> item)
    {
        if (currentWeight + item->getWeight() >= maxWeight) return false;

        // Store refference
        const Item& itemRef = *item;

        if (containsItemOfSameType(itemRef)) {
            std::cout << "Item of the same type already exists in the bag." << std::endl;
            assert(!"Item of the same type already exists in the bag.");
        }

        // Add item
        items.push_back(std::move(item));
        currentWeight += itemRef.getWeight();
        currentValue += itemRef.getPrice();
        return true;
    }


    /* BAG CONTENT PRINTING */
    friend std::ostream& operator<<(std::ostream& os, const Bag& bag) {
        os << bag.toString();
        return os;
    }
    std::string toString() const {
        std::ostringstream oss;

        if (items.empty()) {
            oss << "Bag is empty.";
            return oss.str();
        }

        oss << "=== Bag contents ===" << std::endl;
        oss << "Amount of items: " << items.size() << std::endl;
        oss << "Current weight: " << getCurrentWeight() << " kg / "
            << maxWeight << " kg" << std::endl;
        oss << "Total value: " << getCurrentValue() << " CZK" << std::endl;
        oss << std::endl;

        oss << "Items list:" << std::endl;
        for (const auto& item : items) {
            oss << "- " << item->getName() << "("
            <<item->getWeight() << " kg, "
            << item->getPrice() << " CZK)" << std::endl;
        }
        oss << "===================";

        return oss.str();
    }
    void displayContents() const {
        std::cout << toString() << std::endl;
    }

};

#endif //BAG_H
