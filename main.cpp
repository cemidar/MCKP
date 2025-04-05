#include <iostream>
#include "BruteForceKnapsack.h"
#include "PureBruteForce.h"

int main() {

    int amountOfClasses = 9;

    Table itemTable;
    itemTable.generateItems(amountOfClasses*20);

    BruteForceKnapsack bruteForce(amountOfClasses*20);
    bruteForce.run(itemTable);

    PureBruteForce pureBruteForce(amountOfClasses*20);
    pureBruteForce.run(itemTable);

    return 0;
}