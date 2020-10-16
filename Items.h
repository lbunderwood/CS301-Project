// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file containing various P.O.D. structs for items

#include<string>

// Enum to keep track of various item effects
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

// weapon item
// has a name, monetary value, attack damage, and effect
// can have any effect
struct Weapon
{
    std::string name_;
    int value_;
    int attack_;
    Effect effect_;
};

// potion item
// has a name, monetary value, potency value, and effect
// can have any effect other than "NONE"
struct Potion
{
    std::string name_;
    int value_;
    int potency_;
    Effect effect_;
};

// potion item
// has a name, monetary value, defense rating, and effect
// can have effects "INCREASE" "RESIST" "NONE" (4-6, 10-12)
struct Armor
{
    std::string name_;
    int value_;
    int defense_;
    Effect effect_;
};

// generic item
// has a name, monetary value, and sellable restriction
// if sellable = false, it is a special/quest item that may not be sold
struct Item
{
    std::string name_;
    int value_;
    bool sellable;
};