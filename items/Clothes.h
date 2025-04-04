
#ifndef CLOTHES_H
#define CLOTHES_H
#include "../Item.h"

class Clothes : public Item
{
public:
    Clothes(const std::string& name, double price, double weight)
        : Item(name, price, weight)
    {
    }
};

#endif //CLOTHES_H
