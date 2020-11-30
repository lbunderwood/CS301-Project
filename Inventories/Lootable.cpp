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


void Lootable::takeItem(std::size_t index, Player& player)
{
    if(index >= items_.size())
    {
        printErrMsg();
        return;
    }

    player.push_back(items_[index]);
    items_.erase(items_.begin() + index);
}

void Lootable::printLootMenu()
{
    std::cout << 
    "\n--------------------------------------------------------------------------------------"
    "\n|                                    Wooden Chest                                    |"
    "\n--------------------------------------------------------------------------------------\n\n"
    << Inventory::to_string() << std::endl;
}
