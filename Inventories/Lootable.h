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

class Lootable : public Inventory
{
public:

    Lootable() : Inventory() {}

    void takeItem(std::size_t index, Player& player);

    void printLootMenu();

private:

};

#endif // #ifndef LOOTABLE_H