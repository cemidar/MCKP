#include "PureBruteForce.h"

#include <bitset>
#include <chrono>
#include <set>

#include "Table.h"

PureBruteForce::PureBruteForce(double max_weight) : maxWeight(max_weight)
{

}

void PureBruteForce::run(const Table& itemsProvided) {

    const std::vector<std::unique_ptr<Item>>& items = itemsProvided.getItems();
    std::cout << "Generated " << items.size() << " items for MCKP problem.\n\n";
    itemsProvided.displayItems();

    // Start measuring time
    auto startTime = std::chrono::high_resolution_clock::now();

    // Total number of possible combinations: 2^n where n is the number of items
    const size_t totalItems = items.size();
    const size_t totalCombinations = 1ULL << totalItems; // 2^totalItems

    std::vector<size_t> bestCombination;
    double bestValue = 0.0;
    size_t validCombinationsChecked = 0;

    // Try every possible combination
    for (size_t i = 0; i < totalCombinations; i++) {
        // Convert number to binary representation where each bit represents
        // whether an item is included (1) or not (0)
        std::bitset<64> combination(i);

        // Check if the current combination is valid
        double totalWeight = 0.0;
        double totalValue = 0.0;
        bool isValid = true;

        // To track class IDs already included in this combination
        std::set<int> includedClasses;

        // Check each item
        std::vector<size_t> currentCombination;
        for (size_t j = 0; j < totalItems && j < 64; j++) {
            if (combination[j]) {
                // This item is included in the current combination
                int itemClassId = items[j]->getClassId();

                // Check if we already have an item of this class
                if (includedClasses.find(itemClassId) != includedClasses.end()) {
                    isValid = false;
                    break;
                }

                // Check weight constraint
                totalWeight += items[j]->getWeight();
                if (totalWeight > maxWeight) {
                    isValid = false;
                    break;
                }

                // Add class ID to included classes
                includedClasses.insert(itemClassId);

                // Calculate value
                totalValue += items[j]->getPrice();

                // Add to current combination
                currentCombination.push_back(j);
            }
        }

        // Update the best combination if current one is valid and better
        if (isValid) {
            validCombinationsChecked++;

            if (totalValue > bestValue) {
                bestValue = totalValue;
                bestCombination = currentCombination;
            }
        }
    }

    // Stop measuring time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print results
    std::cout << "\n=== Pure Brute Force MCKP Results ===\n";
    std::cout << "Execution time: " << duration.count() << " milliseconds\n";
    std::cout << "Total combinations checked: " << totalCombinations << "\n";
    std::cout << "Valid combinations checked: " << validCombinationsChecked << "\n";

    if (!bestCombination.empty()) {
        double bestTotalWeight = 0.0;
        std::cout << "\nBest combination found:\n";
        for (size_t idx : bestCombination) {
            std::cout << "- " << items[idx]->getName()
                     << " (Weight: " << items[idx]->getWeight()
                     << " kg, Value: " << items[idx]->getPrice()
                     << " CZK, Class: " << items[idx]->getClassId() << ")\n";
            bestTotalWeight += items[idx]->getWeight();
        }

        std::cout << "\nTotal value: " << bestValue << " CZK\n";
        std::cout << "Total weight: " << bestTotalWeight << " kg\n";


    } else {
        std::cout << "No valid combination found.\n";
    }
}

void PureBruteForce::run() {
    if (itemTable.getItems().empty()) {
        itemTable.generateItems(maxWeight);
    }

    const std::vector<std::unique_ptr<Item>>& items = itemTable.getItems();
    std::cout << "Generated " << items.size() << " items for MCKP problem.\n\n";
    itemTable.displayItems();

    // Start measuring time
    auto startTime = std::chrono::high_resolution_clock::now();

    // Total number of possible combinations: 2^n where n is the number of items
    const size_t totalItems = items.size();
    const size_t totalCombinations = 1ULL << totalItems; // 2^totalItems

    std::vector<size_t> bestCombination;
    double bestValue = 0.0;
    size_t validCombinationsChecked = 0;

    // Try every possible combination
    for (size_t i = 0; i < totalCombinations; i++) {
        // Convert number to binary representation where each bit represents
        // whether an item is included (1) or not (0)
        std::bitset<64> combination(i);

        // Check if the current combination is valid
        double totalWeight = 0.0;
        double totalValue = 0.0;
        bool isValid = true;

        // To track class IDs already included in this combination
        std::set<int> includedClasses;

        // Check each item
        std::vector<size_t> currentCombination;
        for (size_t j = 0; j < totalItems && j < 64; j++) {
            if (combination[j]) {
                // This item is included in the current combination
                int itemClassId = items[j]->getClassId();

                // Check if we already have an item of this class
                if (includedClasses.find(itemClassId) != includedClasses.end()) {
                    isValid = false;
                    break;
                }

                // Check weight constraint
                totalWeight += items[j]->getWeight();
                if (totalWeight > maxWeight) {
                    isValid = false;
                    break;
                }

                // Add class ID to included classes
                includedClasses.insert(itemClassId);

                // Calculate value
                totalValue += items[j]->getPrice();

                // Add to current combination
                currentCombination.push_back(j);
            }
        }

        // Update the best combination if current one is valid and better
        if (isValid) {
            validCombinationsChecked++;

            if (totalValue > bestValue) {
                bestValue = totalValue;
                bestCombination = currentCombination;
            }
        }
    }

    // Stop measuring time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Print results
    std::cout << "\n=== Pure Brute Force MCKP Results ===\n";
    std::cout << "Execution time: " << duration.count() << " milliseconds\n";
    std::cout << "Total combinations checked: " << totalCombinations << "\n";
    std::cout << "Valid combinations checked: " << validCombinationsChecked << "\n";

    if (!bestCombination.empty()) {
        double bestTotalWeight = 0.0;
        std::cout << "\nBest combination found:\n";
        for (size_t idx : bestCombination) {
            std::cout << "- " << items[idx]->getName()
                     << " (Weight: " << items[idx]->getWeight()
                     << " kg, Value: " << items[idx]->getPrice()
                     << " CZK, Class: " << items[idx]->getClassId() << ")\n";
            bestTotalWeight += items[idx]->getWeight();
        }

        std::cout << "\nTotal value: " << bestValue << " CZK\n";
        std::cout << "Total weight: " << bestTotalWeight << " kg\n";


    } else {
        std::cout << "No valid combination found.\n";
    }
}