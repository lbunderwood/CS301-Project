// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header to include assembly functions

#ifndef ASMINCLUSIONS_H
#define ASMINCLUSIONS_H

#include <cstddef>
// For std::size_t

#include "Inventories/Player.h"
// For class Player
#include "Inventories/Shop.h"
// For class Shop
#include "Inventories/Lootable.h"
// For class Lootable

// Links to mainMenu.asm
extern "C" void mainMenu(Player*, Shop*, Lootable*);

// Links to functions.asm
extern "C" bool moveMoney(std::size_t*, std::size_t*, int);

#endif // #include ASMFUNCTIONS_H