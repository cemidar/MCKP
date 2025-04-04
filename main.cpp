#include <iostream>

#include "Bag.h"
#include "Food.h"

int main()
{
    Bag myBag(30);

    myBag.addItem(std::make_unique<Food>("apple", 10, 1.5));
    myBag.addItem(std::make_unique<Food>("apple2", 10, 1.0));
    myBag.addItem(std::make_unique<Item>("tent", 10, 10.0));

    myBag.displayContents();

    return 0;
}

