#include "Jeu.h"
using namespace std;

Jeu::Jeu()
{
    herosJeu = new Personnage();
    niveau=0;
    terrainCourant=NULL;
}
Jeu::~Jeu()
{
    delete terrainCourant;
    delete herosJeu;
}
void Jeu::initTerrain(int const terNum)
{
    assert(terNum >= 0);
    int rdmVal;
    Item * monsterLoot;
    niveau++;
    if(terrainCourant!=NULL)
    {
        delete terrainCourant;
    }
    terrainCourant= new Terrain(herosJeu,niveau);
    ifstream terFile;
    string path = "./assets/terrains/ter";
    path+=to_string(terNum);
    terFile.open(path);
    if (!terFile)
    {
        cout<<"problème lors de l'ouverture du fichier ter"<<terNum;
        return;
    }
    int valTer=0;
    terFile>>valTer;//récupération de la hauteur
    terrainCourant->setHauteur(valTer);
    int tailleTer=valTer;//tailleter stocke la taille du terrain
    terFile>>valTer;//récupération de la largeur
    terrainCourant->setLargeur(valTer);
    tailleTer*=valTer;
    terFile>>valTer;
    terrainCourant->setNbEnnemis(valTer);//récupération du nombre d'ennemis
    terrainCourant->setLoots(new Loot[valTer]);
    terrainCourant->setEnnemisVivants(valTer);
    int terNbEnnemis=valTer;
    char* tabTer = new char[tailleTer];//allocation d'un tableau de taille tailleTer
    terFile.ignore(600,'\n');//met le pointeur au début des caractères
    terFile.read(tabTer,tailleTer);
    terrainCourant->setTab(tabTer);
    terFile>>valTer;
    herosJeu->setPosX(valTer);
    terFile>>valTer;
    herosJeu->setPosY(valTer);
    Ennemi * monstresTer= new Ennemi[terNbEnnemis];
    for(int i=0;i<terNbEnnemis;++i)
    {
        monsterLoot=NULL;
        rdmVal=rand()%100;
        monstresTer[i]=Ennemi();
        terFile>>valTer;
        monstresTer[i].setPosX(valTer);
        terFile>>valTer;
        monstresTer[i].setPosY(valTer);
        monstresTer[i].setCdAtt(700-6*niveau);
        monstresTer[i].setVie(60+niveau*3);
        monstresTer[i].setAttaque(10+(int)((float)(niveau)*0.5));
        if(rdmVal>62)//si vrai, on ajoute un loot
        {
            cout<<"Un monstre a quelque chose sur lui\n";
            if(rdmVal>79)//si vrai, ce sera une arme/armure
            {
                if(rdmVal>89)
                {
                    if (niveau<10)
                    {
                        monsterLoot=new Item('w',1);
                    }
                    else if(niveau<25)
                    {
                        if(rdmVal%2==0)
                        {
                            monsterLoot=new Item('w',2);
                        }
                        else
                        {
                            monsterLoot=new Item('w',1);
                        }
                    }
                    else
                    {
                        if(rdmVal<92)
                        {
                            monsterLoot=new Item('w',1);
                        }
                        else if(rdmVal<95)
                        {
                            monsterLoot=new Item('w',2);
                        }
                        else
                        {
                            monsterLoot=new Item('w',3);
                        }
                    }

                }
                else
                {
                    if (niveau<10)
                    {
                        monsterLoot=new Item('a',1);
                    }
                    else if(niveau<25)
                    {
                        if(rdmVal%2==0)
                        {
                            monsterLoot=new Item('a',2);
                        }
                        else
                        {
                            monsterLoot=new Item('a',1);
                        }
                    }
                    else
                    {
                        if(rdmVal<82)
                        {
                            monsterLoot=new Item('a',1);
                        }
                        else if(rdmVal<85)
                        {
                            monsterLoot=new Item('a',2);
                        }
                        else
                        {
                            monsterLoot=new Item('a',3);
                        }
                    }
                }
                monstresTer[i].setItemHold(true);
                monstresTer[i].setItem(new Item(monsterLoot));
                delete monsterLoot;
            }
            else
            {
                monstresTer[i].setPotionHold(rdmVal%3+1);
            }
        }
    }
    terFile.close();
    terrainCourant->setMonstres(monstresTer);
}
void Jeu::initTerrainBoss(int const terNum)
{
    assert(terNum >= 0);
    int rdmVal;
    Item * monsterLoot;
    niveau++;
    if(terrainCourant!=NULL)
    {
        delete terrainCourant;
    }
    terrainCourant= new Terrain(herosJeu,niveau);
    ifstream terFile;
    string path = "./assets/terrains/ter";
    //path+=to_string(terNum);
    //terFile.open(path);
    if (!terFile)
    {
        cout<<"problème lors de l'ouverture du fichier ter"<<terNum;
        return;
    }
    int valTer=0;
    terFile>>valTer;//récupération de la hauteur
    terrainCourant->setHauteur(valTer);
    int tailleTer=valTer;//tailleter stocke la taille du terrain
    terFile>>valTer;//récupération de la largeur
    terrainCourant->setLargeur(valTer);
    tailleTer*=valTer;
    terFile>>valTer;
    terrainCourant->setNbEnnemis(valTer);//récupération du nombre d'ennemis
    terrainCourant->setLoots(new Loot[valTer]);
    terrainCourant->setEnnemisVivants(valTer);
    int terNbEnnemis=valTer;
    char* tabTer = new char[tailleTer];//allocation d'un tableau de taille tailleTer
    terFile.ignore(600,'\n');//met le pointeur au début des caractères
    terFile.read(tabTer,tailleTer);
    terrainCourant->setTab(tabTer);
    terFile>>valTer;
    herosJeu->setPosX(valTer);
    terFile>>valTer;
    herosJeu->setPosY(valTer);
    Ennemi * monstresTer= new Ennemi[terNbEnnemis];
    for(int i=0;i<terNbEnnemis;++i)
    {
        monsterLoot=NULL;
        rdmVal=rand()%100;
        monstresTer[i]=Ennemi();
        terFile>>valTer;
        monstresTer[i].setPosX(valTer);
        terFile>>valTer;
        monstresTer[i].setPosY(valTer);
        monstresTer[i].setCdAtt(550-3*niveau);
        monstresTer[i].setVie(400+niveau*8);
        monstresTer[i].setAttaque(12+(int)((float)(niveau)*0.7));
        if(rdmVal>30)//si vrai, on ajoute un loot
        {
            cout<<"Un monstre a quelque chose sur lui\n";
            if(rdmVal>69)//si vrai, ce sera une arme/armure
            {
                if(rdmVal>85)
                {
                    if (niveau<10)
                    {
                        monsterLoot=new Item('w',1);
                    }
                    else if(niveau<25)
                    {
                        if(rdmVal%2==0)
                        {
                            monsterLoot=new Item('w',2);
                        }
                        else
                        {
                            monsterLoot=new Item('w',1);
                        }
                    }
                    else
                    {
                        if(rdmVal<90)
                        {
                            monsterLoot=new Item('w',1);
                        }
                        else if(rdmVal<93)
                        {
                            monsterLoot=new Item('w',2);
                        }
                        else
                        {
                            monsterLoot=new Item('w',3);
                        }
                    }
                }
                else
                {
                    if (niveau<10)
                    {
                        monsterLoot=new Item('a',1);
                    }
                    else if(niveau<25)
                    {
                        if(rdmVal%2==0)
                        {
                            monsterLoot=new Item('a',2);
                        }
                        else
                        {
                            monsterLoot=new Item('a',1);
                        }
                    }
                    else
                    {
                        if(rdmVal<75)
                        {
                            monsterLoot=new Item('a',1);
                        }
                        else if(rdmVal<80)
                        {
                            monsterLoot=new Item('a',2);
                        }
                        else
                        {
                            monsterLoot=new Item('a',3);
                        }
                    }
                }
                monstresTer[i].setItemHold(true);
                monstresTer[i].setItem(new Item(monsterLoot));
                delete monsterLoot;
            }
            else
            {
                monstresTer[i].setPotionHold(3);
            }
        }
    }
    terFile.close();
    terrainCourant->setMonstres(monstresTer);
}
void Jeu::InitJeu()
{
    if(niveau%5==4)
    {
        initTerrainBoss(0);
    }
    else
    {
        initTerrain(rand()%9+1);
    }
    jeuSDL.afficherInit(jeuWindow, jeuRenderer);
    int resSDL=jeuSDL.afficherBoucle(jeuRenderer, terrainCourant, niveau);
    if(resSDL==1||resSDL==100)
    {
        loadNewTerrain();
    }
    else if(resSDL==2)
    {
        if(jeuSDL.afficherFinJeu(jeuRenderer))
        {
            resetJeu();
        }
    }
}

void Jeu::loadNewTerrain()
{
    if(niveau%5==4)
    {
        initTerrainBoss(0);
    }
    else
    {
        initTerrain(rand()%9+1);
    }
    int resSDL=jeuSDL.afficherBoucle(jeuRenderer, terrainCourant, niveau);
    if(resSDL==1||resSDL==100)
    {
        loadNewTerrain();
    }
    else if(resSDL==2)
    {
        if(jeuSDL.afficherFinJeu(jeuRenderer))
        {
            resetJeu();
        }
    }
    else if(resSDL==4)
    {
        if(jeuSDL.afficherFinJeuVictoire(jeuRenderer))
        {
            resetJeu();
        }
    }
}
void Jeu::resetJeu()
{
    herosJeu = new Personnage();
    niveau=0;
    delete terrainCourant;
    terrainCourant=NULL;
    if(niveau%5==4)
    {
        initTerrainBoss(0);
    }
    else
    {
        initTerrain(rand()%9+1);
    }
    int resSDL=jeuSDL.afficherBoucle(jeuRenderer, terrainCourant, niveau);
    if(resSDL==1||resSDL==100)
    {
        loadNewTerrain();
    }
    else if(resSDL==2)
    {
        if(jeuSDL.afficherFinJeu(jeuRenderer))
        {
            resetJeu();
        }
    }
}
