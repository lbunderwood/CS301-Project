// Luke Underwood
// 11/29/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file for Lootable : Inventory class

#ifndef LOOTABLE_H
#define LOOTABLE_H

#include "Inventory.h"
#include "Player.h"

// lootable inventory
// used for chests, bodies, etc where the player might be looting items
class Lootable : public Inventory
{
public:

    // Default constructor
    // no member variables, so we just call inventory's default constructor
    Lootable() : Inventory() {}

    // Lootable::takeItem
    // takes an item index and player object, then transfers the item at that
    // index to the player
    void takeItem(std::size_t index, Player& player);

    // Lootable::printLootMenu
    // it does what it says bro
    void printLootMenu();

private:
};

#endif // #ifndef LOOTABLE_H