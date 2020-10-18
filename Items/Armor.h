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
// can have effects "INCREASE" "RESIST" "NONE" (4-6, 10-12)
class Armor : public Item
{
public:

private:
    int defense_;
    Effect effect_;
};

#endif // #ifndef ARMOR_H