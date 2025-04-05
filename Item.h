
#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {
private:
    std::string name;
    double price;
    double weight;
    int classId;

public:
    Item(const std::string& name, double price, double weight, int class_id)
        : name(name),
          price(price),
          weight(weight),
          classId(class_id)
    {
    }

    virtual ~Item() = default;

    // Gettery
    std::string getName() const { return name; }
    double getWeight() const { return weight; }
    double getPrice() const { return price; }
    int getClassId() const { return classId; }

};



#endif //ITEM_H
