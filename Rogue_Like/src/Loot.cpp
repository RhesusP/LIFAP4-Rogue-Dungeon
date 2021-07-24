#include "Loot.h"
Loot::Loot()
{
    drop=new Item();
    positionx=0;
    positiony=0;
}

Loot::Loot(Item * itemLoot,int posX,int posY)
{
    drop=itemLoot;
    positionx=posX;
    positiony=posY;
}
Loot::~Loot()
{
    delete drop;
}
void Loot::setDrop(Item* item)
{
    drop = item;
}

void Loot::setPosX(const int x)
{
    positionx = x;
}

void Loot::setPosY(const int y)
{
    positiony = y;
}

Item* Loot::getDrop() const
{
    return drop;
}

int Loot::getPosX() const
{
    return positionx;
}

int Loot::getPosY() const
{
    return positiony;
}
