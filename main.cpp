#include <iostream>

#include "Bag.h"
#include "Table.h"
#include "items/Food.h"

int main()
{
    Bag myBag(5*20);
    Table myTable;
    myTable.generateItems();
    myTable.displayItems();

    myBag.addItem(std::make_unique<Food>("apple", 10, 1.5));
    myBag.addItem(std::make_unique<Food>("apple2", 10, 1.0));
    myBag.addItem(std::make_unique<Item>("tent", 10, 10.0));

    myBag.displayContents();

    return 0;
}

