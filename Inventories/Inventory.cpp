// Luke Underwood
// Inventory.cpp
// 10/18/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for generic Inventory class

#include "Inventory.h"

#include <string>

std::string Inventory::to_string() const
{
    std::string output = "                 name:   atk/def:    effect:     value:\n\n";

    for(std::size_t i = 0; i < items_.size(); ++i)
    {
        output += std::to_string(i + 1) + items_[i].to_string() + "\n";
    }

    return output;
}

void Inventory::push_back(Item item)
{
    items_.push_back(item);
}

void Inventory::pop_back()
{
    items_.pop_back();
}

Item Inventory::operator[](std::size_t index)
{
    return items_[index];
}
