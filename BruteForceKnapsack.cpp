#include "BruteForceKnapsack.h"

BruteForceKnapsack::BruteForceKnapsack(double maxWeight) : maxWeight(maxWeight) {
}

bool BruteForceKnapsack::containsItemType(const std::vector<size_t>& combination, 
                                         const std::vector<std::unique_ptr<Item>>& items, 
                                         size_t newItemIndex)
{
    const std::type_info& newItemType = typeid(*items[newItemIndex]);
    
    for (size_t idx : combination) {
        if (typeid(*items[idx]) == newItemType) {
            return true;
        }
    }
    return false;
}

std::pair<double, double> BruteForceKnapsack::evaluateCombination(const std::vector<size_t>& combination, 
                                                                 const std::vector<std::unique_ptr<Item>>& items)
{
    double totalWeight = 0.0;
    double totalValue = 0.0;
    
    for (size_t idx : combination) {
        totalWeight += items[idx]->getWeight();
        totalValue += items[idx]->getPrice();
    }
    
    return {totalWeight, totalValue};
}

Bag BruteForceKnapsack::createBagFromCombination(const std::vector<size_t>& combination, 
                                               const std::vector<std::unique_ptr<Item>>& items,
                                               double maxWeight) {
    Bag resultBag(maxWeight);
    
    for (size_t idx : combination) {
        const Item& item = *items[idx];
        std::unique_ptr<Item> itemCopy;
        
        // Create appropriate item type based on the original item
        if (dynamic_cast<const Food*>(&item)) {
            itemCopy = std::make_unique<Food>(item.getName(), item.getPrice(), item.getWeight());
        } else if (dynamic_cast<const Drink*>(&item)) {
            itemCopy = std::make_unique<Drink>(item.getName(), item.getPrice(), item.getWeight());
        } else if (dynamic_cast<const Gadget*>(&item)) {
            itemCopy = std::make_unique<Gadget>(item.getName(), item.getPrice(), item.getWeight());
        } else if (dynamic_cast<const Clothes*>(&item)) {
            itemCopy = std::make_unique<Clothes>(item.getName(), item.getPrice(), item.getWeight());
        } else if (dynamic_cast<const Hygiene*>(&item)) {
            itemCopy = std::make_unique<Hygiene>(item.getName(), item.getPrice(), item.getWeight());
        } else {
            itemCopy = std::make_unique<Item>(item.getName(), item.getPrice(), item.getWeight());
        }
        
        resultBag.addItem(std::move(itemCopy));
    }
    
    return resultBag;
}

void BruteForceKnapsack::run() {
    // Generate items if we don't have custom ones
    if (itemTable.getItems().empty()) {
        itemTable.generateItems();
    }
    
    const std::vector<std::unique_ptr<Item>>& items = itemTable.getItems();
    std::cout << "Generated " << items.size() << " items for MCKP problem.\n\n";
    itemTable.displayItems();
    
    // Start measuring time
    auto startTime = std::chrono::high_resolution_clock::now();
    
    std::vector<size_t> bestCombination;
    double bestValue = 0.0;
    size_t totalCombinationsChecked = 0;
    
    // Map to track items by their types
    std::map<const std::type_info*, std::vector<size_t>> itemsByType;
    
    // Group items by their types
    for (size_t i = 0; i < items.size(); i++) {
        const std::type_info* type = &typeid(*items[i]);
        itemsByType[type].push_back(i);
    }
    
    // Vector of vectors where each inner vector contains indices of items of the same type
    std::vector<std::vector<size_t>> groupedItems;
    for (const auto& [type, indices] : itemsByType) {
        groupedItems.push_back(indices);
    }
    
    // Recursive lambda function for generating combinations
    std::function<void(std::vector<size_t>&, size_t, double, double)> generateCombinations;
    
    generateCombinations = [&](std::vector<size_t>& currentCombination, 
                              size_t currentGroupIndex, 
                              double currentWeight, 
                              double currentValue) {
        // Base case: we've processed all item types
        if (currentGroupIndex >= groupedItems.size()) {
            totalCombinationsChecked++;
            
            // Update the best combination if current one is better
            if (currentValue > bestValue) {
                bestValue = currentValue;
                bestCombination = currentCombination;
            }
            return;
        }
        
        // Try skipping this item type entirely
        generateCombinations(currentCombination, currentGroupIndex + 1, currentWeight, currentValue);
        
        // Try each item of the current type
        for (size_t itemIndex : groupedItems[currentGroupIndex]) {
            double itemWeight = items[itemIndex]->getWeight();
            
            // Check if adding this item would exceed the weight limit
            if (currentWeight + itemWeight <= maxWeight) {
                // Add item to combination
                currentCombination.push_back(itemIndex);
                
                // Recursively process next item type
                generateCombinations(
                    currentCombination, 
                    currentGroupIndex + 1, 
                    currentWeight + itemWeight, 
                    currentValue + items[itemIndex]->getPrice()
                );
                
                // Remove item for backtracking
                currentCombination.pop_back();
            }
        }
    };
    
    // Start the recursive combination generation
    std::vector<size_t> startCombination;
    generateCombinations(startCombination, 0, 0.0, 0.0);
    
    // Stop measuring time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    
    // Print results
    std::cout << "\n=== Brute Force MCKP Results ===\n";
    std::cout << "Execution time: " << duration.count() << " milliseconds\n";
    std::cout << "Total combinations checked: " << totalCombinationsChecked << "\n";
    
    if (!bestCombination.empty()) {
        double bestTotalWeight = 0.0;
        std::cout << "\nBest combination found:\n";
        for (size_t idx : bestCombination) {
            std::cout << "- " << items[idx]->getName() 
                     << " (Weight: " << items[idx]->getWeight() 
                     << " kg, Value: " << items[idx]->getPrice() << " CZK)\n";
            bestTotalWeight += items[idx]->getWeight();
        }
        
        std::cout << "\nTotal value: " << bestValue << " CZK\n";
        std::cout << "Total weight: " << bestTotalWeight << " kg\n";
        
        // Create and display the best bag
        Bag bestBag = createBagFromCombination(bestCombination, items, maxWeight);
        std::cout << "\nBest bag contents:\n";
        bestBag.displayContents();
    } else {
        std::cout << "No valid combination found.\n";
    }
}