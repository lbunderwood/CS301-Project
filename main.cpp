// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file containing main function

#include <iostream>
#include <ostream>

#include "Items/Item.h"
#include "Items/Weapon.h"
#include "Items/Armor.h"
#include "Items/Potion.h"
#include "Inventories/Inventory.h"
#include "Inventories/Player.h"
#include "Inventories/Shop.h"
#include "AsmInclusions.h"

int main()
{
    Item i1("Small Dagger", 5, true);
    Item i2("Rope", 10, true);
    Item i3("Wolf Pelt", 7, true);

    std::vector<Item> items = {i1, i2, i3};

    Player player(items);

    Shop shop(items, 100);

    shop.buyItem(0, player);

    std::cout << player.to_string() << shop.to_string();

    return 0;
}