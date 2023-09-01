#ifndef _LOOT
#define _LOOT
#include "Item.h"

class Loot
{
private :

    Item* drop;

    int positionx;

    int positiony;

public :

/**
 * @brief Constructeur de la classe Loot.
 * Instancie un Item et lui donne un couple de coordonnées (x,y) donnés en paramètres.
 * @param itemLoot (Pointeur sur Item) Item à looter.
 * @param posX (int) Position x.
 * @param posY (int) Position y.
 */
    Loot(Item * itemLoot,const int posX,const int posY);

/**
 * @brief Constructeur par défaut de la classe Loot.
 * Instancie une arme de tier 0 grâce au constructeur par défaut de la classe Item et initialise le couple de coordonnées (x,y) à (0,0).
 */
    Loot();

/**
 * @brief Destructeur de la classe Loot.
 * Supprime l'Item.
 */
    ~Loot();

/**
 * @brief Mutateur de l'Item à drop de la classe Loot.
 * @param item (Item*) Nouvel Item à drop.
 */
    void setDrop(Item* item);

/**
 * @brief Mutateur de la coordonnée X de la classe Loot.
 * @param x (int) Nouvelle coordonnée X.
 */
    void setPosX(const int x);

/**
 * @brief Mutateur de la coordonnée Y de la classe Loot.
 * @param y (int) Nouvelle coordonnée Y.
 */
    void setPosY(const int y);

/**
 * @brief Acceseur de l'item à drop de la classe Loot
 * @return drop (Item*)
 */
    Item* getDrop() const;

/**
 * @brief Acceseur à la coordonnée X de la classe Loot
 * @return positionx (int)
 */
    int getPosX() const;

/**
 * @brief Acceseur à la coordonnée Y de la classe Loot
 * @return positiony (int)
 */
    int getPosY() const;
};


#endif // _LOOT
