#include <iostream>
#include "BruteForceKnapsack.h"
#include "PureBruteForce.h"

int main() {

    BruteForceKnapsack bruteForce(5*20);

    bruteForce.run();

    runPureBruteForce();

    return 0;
}