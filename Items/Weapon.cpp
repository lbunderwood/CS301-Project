// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for Weapon : Item class

#include "Weapon.h"
#include "Effect.h"

#include <vector>
#include <random>
#include <tuple>
#include <sstream>
#include <iomanip>

std::string Weapon::to_string() const
{
    std::stringstream output;
    output << std::setw(30) << name_ << " "
           << std::setw(15) << attack_ << " "
           << std::setw(20) << effectString(effect_) << " "
           << std::setw(15) << value_;
    return output.str();
}

void Weapon::createRandom()
{   
    // Different types of weapons, first int is value, second is attack
    std::vector<std::tuple<std::string, int, int>> weaponTypes = 
    {
        {"Dagger", 5, 1},
        {"Axe", 10, 3},
        {"Shortsword", 15, 5},
        {"Mace", 10, 4},
        {"Greatsword", 30, 10},
        {"Battleaxe", 25, 9},
        {"Warhammer", 25, 8},
        {"Bow", 15, 5},
        {"Scimitar", 20, 6},
        {"Crossbow", 10, 4},
        {"Spear", 20, 7},
        {"Javeline", 10, 6},
        {"Throwing Knives", 10, 3}
    };

    // Different modifiers for weapons, first int is value, second is attack
    std::vector<std::tuple<std::string, int, int>> modifiers = 
    {
        {"Wooden ", 0, 0},
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

    // generate values for type, modifier, and Effect
    int type = typeDist(gen);
    int mod = modDist(gen);
    Effect effect = (Effect)typeDist(gen);

    // assign weapon to have the generated values
    name_ =  std::get<0>(modifiers[mod]) + std::get<0>(weaponTypes[type]);
    value_ = std::get<1>(weaponTypes[type]) + std::get<1>(modifiers[mod]) + 
            (effect == Effect::NONE ? 0 : 20);
    attack_ = std::get<2>(weaponTypes[type]) + std::get<2>(modifiers[mod]);
    effect_ = effect;
    sellable_ = true;
}