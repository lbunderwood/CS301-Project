// Luke Underwood
// Inventory.cpp
// 10/18/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for generic Inventory class

#include "Inventory.h"

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
