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

    
public:
    BruteForceKnapsack(double maxWeight);

    void run();

};

#endif // BRUTE_FORCE_KNAPSACK_H