// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file for various global functions for the UI

#ifndef GLOBALUI_H
#define GLOBALUI_H

#include<string>
// For std::string

#include "Inventories/Shop.h"
#include "Inventories/Player.h"
#include "Inventories/Lootable.h"

// make these functions available from assembly
extern "C" 
{
    // THIS FUNCTION WRITTEN BY GLENN CHAPPELL - modified only slightly by Luke Underwood
    // getInt
    // Input an integer. On non-fatal error, print message and retry. On
    // fatal error, return false. On successful input, set n to integer that
    bool getInt(const std::string & prompt, int& n);

    // getIntC
    // Input an integer pointer. On non-fatal error, print message and retry. On
    // fatal error, return false. On successful input, set n to integer that
    // was read and return true.
    bool getIntC(const char*, int* n);

    // printMenu
    // prints the main actions menu
    void printMenu();

    // printErrMsg
    // lets the user know that something went wrong, and waits for them to acknowledge
    void printErrMsg();

    // printInventory
    // takes a pointer to player object
    // prints the player's inventory and handles any dropping of items
    void printInventory(Player* player);

    // buyMenu
    // takes pointers to player and shop objects
    // prints the buy menu and handles any buying of items
    void buyMenu(Player* player, Shop* shop);

    // sellMenu
    // takes pointers to player and shop objects
    // prints the sell menu and handles any selling of items
    void sellMenu(Player* player, Shop* shop);

    // resetShop
    // resets the shop's inventory and money, then informs the user and waits
    void resetShop(Shop* shop);

    // lootMenu
    // takes pointers to player and lootable objects
    // stocks the lootable with loot, then prints the menu and handles looting
    void lootMenu(Player* player, Lootable* lootable);

    // overflowErr
    // prints a message to let the user know that overflow occured, then waits
    // this should only be called from assembly, when overflow checking has been done
    void overflowErr();

}

#endif // #ifndef GLOBALUI_H