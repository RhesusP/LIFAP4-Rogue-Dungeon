#ifndef _PERSONNAGE
#define _PERSONNAGE
#include <ctime>
#include "Entite.h"
#include "Item.h"
using namespace std;

class Personnage : public Entite
{
    private :
        Item* items;
        int* inventairePotions;
     public :

/**
 * @brief Constructeur par défaut de la classe Personnage.
 * La classe Personnage hérite de la classe Entite. Ce contructeur initialise certains attributs de la classe Entite ainsi que d'autres spécifiques
 * à cette classe. Le personnage commence avec aucune potion, un cooldown de 100 millisecondes et deux objets de tier 0, ne donnant aucun bonus.
*/
        Personnage();

/**
 * @brief Destructeur de la classe Ennemi
 * Efface le tableau d'Items et l'inventaire des potions.
*/
        ~Personnage();

/**
 * @brief Fonction de la classe Personnage permettant d'utiliser une potion.
 * Est utilisable si le Personnage possède au moins une potion de la taille indiquée par l'indice dans son inventaire. Elle fait appel à la fonction
 * soin de la classe Entite, soignant le personnage de 30, 60 ou 90 pv selon la taille de la potion et met à jour le nombre de potions dan l'inventaire du Personnage.
 * @param potion (int) Indice de la potion à utiliser dans l'inventaire
 */
        void utiliserPotion(const int potion);

/**
 * @brief Fonction de la classe Personnage permettant de modifier les statistiques du Personnage.
 */
        void modifierStats (Item * newItem);

/**
 * @brief Met à jour le tableau inventairePotion lorsque le personnage ramasse une potion.
 * @param newPotion (int) Indice de la potion à ajouter.
 */
        void ramasserPotion(const int newPotion);

/**
 * @brief Permet de vérifier si le personnage peut attaquer.
 * Si la dernière attaque du Personnage a été efféctuée dans un laps de temps inférieur au cooldown attaque, alors le personnage ne pourra pas atatquer.
 * Dans le cas contraire, le Personnage peut attaquer et le booléen retourné est égal à True.
 * @return Possibilité d'attaque du Personnage (booléen).
 */
        bool peutAct();

/**
 * @brief Accesseur de l'inventaire des potions du Personnage.
 * @return Inventaire des potions
 */
        int* getPotions() const;

/**
 * @brief Accesseur des Items du Personnage.
 * @return Inventaire d'Items (tableau d'Items).
 */
        Item* getItems() const;
};
#endif
