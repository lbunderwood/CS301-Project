// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for item class

#include <iomanip>
#include <sstream>
#include <vector>
#include <random>

#include "Item.h"

std::string Item::to_string() const
{
    std::stringstream output;
    output << std::setw(30) << name_ << " "
           << std::setw(15) << "" << " "
           << std::setw(20) << "" << " "
           << std::setw(15) << value_;
    return output.str();
}

int Item::getValue() const
{
    return value_;
}

bool Item::isSellable()
{
    return sellable_;
}

void Item::createRandom()
{
    std::vector<Item> items = 
    {
        Item("Rope", 10, true),
        Item("Bread", 4, true),
        Item("Iron Ingot", 5, true),
        Item("Steel Ingot", 10, true),
        Item("Gold Ingot", 20, true),
        Item("Silver Ingot", 15, true),
        Item("Ale", 6, true),
        Item("Wine", 12, true),
        Item("Mead", 6, true),
        Item("Wolf Hide", 8, true),
        Item("Monster Guts", 20, true),
        Item("Bear Hide", 10, true),
        Item("Monster Horn", 15, true),
        Item("Rabbit Hide", 4, true),
        Item("Monster Claws", 10, true),
        Item("Diamond", 75, true),
        Item("Ruby", 65, true),
        Item("Emerald", 65, true),
        Item("Garnet", 30, true),
        Item("Amethyst", 50, true),
        Item("Milk", 3, true),
        Item("Cooked Steak", 7, true),
        Item("Hearty Stew", 13, true),
        Item("Torch", 10, true),
        Item("Leather Strips", 12, true),
        Item("Cookbook", 15, true),
        Item("Spell Tome", 100, true),
        Item("Book of Fairytales", 12, true),
        Item("The Adventures of Hrognar", 15, true),
        Item("Bag of Potion Ingredients", 80, true),
        Item("Traveller's Cloak", 25, true),
        Item("Simple Tunic", 20, true),
        Item("Fancy Clothes", 50, true),
        Item("Hat", 8, true),
        Item("Gloves", 6, true),
        Item("Jeweled Necklace", 60, true),
        Item("Silver Ring", 35, true),
        Item("Gold Ring", 40, true),
    };

    std::random_device r;
	std::mt19937 gen(r());
	std::uniform_int_distribution<> dist(0, 37);

    *this = items[dist(gen)];
}