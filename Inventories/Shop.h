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

    // Default constructor
    // calls inventory def. con. and sets shekels to 500
    Shop() : Inventory(), shekels_(500) {}

    // 2-parameter constructor
    // takes vector of item pointers, and a number of shekels
    // calls inventory constructor with item vector
    Shop(std::vector<itemPtr> items, std::size_t shekels) 
        : Inventory(items), shekels_(shekels) {}

    // Shop::buyItem
    // takes item index and player object
    // transfers item at index to player
    void buyItem(std::size_t index, Player& player);

    // Shop::sellItem
    // takes item index and player object
    // transfers item at index to player
    void sellItem(std::size_t index, Player& player);

    // Shop::printBuyMenu
    // just prints the buy menu
    void printBuyMenu(Player& player);

    // Shop::printSellMenu
    // just prints the sell menu
    void printSellMenu(Player& player);

    // setsShekels
    // sets the ammount of money the shop has to buy from the player with
    void setShekels(std::size_t shekels);

private:

    // keeps track of the shekels the shop has
    std::size_t shekels_;

    // this is used in both buy and sell menus, so its here instead to keep things dry
    std::string banner =
        "\n--------------------------------------------------------------------------------------"
        "\n|                                Welcome to The Shop!                                |"
        "\n--------------------------------------------------------------------------------------\n\n";

};

#endif // #ifndef SHOP_H