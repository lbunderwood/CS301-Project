// Luke Underwood
// 11/29/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for Lootable : Inventory class

#include "Lootable.h"
#include "Player.h"
#include "../GlobalUI.h"

#include <iostream>

// Lootable::takeItem
// takes an item index and player object, then transfers the item at that
// index to the player
void Lootable::takeItem(std::size_t index, Player& player)
{
    // check that the index is good
    if(index >= items_.size())
    {
        printErrMsg();
        return;
    }

    // transfer the item
    player.push_back(items_[index]);
    items_.erase(items_.begin() + index);
}

// Lootable::printLootMenu
// it does what it says bro
void Lootable::printLootMenu()
{
    // like... it just prints the loot menu
    std::cout << 
    "\n--------------------------------------------------------------------------------------"
    "\n|                                    Wooden Chest                                    |"
    "\n--------------------------------------------------------------------------------------\n\n"
    << Inventory::to_string() << std::endl;
}