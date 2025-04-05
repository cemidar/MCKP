#ifndef BRUTE_FORCE_KNAPSACK_H
#define BRUTE_FORCE_KNAPSACK_H

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <map>
#include <set>
#include <functional>


#include "Table.h"


class BruteForceKnapsack {
private:
    double maxWeight;
    Table itemTable;


public:
    BruteForceKnapsack(double maxWeight);
    void run(const Table& itemsProvided);

    void run();

};

#endif // BRUTE_FORCE_KNAPSACK_H