#ifndef _ENTITE
#define _ENTITE
#include <sys/time.h>
#include <string>
#include <cassert>

using namespace std;

class Entite
{
    protected :

        int vie, vieMAX, defense, attaque, taille, positionX, positionY, cooldownAttaque, cooldownMax;
        bool estVivant, chargeAttaque;
        char orientation;//'h', 'b', 'g', 'd'
        long int dernierDeplacement;
        struct timeval tp;

    public :
/**
 * @brief Constructeur par défaut de la classe Entite.
 * Initialise les attributs. Ainsi, l'Entite a une vie et une vieMAX à 100, un cooldown d'attaque de 800, est vivante et est orientée
 * vers le haut initialise aussi le dernier déplacement comme l'instant de création de l'Entite
*/
    Entite();

/**
 * @brief Fonction de la classe Entite gérant la prise de degats.
 * Permet d'afficher les dégats subis et de calculer la vie restante de l'Entite apres la prise de degats en prenant en compte la défense. Dans le cas où la vie de l'Entite
 * est inferieure a zéro, alors l'attribut estVivant passe à False.
 * @param degatsSubis (int) Dégats infligés à l'Entite.
 */
    void PrendreDegats(int degatsSubis);

/**
 * @brief Fonction de la classe Entite permettant de restaurer de la vie à l'Entite.
 * Permet d'afficher les PV restaurés et de calculer la vie restante de l'Entite après le soin. Limite le soin à la vie maximale de l'Entite.
 * @param pvRendus (int) Points de vie restaurés.
 */
    void soin(const int pvRendus);

/**
 * @brief Acceseur de l'attribut estVivant de l'Entite.
 * @return estVivant (bool)
 */
    bool getVivant();

/**
 * @brief Acceseur de l'attribut vie de l'Entite.
 * @return vie (int)
 */
    int getVie() const;

/**
 * @brief Acceseur de l'attribut vieMAX de l'Entite.
 * @return vieMAX (int)
 */
    int getVieMAX() const;

/**
 * @brief Acceseur de l'attribut positionX de l'Entite.
 * Retourne la coordonnée X de l'Entite
 * @return positionX (int)
 */
    int getPosX() const;

/**
 * @brief Acceseur de l'attribut positionY de l'Entite.
 * Retourne la coordonnée y de l'Entite
 * @return positionY (int)
 */
    int getPosY() const;

/**
 * @brief Mutateur de la vie de la classe Entite.
 * @param newVie (int) Nouvelle vie
 */
    void setVie(const int newVie);

/**
 * @brief Mutateur de la vie maximale de la classe Entite.
 * @param newVie MAX(int) Nouvelle vie maximale.
 */
    void setVieMAX(const int newVieMAX);

/**
 * @brief Mutateur de la coordonnée X de la classe Entite.
 * @param newX (int) Nouvelle coordonnée X
 */
    void setPosX(const int newX);

/**
 * @brief Mutateur de la coordonnée Y de la classe Entite.
 * @param newY (int) Nouvelle coordonnée Y
 */
    void setPosY(const int newY);

/**
 * @brief Acceseur de l'attribut attaque de l'Entite.
 * @return attaque (int)
 */
    int getAttaque() const;

/**
 * @brief Acceseur de l'attribut orientaion de l'Entite.
 * Retourne le caractère correspondant à l'orientation actuelle de l'Entite.
 * @return orientation (char)
 */
    char getOrientation() const;

/**
 * @brief Mutateur de l'orientation de la classe Entite.
 * @param newOri (char) Nouvelle orientation
 */
    void setOrientation(const char newOri);

/**
 * @brief Mutateur de l'attaque de la classe Ennemi.
 * @param newAtt (int) Nouvelle valeur de l'attaque.
 */
    void setAttaque(const int newAtt);

/**
 * @brief Mutateur du cooldown de l'attaque de l'Entite.
 * @param newCd (int) Nouveau cooldown d'attaque.
 */
    void setCdAtt(const int newCd);
};


#endif
