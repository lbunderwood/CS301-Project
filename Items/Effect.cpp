// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file containing helper function for Effect enum class

#include "Effect.h"

#include <string>

// effectString
// takes an Effect, returns a string relating to the effect
std::string effectString(Effect effect)
{
    // return an empty string if there is no effect
    if(effect == Effect::NONE)
    {
        return "";
    }
    // return a string that tells the user what the item does
    else if(effect == Effect::REGAIN_HEALTH)
    {
        return "Healing";
    }
    else if(effect == Effect::REGAIN_STAMINA)
    {
        return "Regain Stamina";
    }
    else if(effect == Effect::RAGAIN_MANA)
    {
        return "Regain Mana";
    }
    else if(effect == Effect::INCREASE_HEALTH)
    {
        return "Increase Health";
    }
    else if(effect == Effect::INCREASE_STAMINA)
    {
        return "Increase Stamina";
    }
    else if(effect == Effect::INCREASE_MANA)
    {
        return "Increase Mana";
    }
    else if(effect == Effect::DEAL_FIRE)
    {
        return "Deal Fire";
    }
    else if(effect == Effect::DEAL_SHOCK)
    {
        return "Deal Shock";
    }
    else if(effect == Effect::DEAL_ICE)
    {
        return "Deal Ice";
    }
    else if(effect == Effect::RESIST_FIRE)
    {
        return "Resist Fire";
    }
    else if(effect == Effect::RESIST_SHOCK)
    {
        return "Resist Shock";
    }
    else if(effect == Effect::RESIST_ICE)
    {
        return "Resist Ice";
    }

    // if we got here, something is broken and we want to just act like there's no effect
    return "";
}