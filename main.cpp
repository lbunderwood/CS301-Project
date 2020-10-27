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

    // initialize shop inventory
    // This will later be replaced with a randomly-stocked shop
    Shop shop(std::vector<Item>
        {
            Item("Milk", 3, true),
            Item("Cooked Steak", 7, true),
            Item("Arrows X5", 20, true),
            Item("Traveller's Cloak", 30, true),
            Item("Torch", 10, true),
            Item("Leather Strips", 12, true),
            Item("Steel Shortsword", 40, true)
        }, 100);

    main(&player, Player::printInventory, Shop::buyMenu(player), Shop::sellMenu(player));

    /*
    // Variables for use inside loop
    int menuChoice = 0;
    bool keepGoing = true;
    std::string errMsg = "Invalid Input. Try Again.";

    // Main Program Loop
    while(keepGoing)
    {

        // Get input
        if(!getInt("Enter the number next to your desired choice:", menuChoice))
        {
            std::cout << errMsg;
            continue;
        }

        // Use the input
        switch(menuChoice)
        {
        case 1:
            std::cout << player.to_string();
            break;
        case 2:
            shop.sellMenu(player);
            break;
        case 3:
            shop.buyMenu(player);
            break;
        case 0:
            keepGoing = false;
            break;
        default:
            std::cout << errMsg;
            break;
        };
    }
    */
    return 0;
}