#include "Terrain.h"


Terrain::Terrain()
{
    niveau = 0;
    hauteur = 21;
    largeur = 15;
    nbEnnemis = 0;
    ennemisVivants=0;
    nbItems=0;
}
Terrain::~Terrain()
{
    delete[] monstres;
    delete[] tab;
    delete[] loots;
}
Terrain::Terrain(Personnage * jeuHeros, const int jeuNiveau)
{
    assert(jeuNiveau>=0&&jeuNiveau<=50);
    heros=jeuHeros;
    niveau = jeuNiveau;
    hauteur = 21;
    hauteur = 21;
    largeur = 15;
    nbEnnemis = 0;
    nbItems=0;
}

void Terrain::deplacement(const int newOri)
{
    assert(newOri==113||newOri==100||newOri==115||newOri==122);
    int hePosX=heros->getPosX();
    int hePosY=heros->getPosY();
    int curChar=hePosX+hePosY*largeur;
    if(newOri==113) /// q : 113   s : 115  d : 100   z : 122
    {
        cout << "Vous avez appuye sur la touche q, deplacement a gauche \n";
        if(tab[curChar-1]=='v')
        {
            tab[curChar-1]='P';
            tab[curChar]='v';
            heros->setPosX(hePosX-1); /// aller a gauche
        }
        else if(tab[curChar-1]=='r')
        {
            tab[curChar-1]='P';
            tab[curChar]='v';
            heros->setPosX(hePosX-1);
            heros->PrendreDegats(12+(int)((float)(niveau)*0.7));
        }
        else if (tab[curChar-1]=='a'||tab[curChar-1]=='w')
        {
            tab[curChar-1]='P';
            tab[curChar]='v';
            for(int i=0;i<nbItems;++i)
            {
                if(loots[i].getPosX()==hePosX-1&&loots[i].getPosY()==hePosY)
                {
                    heros->modifierStats(loots[i].getDrop());
                }
            }
            heros->setPosX(hePosX-1);
        }
        else if (tab[curChar-1]=='s'||tab[curChar-1]=='m'||tab[curChar-1]=='l')
        {
            heros->setPosX(hePosX-1);
            switch(tab[curChar-1])
            {
                case 's':
                    heros->ramasserPotion(0);
                    break;
                case 'm':
                    heros->ramasserPotion(1);
                    break;
                case 'l':
                    heros->ramasserPotion(2);
                    break;
                default:
                    break;
            }
            tab[curChar-1]='P';
            tab[curChar]='v';
        }
        heros->setOrientation('g');
    }
    else if(newOri==100)
    {
        cout << "Vous avez appuye sur la touche d, deplacement a droite \n";
        if(tab[curChar+1]=='v')
        {
            tab[curChar+1]='P';
            tab[curChar]='v';
            heros->setPosX(hePosX+1);
        } /// aller a droite
        else if(tab[curChar+1]=='r')
        {
            tab[curChar+1]='P';
            tab[curChar]='v';
            heros->setPosX(hePosX+1);
            heros->PrendreDegats(12+(int)((float)(niveau)*0.7));
        }
        else if (tab[curChar+1]=='a'||tab[curChar+1]=='w')
        {
            tab[curChar+1]='P';
            tab[curChar]='v';
            for(int i=0;i<nbItems;++i)
            {
                if(loots[i].getPosX()==hePosX+1&&loots[i].getPosY()==hePosY)
                {
                    heros->modifierStats(loots[i].getDrop());
                }
            }
            heros->setPosX(hePosX+1);
        }
        else if (tab[curChar+1]=='s'||tab[curChar+1]=='m'||tab[curChar+1]=='l')
        {
            heros->setPosX(hePosX+1);
            switch(tab[curChar+1])
            {
                case 's':
                    heros->ramasserPotion(0);
                    break;
                case 'm':
                    heros->ramasserPotion(1);
                    break;
                case 'l':
                    heros->ramasserPotion(2);
                    break;
                default:
                    break;
            }
            tab[curChar+1]='P';
            tab[curChar]='v';
        }
        heros->setOrientation('d');
    }
    else if(newOri==115)
    {
        cout << "Vous avez appuye sur la touche s, deplacement en bas \n";
        if(tab[curChar+largeur]=='v')
        {
            tab[curChar+largeur]='P';
            tab[curChar]='v';
            heros->setPosY(hePosY+1); /// aller en bas
        }
        else if(tab[curChar+largeur]=='r')
        {
            tab[curChar+largeur]='P';
            tab[curChar]='v';
            heros->setPosY(hePosY+1);
            heros->PrendreDegats(12+(int)((float)(niveau)*0.7));
        }
        else if (tab[curChar+largeur]=='a'||tab[curChar+largeur]=='w')
        {
            tab[curChar+largeur]='P';
            tab[curChar]='v';
            for(int i=0;i<nbItems;++i)
            {
                if(loots[i].getPosX()==hePosX&&loots[i].getPosY()==hePosY+1)
                {
                    heros->modifierStats(loots[i].getDrop());
                }
            }
            heros->setPosY(hePosY+1);
        }
        else if (tab[curChar+largeur]=='s'||tab[curChar+largeur]=='m'||tab[curChar+largeur]=='l')
        {
            heros->setPosY(hePosY+1);
            switch(tab[curChar+largeur])
            {
                case 's':
                    heros->ramasserPotion(0);
                    break;
                case 'm':
                    heros->ramasserPotion(1);
                    break;
                case 'l':
                    heros->ramasserPotion(2);
                    break;
                default:
                    break;
            }
            tab[curChar+largeur]='P';
            tab[curChar]='v';
        }
        heros->setOrientation('b');
    }
    else if(newOri==122)
    {
        cout << "Vous avez appuye sur la touche z, deplacement en haut \n";
        if(tab[curChar-largeur]=='v'||tab[curChar-largeur]=='S')//on gère le cas de la porte de sortie
        {
            tab[curChar-largeur]='P';
            tab[curChar]='v';
            heros->setPosY(hePosY-1);
        }/// aller en haut
        else if(tab[curChar-largeur]=='r')
        {
            tab[curChar-largeur]='P';
            tab[curChar]='v';
            heros->setPosY(hePosY-1);
            heros->PrendreDegats(12+(int)((float)(niveau)*0.7));
        }
        else if (tab[curChar-largeur]=='a'||tab[curChar-largeur]=='w')
        {
            tab[curChar-largeur]='P';
            tab[curChar]='v';
            for(int i=0;i<nbItems;++i)
            {
                if(loots[i].getPosX()==hePosX&&loots[i].getPosY()==hePosY-1)
                {
                    heros->modifierStats(loots[i].getDrop());
                }
            }
            heros->setPosY(hePosY-1);
        }
        else if (tab[curChar-largeur]=='s'||tab[curChar-largeur]=='m'||tab[curChar-largeur]=='l')
        {
            heros->setPosY(hePosY-1);
            switch(tab[curChar-largeur])
            {
                case 's':
                    heros->ramasserPotion(0);
                    break;
                case 'm':
                    heros->ramasserPotion(1);
                    break;
                case 'l':
                    heros->ramasserPotion(2);
                    break;
                default:
                    break;
            }
            tab[curChar-largeur]='P';
            tab[curChar]='v';
        }
        heros->setOrientation('h');
    }
}


void Terrain::attaquePersonnage(Personnage* attaquant)
{
    assert(attaquant!=NULL);
    int i=0;
    bool ennemiTrouve=false;
    char ori=attaquant->getOrientation();
    int attX=attaquant->getPosX();
    int attY=attaquant->getPosY();
    switch(ori)
    {
        case 'h':
            attY--;
            break;
        case 'b':
            attY++;
            break;
        case 'g':
            attX--;
            break;
        case 'd':
            attX++;
            break;
        default:
            cout<<"orientation non valide\n";
    }
    if (attX>=0&&attX<largeur&&attY>=0&&attY<hauteur)
    {
        if(tab[attY*largeur+attX]=='E')
        {
            while(i<nbEnnemis&&!ennemiTrouve)
            {
                if(monstres[i].getPosX()==attX)
                {
                    if(monstres[i].getPosY()==attY)
                    {
                        ennemiTrouve=true;
                        monstres[i].PrendreDegats(attaquant->getAttaque());
                        if(!monstres[i].getVivant())
                        {
                            if(monstres[i].getSurLoot()!='v')
                            {
                                tab[attY*largeur+attX]=monstres[i].getSurLoot();
                                replacerItem(&monstres[i]);
                            }
                            if(monstres[i].getItemHold())
                            {
                                loots[nbItems].getDrop()->setTier(monstres[i].getItem()->getTier());
                                loots[nbItems].getDrop()->setTypeEquipement(monstres[i].getItem()->getTypeEquipement());
                                loots[nbItems].setPosX(monstres[i].getPosX());
                                loots[nbItems].setPosY(monstres[i].getPosY());
                                nbItems++;
                                tab[monstres[i].getPosY()*largeur+monstres[i].getPosX()]=monstres[i].getItem()->getTypeEquipement();
                                cout<<tab[attY*largeur+attX];
                            }
                            else if(monstres[i].getPotionHold()>0)
                            {
                                switch(monstres[i].getPotionHold())
                                {
                                    case 1:
                                        tab[monstres[i].getPosY()*largeur+monstres[i].getPosX()]='s';
                                        break;
                                    case 2:
                                        tab[monstres[i].getPosY()*largeur+monstres[i].getPosX()]='m';
                                        break;
                                    case 3:
                                        tab[monstres[i].getPosY()*largeur+monstres[i].getPosX()]='l';
                                        break;
                                    default:
                                        cout<<"erreur, une potion devrait se trouver sur l'ennemi\n";
                                }
                            }
                            else
                            {
                                tab[monstres[i].getPosY()*largeur+monstres[i].getPosX()]='v';
                            }
                            ennemisVivants--;
                            if(ennemisVivants==0)
                            {
                                tab[7]='S';
                                clearSol();
                            }
                            monstres[i].setPosX(0);
                            monstres[i].setPosY(0);
                        }
                    }
                }
                ++i;
            }
            if(!ennemiTrouve)
            {
                cout<<"Erreur, un ennemi devrait se trouver en X : "<<attX<<" Y : "<<attY<<"\n";
            }
        }
    }
    else
    {
        cout<<"attaque hors des limites du terrain\n";
    }
}
void Terrain ::clearSol()
{
     for(int i=0;i<hauteur;++i)
    {
        for(int j=0;j<largeur;++j)
        {
            if(tab[i*largeur+j]=='r')
            {
                tab[i*largeur+j]='v';
            }
        }
    }
}
void Terrain::replacerItem(Ennemi * monstreMort)
{
    assert(monstreMort!=NULL);
    int n=1;
    int n2=0;
    int enX=monstreMort->getPosX();
    int enY=monstreMort->getPosY();

    while(n<largeur)
    {
        if(enY+n<hauteur)
        {
            for(n2=0;n2<n;n2++)
            {
                if(enX+n2<largeur)
                {
                    if(tab[(enY+n)*largeur+enX+n2]=='v')
                    {
                        monstreMort->setPosX(enX+n2);
                        monstreMort->setPosY(enY+n);
                        return;
                    }
                }
                if(enX-n2>0)
                {
                    if(tab[(enY+n)*largeur+enX-n2]=='v')
                    {
                        monstreMort->setPosX(enX-n2);
                        monstreMort->setPosY(enY+n);
                        return;
                    }
                }
            }
        }
        if(enY-n>0)
        {
            for(n2=0;n2<n;n2++)
            {
                if(enX+n2<largeur)
                {
                    if(tab[(enY-n)*largeur+enX+n2]=='v')
                    {
                        monstreMort->setPosX(enX+n2);
                        monstreMort->setPosY(enY-n);
                        return;
                    }
                }
                if(enX-n2>0)
                {
                    if(tab[(enY-n)*largeur+enX-n2]=='v')
                    {
                        monstreMort->setPosX(enX-n2);
                        monstreMort->setPosY(enY-n);
                        return;
                    }
                }
            }
        }
        if(enX+n<largeur)
        {
            for(n2=0;n2<n;n2++)
            {
                if(enY+n2<hauteur)
                {
                    if(tab[(enY+n2)*largeur+enX+n]=='v')
                    {
                        monstreMort->setPosX(enX+n);
                        monstreMort->setPosY(enY+n2);
                        return;
                    }
                }
                if(enY-n2>0)
                {
                    if(tab[(enY-n2)*largeur+enX+n]=='v')
                    {
                        monstreMort->setPosX(enX+n);
                        monstreMort->setPosY(enY-n2);
                        return;
                    }
                }
            }
        }
        if(enX-n>0)
        {
            for(n2=0;n2<n;n2++)
            {
                if(enY+n2<hauteur)
                {
                    if(tab[(enY+n2)*largeur+enX-n]=='v')
                    {
                        monstreMort->setPosX(enX-n);
                        monstreMort->setPosY(enY+n2);
                        return;
                    }
                }
                if(enY-n2>0)
                {
                    if(tab[(enY-n2)*largeur+enX-n]=='v')
                    {
                        monstreMort->setPosX(enX-n);
                        monstreMort->setPosY(enY-n2);
                        return;
                    }
                }
            }
        }
        ++n;
    }
}
void Terrain::afficherTexte() const
{
    for(int i=0;i<hauteur;++i)
    {
        for(int j=0;j<largeur;++j)
        {
            cout<<tab[i*largeur+j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

void Terrain::setTab(char* newTab)
{
    assert(newTab!=NULL);
    tab=newTab;
}

void Terrain::setHauteur(const int newH)
{
    assert(newH>0);
    hauteur=newH;
}

void Terrain::setLargeur(const int newL)
{
    assert(newL>0);
    largeur=newL;
}

bool Terrain::updateTab()
{
        int input=getch();
        if(input==27)
        {
            return false;
        }
        if(input==32)
        {
            attaquePersonnage(heros);
        }
        else
        {
            deplacement(input);
        }
        deplacementEnnemi();
        return true;
}

bool Terrain::deplacementEnnemi ()
{
    int difX, difY, curX, curY;
    bool depOK;
    for(int i=0;i<nbEnnemis;++i)
    {
        if(monstres[i].getVivant())
        {
            depOK=false;
            curX=monstres[i].getPosX();
            curY=monstres[i].getPosY();
            difX=heros->getPosX()-curX;
            difY=heros->getPosY()-curY;
            if(monstres[i].deplacerEnnemi())
            {
                if(abs(difX)+abs(difY)==1)
                {
                    heros->PrendreDegats(monstres[i].getAttaque());
                    if(!heros->getVivant())
                        return true;
                    depOK=true;
                }
                if(abs(difX)>=abs(difY))
                {
                    if (difX>0)
                    {
                    if(tab[curX+1+curY*largeur]=='v'||tab[curX+1+curY*largeur]=='s'||tab[curX+1+curY*largeur]=='m'||tab[curX+1+curY*largeur]=='l'||tab[curX+1+curY*largeur]=='w'||tab[curX+1+curY*largeur]=='a')
                        {

                            tab[curX+curY*largeur]=monstres[i].getSurLoot();
                            monstres[i].setSurLoot(tab[curX+1+curY*largeur]);
                            tab[curX+1+curY*largeur]='E';
                            monstres[i].setPosX(curX+1);
                            depOK=true;
                        }
                    }
                    else if(difX<0)
                    {
                        if(tab[curX-1+curY*largeur]=='v'||tab[curX-1+curY*largeur]=='s'||tab[curX-1+curY*largeur]=='m'||tab[curX-1+curY*largeur]=='l'||tab[curX-1+curY*largeur]=='w'||tab[curX-1+curY*largeur]=='a')
                        {
                            tab[curX+curY*largeur]=monstres[i].getSurLoot();
                            monstres[i].setSurLoot(tab[curX-1+curY*largeur]);
                            tab[curX-1+curY*largeur]='E';
                            monstres[i].setPosX(curX-1);
                            depOK=true;
                        }
                    }
                }
                if(!depOK)
                {
                    if (difY>0)
                    {
                    if(tab[curX+(curY+1)*largeur]=='v'||tab[curX+(curY+1)*largeur]=='s'||tab[curX+(curY+1)*largeur]=='m'||tab[curX+(curY+1)*largeur]=='l'||tab[curX+(curY+1)*largeur]=='w'||tab[curX+(curY+1)*largeur]=='a')
                        {
                            tab[curX+curY*largeur]=monstres[i].getSurLoot();
                            monstres[i].setSurLoot(tab[curX+(curY+1)*largeur]);
                            monstres[i].setPosY(curY+1);
                            tab[curX+(curY+1)*largeur]='E';
                            depOK=true;
                        }
                    }
                    else if(difY<0)
                    {
                        if(tab[curX+(curY-1)*largeur]=='v'||tab[curX+(curY-1)*largeur]=='s'||tab[curX+(curY-1)*largeur]=='m'||tab[curX+(curY-1)*largeur]=='l'||tab[curX+(curY-1)*largeur]=='w'||tab[curX+(curY-1)*largeur]=='a')
                        {
                            tab[curX+curY*largeur]=monstres[i].getSurLoot();
                            monstres[i].setSurLoot(tab[curX+(curY-1)*largeur]);
                            monstres[i].setPosY(curY-1);
                            tab[curX+(curY-1)*largeur]='E';
                            depOK=true;
                        }
                    }
                }
                if(!depOK)
                {
                    if (difX>0)
                    {
                    if(tab[curX+1+curY*largeur]=='v'||tab[curX+1+curY*largeur]=='s'||tab[curX+1+curY*largeur]=='m'||tab[curX+1+curY*largeur]=='l'||tab[curX+1+curY*largeur]=='w'||tab[curX+1+curY*largeur]=='a')
                        {

                            tab[curX+curY*largeur]=monstres[i].getSurLoot();
                            monstres[i].setSurLoot(tab[curX+1+curY*largeur]);
                            tab[curX+1+curY*largeur]='E';
                            monstres[i].setPosX(curX+1);
                            depOK=true;
                        }
                    }
                    else if(difX<0)
                    {
                        if(tab[curX-1+curY*largeur]=='v'||tab[curX-1+curY*largeur]=='s'||tab[curX-1+curY*largeur]=='m'||tab[curX-1+curY*largeur]=='l'||tab[curX-1+curY*largeur]=='w'||tab[curX-1+curY*largeur]=='a')
                        {
                            tab[curX+curY*largeur]=monstres[i].getSurLoot();
                            monstres[i].setSurLoot(tab[curX-1+curY*largeur]);
                            tab[curX-1+curY*largeur]='E';
                            monstres[i].setPosX(curX-1);
                            depOK=true;
                        }
                    }
                }

        }

        }
    }
  return false;
}
bool Terrain::deplacementBoss()
{
    int difX, difY, curX, curY;
    bool depOK;
    for(int i=0;i<nbEnnemis;++i)
    {
        if(monstres[i].getVivant())
        {
            depOK=false;
            curX=monstres[i].getPosX();
            curY=monstres[i].getPosY();
            difX=heros->getPosX()-curX;
            difY=heros->getPosY()-curY;
            if(monstres[i].deplacerEnnemi())
            {
                if(abs(difX)+abs(difY)==1)
                {
                    heros->PrendreDegats(monstres[i].getAttaque());
                    if(!heros->getVivant())
                        return true;
                    depOK=true;
                }
                if(abs(difX)>=abs(difY))
                {
                    if (difX>0)
                    {
                    if(tab[curX+1+curY*largeur]=='v'||tab[curX+1+curY*largeur]=='r')
                        {

                            tab[curX+curY*largeur]='r';
                            tab[curX+1+curY*largeur]='E';
                            monstres[i].setPosX(curX+1);
                            depOK=true;
                        }
                    }
                    else if(difX<0)
                    {
                        if(tab[curX-1+curY*largeur]=='v'||tab[curX-1+curY*largeur]=='r')
                        {
                            tab[curX+curY*largeur]='r';
                            tab[curX-1+curY*largeur]='E';
                            monstres[i].setPosX(curX-1);
                            depOK=true;
                        }
                    }
                }
                if(!depOK)
                {
                    if (difY>0)
                    {
                    if(tab[curX+(curY+1)*largeur]=='v'||tab[curX+(curY+1)*largeur]=='r')
                        {
                            tab[curX+curY*largeur]='r';
                            monstres[i].setPosY(curY+1);
                            tab[curX+(curY+1)*largeur]='E';
                            depOK=true;
                        }
                    }
                    else if(difY<0)
                    {
                        if(tab[curX+(curY-1)*largeur]=='v'||tab[curX+(curY-1)*largeur]=='r')
                        {
                            tab[curX+curY*largeur]='r';
                            monstres[i].setPosY(curY-1);
                            tab[curX+(curY-1)*largeur]='E';
                            depOK=true;
                        }
                    }
                }
                if(!depOK)
                {
                    if (difX>0)
                    {
                    if(tab[curX+1+curY*largeur]=='v'||tab[curX+1+curY*largeur]=='r')
                        {

                            tab[curX+curY*largeur]='r';
                            tab[curX+1+curY*largeur]='E';
                            monstres[i].setPosX(curX+1);
                            depOK=true;
                        }
                    }
                    else if(difX<0)
                    {
                        if(tab[curX-1+curY*largeur]=='v'||tab[curX-1+curY*largeur]=='r')
                        {
                            tab[curX+curY*largeur]='r';
                            tab[curX-1+curY*largeur]='E';
                            monstres[i].setPosX(curX-1);
                            depOK=true;
                        }
                    }
                }

        }

        }
    }
  return false;
}
Ennemi* Terrain::getMonstres() const
{
    return monstres;
}

void Terrain::setMonstres(Ennemi * newMonstres)
{
    assert(newMonstres!=NULL);
    monstres=newMonstres;
}
int Terrain::getNbEnnemis() const
{
    return nbEnnemis;
}
void Terrain::setNbEnnemis(const int newNbEnnemis)
{
    assert(nbEnnemis>=0);
    nbEnnemis=newNbEnnemis;
}
Personnage * Terrain::getHeros()
{
    return heros;
}

int Terrain::getHauteur() const
{
    return hauteur;
}
int Terrain::getLargeur() const
{
    return largeur;
}
char* Terrain::getTab() const
{
    return tab;
}
void Terrain::setHeros(Personnage * newHeros)
{
    assert(newHeros!=NULL);
    heros=newHeros;
}
void Terrain::setEnnemisVivants(const int newEnnemisVivants)
{
    assert(newEnnemisVivants>=0);
    ennemisVivants=newEnnemisVivants;
}
int Terrain::getEnnemisVivants() const
{
    return ennemisVivants;
}

void Terrain::setLoots(Loot * tabLoots)
{
    assert(tabLoots!=NULL);
    loots=tabLoots;
}
int Terrain::getNbLoots() const
{
    return nbItems;
}
void Terrain::setNbLoots(const int newNbLoots)
{
    assert(newNbLoots>=0);
    nbItems=newNbLoots;
}
