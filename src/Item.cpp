#include "Item.h"
#include <cassert>
Item::Item()
{
    typeEquipement='w';
    tier=0;
}

Item::Item(const char type, const int newTier)
{
    assert(newTier >= 0 && newTier <=3);
    typeEquipement=type;
    tier=newTier;
}
Item::~Item()
{

}
Item::Item(Item * itemCp)
{
    tier=itemCp->getTier();
    typeEquipement=itemCp->getTypeEquipement();
}
void Item::setTypeEquipement(const char equipement)
{
    typeEquipement = equipement;
}

void Item::setTier(const int t)
{
    assert(t >= 0 && t <=3);
    tier = t;
}

char Item::getTypeEquipement() const
{
    return typeEquipement;
}

int Item::getTier() const
{
    return tier;
}
