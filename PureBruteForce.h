#ifndef PURE_BRUTE_FORCE_H
#define PURE_BRUTE_FORCE_H

#include <memory>
#include <chrono>
#include <set>
#include <bitset>

#include "Table.h"

class PureBruteForce
{
private:
        double maxWeight; // Maximum weight for the bag
        Table itemTable;  // Table of items

public:
        PureBruteForce(double max_weight);
        void run(const Table& itemsProvided);

        void run();




};


#endif // PURE_BRUTE_FORCE_H