#include <iostream>
#include "Entite.h"

using namespace std;

Entite::Entite()
{
    vie = 100;
    vieMAX = 100;
    defense = 0;
    attaque = 10;
    taille = 0;
    positionX = 0;
    positionY = 0;
    cooldownAttaque=800;
    gettimeofday(&tp,NULL);
    dernierDeplacement=tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cooldownMax=1000;
    estVivant = true;
    chargeAttaque=false;
    orientation='h';

}

void Entite::PrendreDegats(int degatsSubis)
{
    degatsSubis=degatsSubis*(100-defense)/100;
    vie = vie - degatsSubis;
    cout << "degats subi : " << degatsSubis << endl;
    if(vie <= 0)
    {
        cout<< "mort\n";
        estVivant = false;
        vie = 0;
    }
}

bool Entite::getVivant()
{
    return estVivant;
}

void Entite::soin(const int pvRendus)
{
    cout << "pv rendu : " << pvRendus << endl;
    vie = vie + pvRendus;
    if(vie > vieMAX)
    {
        vie = vieMAX;
    }
}

int Entite::getVie() const
{
    return vie;
}

int Entite::getVieMAX() const
{
    return vieMAX;
}

int Entite::getPosX() const
{
    return positionX;
}

int Entite::getPosY() const
{
    return positionY;
}

void Entite::setVie(const int newVie)
{
    assert(newVie > 0);
    vie=newVie;
}

void Entite::setVieMAX(const int newVieMAX)
{
    assert(newVieMAX > 0);
    vieMAX=newVieMAX;
}

void Entite::setPosX(const int newX)
{
    assert(newX >=0 && newX < 481);
    positionX=newX;
}

void Entite::setPosY(const int newY)
{
    assert(newY >=0 && newY < 705);
    positionY=newY;
}

int Entite::getAttaque() const
{
    return attaque;
}

char Entite::getOrientation() const
{
    return orientation;
}

void Entite::setOrientation(const char newOri)
{
    assert(newOri != NULL);
    orientation=newOri;
}
void Entite::setAttaque(const int newAtt)
{
    assert(newAtt >= 0);
    attaque=newAtt;
}
void Entite::setCdAtt(const int newCd)
{
    assert(newCd >= 0);
    cooldownAttaque=newCd;
}
