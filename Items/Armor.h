// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file for Armor class

#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include "Effect.h"

// Armor item
// has a name, monetary value, defense rating, and effect
// can have effects "INCREASE" "RESIST" "NONE" (4-6, 10-12)
class Armor
{
    std::string name_;
    int value_;
    int defense_;
    Effect effect_;
};

#endif // #ifndef ARMOR_H