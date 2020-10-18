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

    Inventory(std::vector<Item> items)
        : items_(items) {}

    void push_back(Item item);

    void pop_back();

    Item& operator[](std::size_t index);

    const Item operator[](std::size_t index) const;

private:

    std::vector<Item> items_;

};

#endif // #ifndef INVENTORY_H