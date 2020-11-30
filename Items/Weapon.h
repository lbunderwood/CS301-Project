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

    // Default Constructor
    Weapon() = delete;

    Weapon(const std::string& name, int value, int attack, Effect effect, bool sellable)
        : Item(name, value, sellable), attack_(attack), effect_(effect) {}

    std::string to_string() const;

    void createRandom();

private:

    int attack_;
    Effect effect_;
};

#endif // #ifndef WEAPON_H