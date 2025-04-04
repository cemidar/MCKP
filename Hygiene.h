
#ifndef HYGINE_H
#define HYGINE_H
#include "Item.h"

class Hygiene : public Item
{
public:
    Hygiene(const std::string& name, double price, double weight)
        : Item(name, price, weight)
    {
    }
};

#endif //HYGINE_H
