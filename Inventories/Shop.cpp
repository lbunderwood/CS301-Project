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


// Shop::buyItem
// takes item index and player object
// transfers item at index to player
void Shop::buyItem(std::size_t index, Player& player)
{
    // check that the index is valid, inform the user if not
    if(index >= items_.size())
    {
        printErrMsg();
        return;
    }

    // move the money around via assembly
    if(!moveMoney(&player.getShekels(), &shekels_, items_[index]->getValue())) return;

    // transfer item from shop to player
    player.push_back(items_[index]);
    items_.erase(items_.begin() + index);
}

// Shop::sellItem
// takes item index and player object
// takes item at index from player
void Shop::sellItem(std::size_t index, Player& player)
{
    // check that the index exists
    if(index >= player.items_.size())
    {
        printErrMsg();
        return;
    }

    // transfer money via assembly
    if(!moveMoney(&shekels_, &player.getShekels(), player[index]->getValue())) return;
    
    // move the item from the player to the shop
    auto item = player[index];
    push_back(item);
    player.removeItem(index);
}

// Shop::printBuyMenu
// just prints the buy menu
void Shop::printBuyMenu(Player& player)
{
    std::cout << banner 
              << to_string() 
              << "\n\t\t\t\t\t\t\t\t     Your Shekels : " 
              << std::to_string(player.getShekels()) 
              << "\n\nWhat would you like to buy?\n";    
}

// Shop::printSellMenu
// just prints the sell menu
void Shop::printSellMenu(Player& player)
{
    std::cout << banner 
              << player.to_string() 
              << "\n\t\t\t\t\t\t\t\t     Shop Shekels : "
              << std::to_string(shekels_)
              << "\n\nWhat would you like to sell?\n";  
}

// setsShekels
// sets the ammount of money the shop has to buy from the player with
void Shop::setShekels(std::size_t shekels)
{
    shekels_ = shekels;
}