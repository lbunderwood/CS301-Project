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
    Item() = delete;

    // 3-parameter constructor
    // initializes name_, value_, and sellable_
    Item(std::string name, int value, bool sellable) : 
        name_(name), value_(value), sellable_(sellable) {}

    // Item::to_string
    // returns a string of the item's stats, for display in an inventory
    // virtual so that other types of items can override
    virtual std::string to_string() const;

    // Item::getValue
    // returns the monetary value of the item
    int getValue() const;

    // Item::isSellable
    // returns whether or not this item may be sold
    bool isSellable();

    // Item::createRandom
    // makes this item into a random new one, for creating random items in inventories
    // virtual so that other types of items can override
    virtual void createRandom();

protected:

    // keeps track of the item's name
    std::string name_;

    // keeps track of the item's monetary value
    int value_;

    // keeps track of whether the item is sellable
    // this should only be false for special/quest items
    bool sellable_;
};

#endif // #ifndef ITEM_H