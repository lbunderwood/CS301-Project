// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file for Weapon : Item class

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Effect.h"

// weapon item
// has a name, monetary value, attack damage, and effect
// can have any effect
class Weapon : public Item 
{
public:

    // Default Constructor should never be used
    Weapon() = delete;

    // 5-Parameter constructor
    // initializes name_, value_, attack_, effect_, and sellable_
    Weapon(const std::string& name, int value, int attack, Effect effect, bool sellable)
        : Item(name, value, sellable), attack_(attack), effect_(effect) {}

    // Weapon::to_string
    // returns a string of the weapon's stats, for display in an inventory
    std::string to_string() const;

    // Weapon::createRandom
    // makes this weapon into a random new one, for creating random items in inventories
    void createRandom();

private:

    // keeps track of how much damage this weapon deals
    int attack_;

    // keeps track of the effect this weapon applies
    Effect effect_;
};

#endif // #ifndef WEAPON_H