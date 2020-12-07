// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for Potion : Item class

#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "Effect.h"

// potion item
// has a name, monetary value, potency value, and effect
// can have any effect other than "NONE"
class Potion : public Item
{
public:

    // default constructor should not be used
    Potion() = delete;

    // 5-parameter constructor
    // initializes name_, value_, potency_, effect_, and sellable_
    Potion(const std::string& name, int value, int potency, Effect effect, bool sellable)
        : Item(name, value, sellable), potency_(potency), effect_(effect) {}

    // Potion::to_string
    // returns a string of the potion's stats, for display in an inventory
    std::string to_string() const;

    // Potion::createRandom
    // makes this potion into a random new one, for creating random items in inventories
    void createRandom();

private:

    // keeps track of how much of the effect the potion applies
    int potency_;

    // keeps track of what kind of potion it is
    Effect effect_;
};

#endif // #ifndef WEAPON_H