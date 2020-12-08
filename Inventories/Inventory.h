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

// inventory class
// pure virtual class used to share behavior between inventory types
class Inventory
{
public:

    // itemPtr will be used to refer to items
    // shared_ptr was selected because raw pointers are *the worst* and 
    // I couldn't get unique_ptr to work for some reason
    using itemPtr = std::shared_ptr<Item>;

    // default constructor is written by compiler
    Inventory() = default;

    // 1-parameter constructor
    // takes inventory vector and puts those items in the inventory
    Inventory(const std::vector<itemPtr>& items)
        : items_(items) {}

    // Inventory::to_string
    // returns a string to represent the inventory in a menu
    std::string to_string() const;

    // Inventory::push_back
    // adds an item to the end of the list
    void push_back(itemPtr& item);

    // Inventory::operator[]
    // allows access to the item at the given index
    itemPtr operator[](std::size_t index);

    // Inventory::restock
    // takes a size_t that indicates the number of random items to restock the inventory with
    // These items will be 1/2 regular items, 1/6 potions, 1/6 weapons, 1/6 armor
    // the number of items inserted may be greater than the number requested if it is not a
    // multiple of 6
    void restock(std::size_t count);

protected:

    // items_ keeps track of all the items in the inventory
    std::vector<itemPtr> items_;

};

#endif // #ifndef INVENTORY_H