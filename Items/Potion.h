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

private:
    int potency_;
    Effect effect_;
};

#endif // #ifndef WEAPON_H