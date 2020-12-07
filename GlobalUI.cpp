// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for various global functions used in the UI

#include<string>
// For std::string, std::getline
#include<iostream>
// For std::cin, std::cout
#include<sstream>
// For std::istringstream

#include "GlobalUI.h"
#include "Inventories/Shop.h"
#include "Inventories/Player.h"

// wait - LOCAL TO THIS FILE
// waits for the user to press enter, useful for pausing to make sure the user
// sees a message before continuing with the program
void wait()
{
    // print message
    std::cout << "Press ENTER to continue.";

    // wait
    std::string line;
    std::getline(std::cin, line);
}

// getInput - LOCAL TO THIS FILE
// used to give a common prompt to getInt and print error message
bool getInput(int& itemNum, std::string action)
{
    if(!getInt("Enter the number beside the item you would like to " + action + ", or a 0 to exit:", itemNum)
        || itemNum < 0)
    {
        std::cout << "Fatal input error. Trying again.\n";
        return false;
    }
    return true;
}

// THIS FUNCTION WRITTEN BY GLENN CHAPPELL - modified only slightly by Luke Underwood
// getInt
// Input an integer. On non-fatal error, print message and retry. On
// fatal error, return false. On successful input, set n to integer that
// was read and return true.
bool getInt(const std::string & prompt,  // Print this before doing input
            int& n)                // Number we input
{
    // Prompt & input integer, with retry on bad input
    while (true)
    {
        bool founderror = false;
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        if (!std::cin)
        {
            if (std::cin.eof())      // End of file
                return false;   // Fatal error
            std::cin.clear();
            std::cin.ignore();
            founderror = true;  // Bad input; retry
        }
        else
        {
            std::istringstream is(line);
            is >> n;
            if (!is)
                founderror = true;  // Bad read from string; retry
        }

        if (!founderror)
            break;
        std::cout << std::endl;
        std::cout << "Try again; please type an integer" << std::endl;
    }

    return true;  // Successful input
}

// getIntC
// Input an integer pointer. On non-fatal error, print message and retry. On
// fatal error, return false. On successful input, set n to integer that
// was read and return true.
bool getIntC(const char* prompt,  // Print this before doing input
            int* n)                // Number we input
{
    // just construct a string, and dereference int*, pass to getInt
    return getInt(std::string(prompt), *n);
}

// printMenu
// prints the main actions menu
void printMenu()
{
    std::cout <<
        "\n----------------------------------------------------------"
        "\n|                      Actions Menu                      |"
        "\n----------------------------------------------------------\n\n"
        "\t1. View Inventory\n"
        "\t2. Shop - Sell Items\n"
        "\t3. Shop - Buy Items\n"
        "\t4. Shop - Reset\n"
        "\t5. Loot a Chest\n\n"
        "\t0. Exit\n\n";
}

// printErrMsg
// lets the user know that something went wrong, and waits for them to acknowledge
void printErrMsg()
{
    std::cout << "Invalid Input. Try Again.\n";
    wait();
}

// overflowErr
// prints a message to let the user know that overflow occured, then waits
// this should only be called from assembly, when overflow checking has been done
void overflowErr()
{
    std::cout << "\nSomeone had insufficient funds.\n"
        "You may only buy things that you have the money for and sell things that the shop has money for.\n\n"
        "Alternatively, it is possible that you have reached the maximum number of shekels.\n"
        "If this is the case, congratulations!\n";
    wait();
}

// printInventory
// takes a pointer to player object
// prints the player's inventory and handles any dropping of items
void printInventory(Player* player)
{
    // loop until user inputs 0 and break is called
    while(true)
    {
        // print the menu
        player->printMenu();

        // get input
        int itemNum = 0;
        if(!getInput(itemNum, "drop")) continue;

        // see if its time to leave
        if(itemNum == 0) break;

        // drop item
        player->removeItem(itemNum - 1);
    }
}

// buyMenu
// takes pointers to player and shop objects
// prints the buy menu and handles any buying of items
void buyMenu(Player* player, Shop* shop)
{
    // keep looping until itemNum == 0 and break is called
    while(true)
    {
        // print the buy menu
        shop->printBuyMenu(*player);

        // get input
        int itemNum = 0;
        if(!getInput(itemNum, "buy")) continue;

        // see if its time to leave
        if(itemNum == 0) break;

        // buy an item
        shop->buyItem(itemNum - 1, *player);
    }
}

// sellMenu
// takes pointers to player and shop objects
// prints the sell menu and handles any selling of items
void sellMenu(Player* player, Shop* shop)
{
    // keep looping until itemNum == 0 and break is called
    while(true)
    {
        // print the sell menu
        shop->printSellMenu(*player);

        // get input
        int itemNum = 0;    
        if(!getInput(itemNum, "sell")) continue;

        // see if its time to leave
        if(itemNum == 0) break;

        // sell an item
        shop->sellItem(itemNum - 1, *player);
    }
}

// resetShop
// resets the shop's inventory and money, then informs the user and waits
void resetShop(Shop* shop)
{
    shop->restock(15);
    shop->setShekels(500);

    std::cout << "\nThe Shop had been restocked!\n";
    wait();
}

// lootMenu
// takes pointers to player and lootable objects
// stocks the lootable with loot, then prints the menu and handles looting
void lootMenu(Player* player, Lootable* lootable)
{
    // put 6 items in the chest
    lootable->restock(6);

    // keep looping until the user inputs 0
    while(true)
    {
        // show off the goods
        lootable->printLootMenu();

        // get input
        int itemNum = 0;    
        if(!getInput(itemNum, "take")) continue;

        // check if its time to leave
        if(itemNum == 0) break;

        // transfer item to player
        lootable->takeItem(itemNum - 1, *player);
    }
}