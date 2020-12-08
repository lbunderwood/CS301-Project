// Luke Underwood
// Player.h
// 10/18/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file containing Player : Inventory class

#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<ostream>

#include "Inventory.h"
#include "../Items/Item.h"

// player class
// handles the player's inventory and shekels
class Player : public Inventory
{
public:

    // default constructor
    // initializes shekels_ to 10
    Player() : shekels_(10) {}

    // 1-parameter constructor
    // takes a vector of items, passes it to inventory constructor
    // initializes shekels to 10
    Player(std::vector<itemPtr> items) : Inventory(items), shekels_(10) {}

    // Player::printMenu
    // prints the player inventory
    void printMenu();

    // Player::getShekels
    // returns the number of shekels the player has
    // returns by reference so that buy and sell menus can pass a pointer to assembly
    std::size_t& getShekels();

    // Player::removeItem
    // takes an item index, drops the item at that index from the player's inventory
    void removeItem(std::size_t index);

    // make shop a friend so it can manipulate things directly
    friend class Shop;

private:

    // keeps track of how many shekels the player has
    std::size_t shekels_;

};

#endif // #ifndef PLAYER_H