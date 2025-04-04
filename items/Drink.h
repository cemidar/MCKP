
#ifndef DRINK_H
#define DRINK_H
#include "../Item.h"

class Drink : public Item
{
public:
    Drink(const std::string& name, double price, double weight)
        : Item(name, price, weight)
    {
    }
};

#endif //DRINK_H
