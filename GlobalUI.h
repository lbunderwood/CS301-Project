// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file for various global functions for the UI

#ifndef GLOBALUI_H
#define GLOBALUI_H

#include<string>

#include "Inventories/Shop.h"
#include "Inventories/Player.h"
#include "Inventories/Lootable.h"

extern "C" 
{
    bool getInt(const std::string & prompt, int& n);

    bool getIntC(const char*, int* n);

    void printMenu();

    void printErrMsg();

    void printInventory(Player* player);

    void buyMenu(Player* player, Shop* shop);

    void sellMenu(Player* player, Shop* shop);

    void resetShop(Shop* shop);

    void lootMenu(Player* player, Lootable* lootable);

    void overflowErr();

}

#endif // #ifndef GLOBALUI_H