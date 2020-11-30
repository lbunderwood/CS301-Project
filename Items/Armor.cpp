// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for Armor : Item class

#include "Armor.h"

#include <vector>
#include <tuple>
#include <random>
#include <strstream>
#include <iomanip>

std::string Armor::to_string() const
{
    std::stringstream output;
    output << std::setw(20) << name_ << " "
           << std::setw(10) << defense_ << " "
           << std::setw(10) << effectString(effect_) << " "
           << std::setw(10) << value_;
    return output.str();
}

void Armor::createRandom()
{
    // Different types of armor, first int is value, second is defense
    std::vector<std::tuple<std::string, int, int>> armorTypes = 
    {
        {"Boots", 5, 2},
        {"Gauntlets", 5, 2},
        {"Breastplate", 10, 4},
        {"Helmet", 5, 3},
        {"Plate Boots", 20, 10},
        {"Plate Gauntlets", 20, 10},
        {"Plate Chestpiece", 30, 20},
        {"Plate Helmet", 20, 15},
        {"Chain Mail Shirt", 20, 15},
        {"Chain Mail Hood", 10, 10},
        {"Chain Mail Pants", 10, 10},
        {"Greaves", 7, 5},
        {"Shield", 20, 30}
    };

    // Different modifiers for armor, first int is value, second is defense
    std::vector<std::tuple<std::string, int, int>> modifiers = 
    {
        {"Leather ", 1, 0},
        {"Iron ", 5, 2},
        {"Steel ", 10, 4},
        {"Elven ", 15, 6},
        {"Dwarven ", 15, 6},
        {"Orcish ", 15, 6},
        {"Silver ", 30, 3},
        {"Mithril ", 30, 15},
        {"Adamantium ", 35, 20},
        {"Eldritch ", 50, 30}
    };

    // mt random number generation setup
    std::random_device r; 
	std::mt19937 gen(r());
	std::uniform_int_distribution<> typeDist(0, 12);
	std::uniform_int_distribution<> modDist(0, 9);
	std::uniform_int_distribution<> effectDist(0, 6);

    // generate values for type, modifier, and Effect
    int type = typeDist(gen);
    int mod = modDist(gen);
    int effectNum = effectDist(gen);

    // make sure the effect applied is one that is applicable to armor
    if(effectNum > 0)
    {
        effectNum += 3;
        if(effectNum > 6)
        {
            effectNum += 3;
        }
    }
    
    // assign armor to have the generated values
    name_ = std::get<0>(armorTypes[type]) + std::get<0>(modifiers[mod]);
    value_ = std::get<1>(armorTypes[type]) + std::get<1>(modifiers[mod]) + 
            (effectNum == 0 ? 0 : 20);
    defense_ = std::get<2>(armorTypes[type]) + std::get<2>(modifiers[mod]);
    effect_ = (Effect)effectNum;
    sellable_ = true;
}