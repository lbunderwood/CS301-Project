// Luke Underwood
// Shop.cpp
// 10/18/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for Shop : Inventory class

#include "Shop.h"
#include "Player.h"
#include "../Items/Item.h"
#include "../AsmInclusions.h"

#include<string>

std::string Shop::to_string() const
{
    std::string output = 
    "\n----------------------------------------------------"
    "\n-               Welcome to The Shop!               -"
    "\n----------------------------------------------------\n\n";
    
    for(std::size_t i = 0; i < items_.size(); ++i)
    {
        output += items_[i].to_string() + "\n";
    }

    output += "\n\t\t\t\tShop Shekels : " + std::to_string(shekels_) + "\n";

    return output;
}

void Shop::buyItem(std::size_t index, Player& player)
{
    moveMoney(&player.getShekels(), &shekels_, items_[index].getValue());

    player.push_back(items_[index]);
    items_.erase(items_.begin() + index);
}

void Shop::sellItem(std::size_t index, Player& player)
{
    moveMoney(&shekels_, &player.getShekels(), items_[index].getValue());

    push_back(player[index]);
    player.removeItem(index);
}