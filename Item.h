
#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {
private:
    std::string name;
    double price;
    double weight;

public:
    Item(const std::string& name, double price, double weight)
        : name(name), price(price), weight(weight) {}


    virtual ~Item() = default;

    // Gettery
    std::string getName() const { return name; }
    double getWeight() const { return weight; }
    double getPrice() const { return price; }

};



#endif //ITEM_H
