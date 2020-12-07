// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file containing Effect enum class

#ifndef EFFECT_H
#define EFFECT_H

#include <string>

// Enum class to keep track of various item effects
enum class Effect
{
    NONE,               // 0
    REGAIN_HEALTH,
    REGAIN_STAMINA,
    RAGAIN_MANA,
    INCREASE_HEALTH,
    INCREASE_STAMINA,   // 5
    INCREASE_MANA,
    DEAL_FIRE,
    DEAL_SHOCK,
    DEAL_ICE,
    RESIST_FIRE,        // 10
    RESIST_SHOCK,
    RESIST_ICE,
};

// effectString
// see discription in Effect.cpp
std::string effectString(Effect effect);

#endif // #ifndef EFFECT_H