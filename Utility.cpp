// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file for various utility functions

#include<string>
#include<iostream>
#include<sstream>

#include "Utility.h"

// THIS FUNCTION WRITTEN BY GLENN CHAPPELL - modified only slightly by Luke Underwood
// getInt
// Input an integer. On non-fatal error, print message and retry. On
// fatal error, return false. On successful input, set n to integer that
// was read and return true.
bool getInt(const std::string & prompt,  // Print this before doing input
            int & n)                // Number we input
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