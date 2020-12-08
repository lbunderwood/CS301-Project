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

// Inventory::to_string
// returns a string to represent the inventory in a menu
std::string Inventory::to_string() const
{
    // create stringstream
    std::stringstream output;
    // nice labels for columns of item statistics
    output << "                             name:       strength:              effect:          value:\n\n";

    // put all of the items in there with numeric labels
    for(std::size_t i = 0; i < items_.size(); ++i)
    {
        output << std::setw(3) << std::to_string(i + 1) << items_[i]->to_string() << "\n";
    }

    // return the constructed string
    return output.str();
}

// Inventory::push_back
// adds an item to the end of the list
void Inventory::push_back(itemPtr& item)
{
    items_.push_back(item);
}

// Inventory::operator[]
// allows access to the item at the given index
Inventory::itemPtr Inventory::operator[](std::size_t index)
{
    return items_[index];
}

// Inventory::restock
// takes a size_t that indicates the number of random items to restock the inventory with
// These items will be 1/2 regular items, 1/6 potions, 1/6 weapons, 1/6 armor
// the number of items inserted may be greater than the number requested if it is not a
// multiple of 6
void Inventory::restock(std::size_t count)
{
    items_.clear();
    
    // add some regular items
    for(std::size_t i = 0; i < std::floor((double)count/2.0); ++i)
    {
        itemPtr item = std::make_shared<Item>("VOID", 0, true);
        item->createRandom();
        push_back(item);
    }

    // add some weapons
    for(std::size_t i = 0; i < std::ceil((double)count/6); ++i)
    {
        itemPtr item = std::make_shared<Weapon>("VOID", 0, 0, Effect::NONE, true);
        item->createRandom();
        push_back(item);
    }
    
    // add some armor
    for(std::size_t i = 0; i < std::ceil((double)count/6); ++i)
    {
        itemPtr item = std::make_shared<Armor>("VOID", 0, 0, Effect::NONE, true);
        item->createRandom();
        push_back(item);
    }
    
    // add some potions
    for(std::size_t i = 0; i < std::ceil((double)count/6); ++i)
    {
        itemPtr item = std::make_shared<Potion>("VOID", 0, 0, Effect::NONE, true);
        item->createRandom();
        push_back(item);
    }
}