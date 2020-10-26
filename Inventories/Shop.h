// Luke Underwood
// Shop.h
// 10/18/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file containing Shop : Inventory class

#ifndef SHOP_H
#define SHOP_H

#include "Inventory.h"
#include "Player.h"
#include "../Items/Item.h"

#include<string>

class Shop : public Inventory
{
public:

    Shop(std::vector<Item> items, std::size_t shekels) 
        : Inventory(items), shekels_(shekels) {}

    void buyItem(std::size_t index, Player& player);

    void sellItem(std::size_t index, Player& player);

    void printBuyMenu(Player& player);

    void buyMenu(Player& player);

    void printSellMenu(Player& player);

    void sellMenu(Player& player);

private:

    std::size_t shekels_;

    std::string banner =
        "\n----------------------------------------------------------"
        "\n|                  Welcome to The Shop!                  |"
        "\n----------------------------------------------------------\n\n";

};

#endif // #ifndef SHOP_H