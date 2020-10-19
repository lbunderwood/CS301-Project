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
    std::stringstream output;
    output << std::setw(20) << name_ 
           << std::setw(10) << value_;
    return output.str();
}

int Item::getValue() const
{
    return value_;
}