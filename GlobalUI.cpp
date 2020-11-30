// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for various global functions used in the UI

#include<string>
#include<iostream>
#include<sstream>

#include "GlobalUI.h"
#include "Inventories/Shop.h"
#include "Inventories/Player.h"

// THIS FUNCTION WRITTEN BY GLENN CHAPPELL - modified only slightly by Luke Underwood
// getInt
// Input an integer. On non-fatal error, print message and retry. On
// fatal error, return false. On successful input, set n to integer that
// was read and return true.
bool getInt(const std::string & prompt,  // Print this before doing input
            int& n)                // Number we input
{
    // Prompt & input chessboard size, with retry on bad input
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
    return getInt(std::string(prompt), *n);
}

void wait()
{
    std::cout << "Press ENTER to continue.";
    std::string line;
    std::getline(std::cin, line);
}

//
void printMenu()
{
    std::cout <<
        "\n----------------------------------------------------------"
        "\n|                  Welcome to The Shop!                  |"
        "\n----------------------------------------------------------\n\n"
        "\t1. View Inventory\n"
        "\t2. Shop - Sell Items\n"
        "\t3. Shop - Buy Items\n"
        "\t4. Loot a Chest\n\n"
        "\t0. Exit\n\n";
}

void printErrMsg()
{
    std::cout << "Invalid Input. Try Again.\n";
    wait();
}

void overflowErr()
{
    std::cout << "\nSomeone had insufficient funds.\n"
        "You may only buy things that you have the money for and sell things that the shop has money for.\n\n"
        "Alternatively, it is possible that you have reached the maximum number of shekels.\n"
        "If this is the case, congratulations!\n";
    wait();
}


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

void printInventory(Player* player)
{
    while(true)
    {
        player->printMenu();

        int itemNum = 0;
        if(!getInput(itemNum, "drop")) continue;

        if(itemNum == 0) break;

        player->removeItem(itemNum - 1);
    }
}

void buyMenu(Player* player, Shop* shop)
{
    shop->restock(15);

    while(true)
    {
        shop->printBuyMenu(*player);

        int itemNum = 0;
        if(!getInput(itemNum, "buy")) continue;

        if(itemNum == 0) break;

        shop->buyItem(itemNum - 1, *player);
    }
}

void sellMenu(Player* player, Shop* shop)
{
    while(true)
    {
        shop->printSellMenu(*player);

        int itemNum = 0;    
        if(!getInput(itemNum, "sell")) continue;

        if(itemNum == 0) break;

        shop->sellItem(itemNum - 1, *player);
    }
}