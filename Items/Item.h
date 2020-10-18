// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file containing generic Item class

#ifndef ITEM_H
#define ITEM_H

#include<string>

// generic item
// has a name, monetary value, and sellable restriction
// if sellable = false, it is a special/quest item that may not be sold
class Item
{
public:

    //Constructors
    Item() : Item("VOID", 0, true) {}

    Item(std::string name, int value, bool sellable) : 
        name_(name), value_(value), sellable_(sellable) {}

    std::string to_string();

protected:

    std::string name_;
    int value_;
    bool sellable_;
};

#endif // #ifndef ITEM_H