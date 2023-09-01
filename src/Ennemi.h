#ifndef _ENNEMI
#define _ENNEMI

#include "Entite.h"
#include "Item.h"
#include <sys/time.h>
using namespace std;

class Ennemi : public Entite
{
    private :
        Item* Items;
        bool isBoss;
        char nom;
        Item* loot;
        float cdDeplacement;
        int holdPotion;
        bool holdItem;
        char surLoot;
    public :

/**
 * @brief Constructeur par défaut de la classe Ennemi. La classe Ennemi hérite de la classe Entite.
 * Initialise les données de l'ennemi qui seront définies plus précisément lors de l'initialisation du terrain.
 */
        Ennemi();

/**
 * @brief Destructeur de la classe Ennemi
 * Supprime le pointeur sur Item s'il n'est pas à NULL.
*/
        ~Ennemi();

/**
* @brief Gère le cooldown des actions de l'ennemi (si celui-ci est écoulé, le réinitialise et renvoie vrai, renvoie faux sinon
*/
        bool deplacerEnnemi();

/**
 * @brief Mutateur de l'Item de l'Ennemi.
 * @param newItem nouvel Item.
 */
        void setItem(Item * newItem);

/**
 * @brief Accesseur de l'Item de l'Ennemi.
 * @return Renvoie le pointeur sur l'Item de l'Ennemi.
 */
        Item * getItem() const;

/**
 * @brief Mutateur de l'attribut holdPotion (la potion qui sera déposée au moment de sa mort s'il en porte une).
 * @param potion, un entier représentant la potion (1 pour une petite, 2 pour une moyenne, 3 pour une grosse)
 */
        void setPotionHold(const int potion);

/**
 * @brief Mutateur de l'attribut holdItem de la classe Ennemi.
 * @param newItemHold (bool) Booléen afin de savoir si l'Ennemi porte un Item.
 */
        void setItemHold (const bool newItemHold);

/**
 * @brief Accesseur de l'attribut holdPotion, la potion que porte l'ennemi
 */
        int getPotionHold() const;

/**
 * @brief Accesseur à l'attribut holdItem de la classe Ennemi.
 * @return Booléen afin de savoir si l'Ennemi possède un Item.
 */
        bool getItemHold() const;

/**
 * @brief Mutateur du temps entre deux actions de l'Ennemi
 * @param  newCd (float) Nouveau cooldown d'action.
 */
        void setCdDeplacement(const float newCd);

/**
 * @brief Accesseur de l'attribut surLoot, un caractère représentant ce sur quoi l'ennemi se trouve pour le réafficher une fois que l'ennemi change de case.
 */
        char getSurLoot() const;

/**
 * @brief Mutateur de l'attribut surLoot, un caractère représentant ce sur quoi l'ennemi se trouve pour le réafficher une fois que l'ennemi change de case.
 */
        void setSurLoot(const char newLoot);
};
#endif
