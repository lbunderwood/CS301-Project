// Luke Underwood
// Inventory.cpp
// 10/18/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for generic Inventory class

#include "Inventory.h"
#include "../Items/Item.h"
#include "../Items/Armor.h"
#include "../Items/Potion.h"
#include "../Items/Weapon.h"
#include "../Items/Effect.h"

#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

std::string Inventory::to_string() const
{
    std::stringstream output;
    output << "                             name:       strength:              effect:          value:\n\n";

    for(std::size_t i = 0; i < items_.size(); ++i)
    {
        output << std::setw(3) << std::to_string(i + 1) << items_[i]->to_string() << "\n";
    }

    return output.str();
}

void Inventory::push_back(Item* item)
{
    items_.push_back(item);
}

Item* Inventory::operator[](std::size_t index)
{
    return items_[index];
}

void Inventory::restock(std::size_t count)
{
    // clear our old inventory
    for(auto m : items_)
    {
        delete m;
    }
    items_.clear();
    
    // add some regular items
    for(std::size_t i = 0; i < std::floor((double)count/2.0); ++i)
    {
        Item* item = new Item("VOID", 0, true);
        item->createRandom();
        push_back(item);
    }

    // add some weapons
    for(std::size_t i = 0; i < std::ceil((double)count/6); ++i)
    {
        Item* item = new Weapon("VOID", 0, 0, Effect::NONE, true);
        item->createRandom();
        push_back(item);
    }
    
    // add some armor
    for(std::size_t i = 0; i < std::ceil((double)count/6); ++i)
    {
        Item* item = new Armor("VOID", 0, 0, Effect::NONE, true);
        item->createRandom();
        push_back(item);
    }
    
    // add some potions
    for(std::size_t i = 0; i < std::ceil((double)count/6); ++i)
    {
        Item* item = new Potion("VOID", 0, 0, Effect::NONE, true);
        item->createRandom();
        push_back(item);
    }
}