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
    // initialize player inventory
    Inventory::itemPtr dagger = std::make_shared<Weapon>("Iron Dagger", 10, 3, Effect::NONE, true);
    Inventory::itemPtr rope = std::make_shared<Item>("Rope", 10, true);
    Inventory::itemPtr clothes = std::make_shared<Item>("Plain Clothes", 15, true);
    Player player;
    player.push_back(dagger);
    player.push_back(rope);
    player.push_back(clothes);

    // default-construct shop, then randomly insert some items
    Shop shop;
    shop.restock(15);

    // default construct lootable, it is stocked automatically later
    Lootable chest;

    mainMenu(&player, &shop, &chest);

    return 0;
}