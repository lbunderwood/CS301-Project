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

#include "../Items/Item.h"

class Inventory
{
public:

    Inventory();

    Inventory(std::vector<Item> items)
        : items_(items) {}

private:

    std::vector<Item> items_;

};

#endif // #ifndef INVENTORY_H