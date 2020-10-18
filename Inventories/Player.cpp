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
    std::string output = "";
    
    for(std::size_t i = 0; i < items_.size(); ++i)
    {
        output += items_[i].to_string() + "\n";
    }

    output += "\nShekels : " + std::to_string(shekels_);

    return output;
}

std::ostream operator<<(std::ostream& os, const Player& player)
{
    os << player.to_string();
    return os;
}