#include <iostream>
#include "Personnage.h"
using namespace std;

Personnage::Personnage() : Entite()
{
    items=new Item[2];
    Item* arme = new Item('w',0);
    Item* armure = new Item('a',0);
    items[0]=*arme;//initialisation du loot
    items[1]=*armure;
    cooldownAttaque=100;
    inventairePotions= new int[3];
    inventairePotions[0]=0;
    inventairePotions[1]=0;
    inventairePotions[2]=0;
}
Personnage::~Personnage()
{
    delete [] items;
    delete [] inventairePotions;
}
void Personnage::utiliserPotion(const int potion)
{
    if(inventairePotions[potion]>0)
    {
        --inventairePotions[potion];
        soin((potion+1)*30);
    }
}
void Personnage::modifierStats(Item * newItem)
{
    int diftier=0;
    if(newItem->getTypeEquipement()=='w')
    {
        diftier=newItem->getTier()-items[0].getTier();
        if(diftier<1)
        {
            return;
        }
        attaque=attaque+diftier*10;
        items[0].setTier(newItem->getTier());
        cout<<"arme récupérée\n";
    }
    else
    {
        diftier=newItem->getTier()-items[1].getTier();
        if(diftier<1)
        {
            return;
        }
        vieMAX+=50*diftier;
        vie+=50*diftier;
        defense+=20*diftier;
        items[1].setTier(newItem->getTier());
        cout<<"armure récupérée\n";
    }
}
void Personnage::ramasserPotion(const int newPotion)
{
    inventairePotions[newPotion]++;
}
bool Personnage::peutAct()
{
    gettimeofday(&tp,NULL);
    if(tp.tv_sec * 1000 + tp.tv_usec / 1000-dernierDeplacement>=cooldownAttaque)
    {
        dernierDeplacement=tp.tv_sec * 1000 + tp.tv_usec / 1000;
        return true;
    }
    return false;
}
int* Personnage::getPotions() const
{
    return inventairePotions;
}

Item* Personnage::getItems() const
{
    return items;
}
