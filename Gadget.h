
#ifndef GADGET_H
#define GADGET_H
#include "Item.h"

class Gadget : public Item
{
    public:
        Gadget(const std::string& name, double price, double weight)
            : Item(name, price, weight)
        {
        }
};

#endif //GADGET_H
