// Luke Underwood
// 10/16/2020
// CS301
// CS301 - Project
// InventoryAndShop
// Header file containing Effect enum class

#ifndef EFFECT_H
#define EFFECT_H

// Enum class to keep track of various item effects
enum class Effect
{
    NONE,               // 0
    REGAIN_HEALTH,
    REGAIN_STAMINA,
    RAGAIN_MANA,
    INCREASE_HEALTH,
    INCREASE_STAMINA,   // 5
    INCREASE_MANA,
    DEAL_FIRE,
    DEAL_SHOCK,
    DEAL_ICE,
    RESIST_FIRE,        // 10
    RESIST_SHOCK,
    RESIST_ICE,
};

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
}

#endif // #ifndef EFFECT_H