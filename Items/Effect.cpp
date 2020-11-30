// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Source file containing helper function for Effect enum class

#include "Effect.h"

#include <string>

std::string effectString(Effect effect)
{
    if(effect == Effect::NONE)
    {
        return "";
    }
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

    return "";
}