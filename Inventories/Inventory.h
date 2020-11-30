// Luke Underwood
// Inventory.h
// 10/18/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file containing generic Inventory class

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <cstddef>

#include "../Items/Item.h"

class Inventory
{
public:

    Inventory() = default;

    Inventory(std::vector<Item*> items)
        : items_(items) {}

    std::string to_string() const;

    void push_back(Item* item);

    Item* operator[](std::size_t index);

    void restock(std::size_t count);

protected:

    std::vector<Item*> items_;

};

#endif // #ifndef INVENTORY_H