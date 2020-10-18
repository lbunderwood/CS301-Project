// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for item class

#include <iomanip>
#include <strstream>

#include "Item.h"

std::string Item::to_string() const
{
    std::stringstream value;
    value << std::setw(8) << value_;
    return name_ + value.str();
}