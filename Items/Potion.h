#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "Effect.h"

// potion item
// has a name, monetary value, potency value, and effect
// can have any effect other than "NONE"
class Potion
{
    std::string name_;
    int value_;
    int potency_;
    Effect effect_;
};

#endif // #ifndef WEAPON_H