#include <iostream>
#include "Ennemi.h"

using namespace std;

Ennemi::Ennemi() : Entite()
{
    isBoss = false;
    nom = '_';
    cdDeplacement=800;
    holdPotion=0;
    holdItem=false;
    loot=NULL;
    surLoot='v';
}
Ennemi::~Ennemi()
{
    if(loot!=NULL)
    {
        delete loot;
    }
}
bool Ennemi::deplacerEnnemi()
{
    gettimeofday(&tp,NULL);
    if(tp.tv_sec * 1000 + tp.tv_usec / 1000-dernierDeplacement>=cooldownAttaque)
    {
        dernierDeplacement=tp.tv_sec * 1000 + tp.tv_usec / 1000;
        return true;
    }
    return false;
}

void Ennemi::setItem(Item * newItem)
{
    loot=newItem;
}
void Ennemi::setPotionHold(const int potion)
{
    holdPotion=potion;
}
void Ennemi::setItemHold (const bool newItemHold)
{
    holdItem=newItemHold;
}
int Ennemi::getPotionHold() const
{
    return holdPotion;
}
bool Ennemi::getItemHold() const
{
    return holdItem;
}
void Ennemi::setCdDeplacement(const float newCd)
{
    cdDeplacement=newCd;
}
Item * Ennemi::getItem() const
{
    return loot;
}
char Ennemi::getSurLoot() const
{
    return surLoot;
}
void Ennemi::setSurLoot(const char newLoot)
{
    surLoot=newLoot;
}
