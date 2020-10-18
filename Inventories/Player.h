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

class Player : public Inventory
{
public:

    Player(std::vector<Item> items) : Inventory(items) {};

    std::string to_string() const;

private:

    std::size_t shekels_;

};

std::ostream operator<<(std::ostream os, Player player);

#endif // #ifndef PLAYER_H