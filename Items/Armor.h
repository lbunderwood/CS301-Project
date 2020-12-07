// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file for Armor : Item class

#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include "Effect.h"

// Armor item
// has a name, monetary value, defense rating, and effect
// can have effects "INCREASE" "RESIST" "NONE" (0, 4-6, 10-12)
class Armor : public Item
{
public:

    // Default Constructor should not be used
    Armor() = delete;

    // 5-parameter constructor
    // initializes name_, value_, defense_, effect_, and sellable_
    Armor(const std::string& name, int value, int defense, Effect effect, bool sellable) 
        : Item(name, value, sellable), defense_(defense), effect_(effect) {}
    
    // Armor::to_string
    // returns a string of the armor's stats, for display in an inventory
    std::string to_string() const;

    // Armor::createRandom
    // makes this armor into a random new one, for creating random items in inventories
    void createRandom();

private:

    // keeps track of how much damage resistance is provided
    int defense_;

    // keeps track of effect applied
    Effect effect_;
};

#endif // #ifndef ARMOR_H