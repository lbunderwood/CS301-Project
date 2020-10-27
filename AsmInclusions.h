// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header to include assembly functions

#ifndef ASMINCLUSIONS_H
#define ASMINCLUSIONS_H

#include <cstddef>
#include "Inventories/Player.h"
#include "Inventories/Shop.h"

// Links to main.asm
extern "C" void mainMenu(Player*, void(Player::*)(), void(Shop::*)(Player&), void(Shop::*)(Player&));

// Links to functions.asm
extern "C" void moveMoney(std::size_t*, std::size_t*, int);

#endif // #include ASMFUNCTIONS_H