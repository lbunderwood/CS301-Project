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
#include <memory>

#include "../Items/Item.h"

class Inventory
{
public:

    using itemPtr = std::shared_ptr<Item>;

    Inventory() = default;

    Inventory(std::vector<itemPtr> items)
        : items_(items) {}

    std::string to_string() const;

    void push_back(itemPtr& item);

    itemPtr operator[](std::size_t index);

    void restock(std::size_t count);

protected:

    std::vector<itemPtr> items_;

};

#endif // #ifndef INVENTORY_H