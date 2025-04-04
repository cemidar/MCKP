#ifndef BRUTE_FORCE_KNAPSACK_H
#define BRUTE_FORCE_KNAPSACK_H

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <map>
#include <set>
#include <functional>

#include "Bag.h"
#include "Table.h"
#include "items/Food.h"
#include "items/Drink.h"
#include "items/Gadget.h"
#include "items/Clothes.h"
#include "items/Hygiene.h"

class BruteForceKnapsack {
private:
    double maxWeight;
    Table itemTable;
    
    // Helper function to check if an item type already exists in the current combination
    bool containsItemType(const std::vector<size_t>& combination, 
                        const std::vector<std::unique_ptr<Item>>& items, 
                        size_t newItemIndex);
    
    // Helper function to evaluate a combination's total weight and value
    std::pair<double, double> evaluateCombination(const std::vector<size_t>& combination, 
                                                const std::vector<std::unique_ptr<Item>>& items);
    
    // Helper function to create a Bag from a combination
    Bag createBagFromCombination(const std::vector<size_t>& combination, 
                                const std::vector<std::unique_ptr<Item>>& items,
                                double maxWeight);
    
public:
    BruteForceKnapsack(double maxWeight = 100.0);
    
    // Main function to run the brute force algorithm
    void run();

};

#endif // BRUTE_FORCE_KNAPSACK_H