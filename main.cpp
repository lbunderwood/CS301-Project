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
#include "Items/Effect.h"
#include "Inventories/Inventory.h"
#include "Inventories/Player.h"
#include "Inventories/Shop.h"
#include "AsmInclusions.h"
#include "GlobalUI.h"

int main()
{

    Weapon dagger("Iron Dagger", 10, 3, Effect::NONE, true);
    Item rope("Rope", 10, true);
    Item clothes("Plain Clothes", 15, true);
    // initialize player inventory
    Player player;
    player.push_back((Item)dagger);
    player.push_back(rope);
    player.push_back(clothes);

    // default-construct shop, since items are added by buyMenu
    Shop shop;

    mainMenu(&player, &shop);

    return 0;
}