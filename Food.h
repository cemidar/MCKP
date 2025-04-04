
#ifndef FOOD_H
#define FOOD_H
#include "Item.h"

class Food : public Item
{
public:
    Food(const std::string& name, double price, double weight)
        : Item(name, price, weight){}
};

#endif //FOOD_H
