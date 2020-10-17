// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file for Weapon class

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Effect.h"

// weapon item
// has a name, monetary value, attack damage, and effect
// can have any effect
class Weapon
{
public:

    // Default Constructor
    Weapon();

    std::string name_;
    int value_;
    int attack_;
    Effect effect_;
};

#endif // #ifndef WEAPON_H