// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for Potion : Item class

#include "Potion.h"
#include "Effect.h"

#include <utility>
#include <vector>
#include <random>
#include <sstream>
#include <iomanip>

std::string Potion::to_string() const
{
    std::stringstream output;
    output << std::setw(20) << name_ << " "
           << std::setw(10) << potency_ << " "
           << std::setw(10) << effectString(effect_) << " "
           << std::setw(10) << value_;
    return output.str();
}

void Potion::createRandom()
{   
    // Different types of potions, int is the value multiplier
    std::vector<std::pair<std::string, int>> types = 
    {
        {"Potion of Healing", 5},
        {"Potion of Recover Stamina", 4},
        {"Potion of Regain Mana", 6},
        {"Potion of Increase Health", 3},
        {"Potion of Increase Stamina", 1},
        {"Potion of Increase Mana", 2},
        {"Splash Potion of Fire", 8},
        {"Splash Potion of Shock", 8},
        {"Splash Potion of Ice", 8},
        {"Potion of Fire Resistance", 5},
        {"Potion of Shock Resistance", 5},
        {"Potion of Ice Resistance", 5}
    };

    // mt random number generation setup
    std::random_device r; 
	std::mt19937 gen(r());
	std::uniform_int_distribution<> typeDist(1, 12);

    // generate value for type, potency, and Effect
    int type = typeDist(gen);
    int potency = typeDist(gen) * 2;
    Effect effect = (Effect)type;

    // assign potion to have the generated values
    name_ = types[type].first;
    potency_ = potency;
    value_ = types[type].second * potency;
    effect_ = effect;
    sellable_ = true;
}