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
#include "../GlobalUI.h"

#include<string>
#include<iostream>

void Shop::buyItem(std::size_t index, Player& player)
{
    if(index >= items_.size())
    {
        printErrMsg();
        return;
    }

    if(!moveMoney(&player.getShekels(), &shekels_, items_[index]->getValue())) return;

    player.push_back(items_[index]);
    items_.erase(items_.begin() + index);
}

void Shop::sellItem(std::size_t index, Player& player)
{
    if(index >= player.items_.size())
    {
        printErrMsg();
        return;
    }

    if(!moveMoney(&shekels_, &player.getShekels(), player[index]->getValue())) return;
    
    auto item = player[index];
    push_back(item);
    player.removeItem(index);
}

void Shop::printBuyMenu(Player& player)
{
    std::cout << banner 
              << to_string() 
              << "\n\t\t\t\t\t\t\t\t     Your Shekels : " 
              << std::to_string(player.getShekels()) 
              << "\n\nWhat would you like to buy?\n";    
}

void Shop::printSellMenu(Player& player)
{
    std::cout << banner 
              << player.to_string() 
              << "\n\t\t\t\t\t\t\t\t     Shop Shekels : "
              << std::to_string(shekels_)
              << "\n\nWhat would you like to sell?\n";  
}

void Shop::setShekels(std::size_t shekels)
{
    shekels_ = shekels;
}