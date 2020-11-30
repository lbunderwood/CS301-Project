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
#include "GlobalUI.h"

int main()
{
    // initialize player inventory
    Player player(std::vector<Item>
        {
            Item("Iron Dagger", 5, true), 
            Item("Rope", 10, true), 
            Item("Plain Clothes", 15, true)
        });

    // default-construct shop, since items are added by buyMenu
    Shop shop;

    mainMenu(&player, &shop);

    return 0;
}