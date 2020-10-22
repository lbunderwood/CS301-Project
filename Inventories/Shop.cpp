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

void Shop::printBuyMenu(Player& player)
{
    std::cout << banner 
              << Inventory::to_string() 
              << "\n\t\t\t\t\t     Shekels : " 
              << std::to_string(player.getShekels()) 
              << "\nWhat would you like to buy?\n";    
}

void Shop::buyMenu(Player& player)
{
    while(true)
    {
        printBuyMenu(player);

        int itemNum = 0;    
        if(!getInt("Enter the number beside the item you would like to buy, or a 0 to exit.", itemNum)
            || itemNum < 0)
        {
            std::cout << "Fatal input error. Trying again.";
            continue;
        }

        if(itemNum == 0) break;
        
        buyItem(itemNum - 1, player);
    }

}

void Shop::printSellMenu(Player& player)
{
    std::cout << banner 
              << player.Inventory::to_string() 
              << "\n\t\t\t\t\tShop Shekels : "
              << std::to_string(shekels_)
              << "\nWhat would you like to sell?\n";  
}

void Shop::sellMenu(Player& player)
{
    while(true)
    {
        printSellMenu(player);

        int itemNum = 0;    
        if(!getInt("Enter the number beside the item you would like to sell, or a 0 to exit.", itemNum)
            || itemNum < 0)
        {
            std::cout << "Fatal input error. Trying again.";
            continue;
        }

        if(itemNum == 0) break;

        sellItem(itemNum - 1, player);
    }
}