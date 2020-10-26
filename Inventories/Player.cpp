// Luke Underwood
// Player.cpp
// 10/18/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for Player : Inventory class

#include "Player.h"
#include <string>
#include <ostream>

std::string Player::to_string() const
{
    std::string output = 
    "\n----------------------------------------------------------"
    "\n|                    Player Inventory                    |"
    "\n----------------------------------------------------------\n\n";
    
    output += Inventory::to_string();
    output += "\n\t\t\t\t\t     Shekels : " + std::to_string(shekels_) + "\n";

    return output;
}

std::size_t& Player::getShekels()
{
    return shekels_;
}

void Player::removeItem(std::size_t index)
{
    items_.erase(items_.begin() + index);
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << player.to_string();
    return os;
}