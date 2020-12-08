// Luke Underwood
// Player.cpp
// 10/18/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for Player : Inventory class

#include "Player.h"
#include "../GlobalUI.h"
#include <iostream>
#include <string>
#include <ostream>

// Player::printMenu
// prints the player inventory
void Player::printMenu()
{
    std::cout << 
        "\n--------------------------------------------------------------------------------------"
        "\n|                                  Player Inventory                                  |"
        "\n--------------------------------------------------------------------------------------\n\n"
        << Inventory::to_string()
        << "\n\t\t\t\t\t\t\t\t     Your Shekels : " << std::to_string(shekels_) << "\n\n";
}

// Player::getShekels
// returns the number of shekels the player has
// returns by reference so that buy and sell menus can pass a pointer to assembly
std::size_t& Player::getShekels()
{
    return shekels_;
}

// Player::removeItem
// takes an item index, drops the item at that index from the player's inventory
void Player::removeItem(std::size_t index)
{
    if(index >= items_.size()) 
    {
        printErrMsg();
        return;
    }

    items_.erase(items_.begin() + index);
}