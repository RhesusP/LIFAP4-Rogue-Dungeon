#ifndef _TERRAIN
#define _TERRAIN

#include "Personnage.h"
#include "Ennemi.h"
#include "Loot.h"
#include <vector>
#include <iostream>
#include <conio.h>

class Terrain
{
    private :

    Personnage* heros;
    Ennemi* monstres; /// pointera vers un tableau de pointeur dans l'initialisation
    Loot* loots; /// pointera vers un tableau de pointeur dans l'initialisation
    int niveau;
    int hauteur;
    int largeur;
    char* tab;//'P'=personnage, 'E'=ennemi, 'v'=vide, 'o'=obstacle, 's','m','l'=potion petite/moyenne/grande, 'w'=arme, 'a'=armure,  'S'=sortie
    int nbEnnemis;
    int ennemisVivants;
    int nbItems;

public :

/**
 * @brief Constructeur par défaut de la classe Terrain.
 * Initialise le numéro du niveau à 0, la hauteur à 21, la largeur à 15, le nombre d'ennemis à 0 (donc aucun ennemi vivant) et le nombre d'Item à 0.
 * Les autres données du terrain sont initialisées dans la méthode initTerrain de la classe Jeu.
 */
    Terrain();

/**
 * @brief Constructeur avec paramètres de la classe Terrain.
 * Ce constructeur prend en paramètre un pointeur sur Personnage correpondant au héros (personnage joué) et un numéro de niveaux. Il initialise
 * la hauteur à 21, la largeur à 15 et le nombre d'Ennemis et d'Items à 0. Il est pensé pour être utilisé dans la fonction initJeu afin de récupérer
 * le héros entre les niveaux.
 * @param jeuHeros (Pointeur sur Personnage) Héros du jeu.
 * @param jeuNiveau (int) Numéro du niveau.
 */
    Terrain(Personnage * jeuHeros,const int jeuNiveau);

/**
 * @brief Destructeur de la classe Terrain.
 * Efface le tableau de caractères, le tableau d'Ennemis et le tableau de Loot.
 */
    ~Terrain();

/**
 * @brief Fonction de la classe Terrain permettant au Personnage de se déplacer.
 * Gère le déplacement du Personnage sur le terrain en fonction de la touche appuyée, orientant le personnage et le déplaçant si la case est libre
 * (pas d'ennemi ni d'obstacle). Cette fonction gère aussi la récupération du loot et la prise de dégats lorsque le personnage marche sur le sol rouge
 * en combat de boss. Donne aussi des informations en console sur le déplacement du personnage.
 * @param newOri (int) Nouvelle orientation du personnage et direction du déplacement.
 */
    void deplacement(const int newOri);

/**
 * @brief Fonction de la classe Terrain permettant au Personnage d'attaquer un Ennemi.
 * Verifie si un Ennemi se trouve en face du Personnage. Dans ce cas là, l'attaque peut s'effectuer. Fait aussi apparaître la porte de sortie une fois
 * les ennemis vaincus. Rendue obsolète après l'ajout de l'affichage via SDL.
 * @param attaquant (Personnage*) Personnage attaquant.
 */
    void attaquePersonnage(Personnage * attaquant);

/**
 * @brief Ancienne fonction de la classe Terrain qui permettait d'afficher le terrain en mode texte.
 * Affiche le tableau de caractères tab dans la console.
 */
    void afficherTexte() const;

/**
 * @brief Ancienne fonction de la classe Terrain qui permettait de mettre à jour le tableau de caractères selon les actions effectuées.
 * Permettait l'intégration de la touche <ECHAP> pour quitter le jeu et <SPACE> pour attaquer.
 * @return Un booleen indiquant si la touche <ECHAP> a été appuyée, auquel cas le jeu se terminait.
 */
    bool updateTab();

/**
 * Mutateur de l'attribut tab de la classe Terrain.
 * @param newTab (char*) Tableau de caractères
 */
    void setTab(char* newTab);

/**
 * @brief Mutateur de la hauteur de la classe Terrain.
 * @param newH (int) Nouvelle hauteur
 */
    void setHauteur(const int newH);

/**
 * @brief Mutateur à la largeur de la classe Terrain.
 * @param newL (int) Nouvelle largeur
 */
    void setLargeur(const int newL);

/**
 * @brief Accesseur du tableau de monstres du Terrain.
 * @return Tableau d'Ennemis.
 */
    Ennemi* getMonstres() const;

/**
 * @brief Mutateur du tableau de monstres du Terrain.
 * @param newMonstres (Tableau d'Ennemis) Nouveaux monstres.
 */
    void setMonstres(Ennemi* newMonstres);

/**
 * @brief Acesseur du nombre d'ennemis (vivants et morts) sur le Terrain.
 * @return Nombre d'ennemis.
 */
    int getNbEnnemis() const;

/**
 * @brief Mutateur du nombre d'ennemis (vivants et morts) sur le Terrain.
 * @param newNbEnnemis (int) Nouveau nombre d'ennemis.
 */
    void setNbEnnemis(const int newNbEnnemis);

/**
 * @brief Mutateur du nombre d'ennemis vivants sur le Terrain.
 * @param newEnnemisVivants (int) Nouveau nombre d'ennemis vivants.
 */
    void setEnnemisVivants(const int newEnnemisVivants);

/**
 * @brief Accesseur du nombre d'ennemis vivants sur le Terrain.
 * @return Nombre d'ennemis vivants (int).
 */
    int getEnnemisVivants () const;

/**
 * @brief Accesseur du héros présent sur le Terrain.
 * @return Pointeur sur Personnage.
 */
    Personnage * getHeros();

/**
 * @brief Accesseur de la hauteur du Terrain.
 * @return Hauteur du Terrain (int).
 */
    int getHauteur() const;

/**
 * @brief Accesseur de la largeur du Terrain.
 * @return Largeur du Terrain (int).
 */
    int getLargeur() const;

/**
 * @brief Accesseur du tableau composant le Terrain.
 * Le tableau sert à gérer le niveau et à être lu par les différentes classes. Chaque caractère correspond à un élément :
 * - 'o' : obstacle
 * - 'P' : personnage (héros)
 * - 'E' : ennemi
 * - 'v' : sol
 * - 's' : petite potion
 * - 'm' : moyenne potion
 * - 'l' : grosse potion
 * - 'w' : arme
 * - 'a' : armure
 * - 'S' : sortie
 * - 'r' : le sol rouge laissé par le boss là où il passe
 * @return Tableau de caractères.
 */
    char* getTab() const;

/**
 * @brief Mutateur du héros sur le Terrain.
 * Prend en paramètre un pointeur sur Personnage et fait appel appel au constructeur de la classe Personnage afin d'instancier un héros sur le terrain.
 * @param newHeros (Personnage *) Nouveau héros.
 */
    void setHeros(Personnage * newHeros);

/**
 * @brief Fonction gérant le comportement des ennemis (leur déplacement et leurs attaques). S'ils s'ont sur une case adjacente au héros, ils attaquent. Sinon
 * ils s'approchent du héros s'ils le peuvent en priorité sur l'axe où ils sont le plus éloignés. Cette fonction gère aussi le cas où un ennemi marche
 * sur un loot ou une potion, stockant temporairement le caractère le représentant via l'attribut surLoot avant de le reposer lorque l'Ennemi se déplace.
 * @return Renvoie un booléen : vrai si le Héros est mort, faux sinon.
 */
    bool deplacementEnnemi();
 /**
 * @brief Fonction similaire à deplacementEnnemi adaptée au boss. Le fait de gérer si un ennemi marche sur un loot est remplacé par l'apparition de sol rouge
 * là où le boss était lorsqu'il se déplace.
 * @return Renvoie un booléen : vrai si le Héros est mort, faux sinon.
 */

    bool deplacementBoss();
/**
 * @brief Mutateur du tableau d'Items à looter de la classe Terrain.
 * @param tabLoots (un tableau de Loots) Nouveau tableau des objets à looter.
 */
    void setLoots(Loot * tabLoots);

/**
 * @brief Accesseur du nombre d'Items sur le Terrain.
 * @return Nombre entier d'Items sur le Terrain.
 */
    int getNbLoots() const;

/**
 * @brief Mutateur du nombre d'Items sur le Terrain.
 * @param newNbLoots (int) Nouveau nombre d'Items.
 */
    void setNbLoots(const int newNbLoots);

/**
 * @brief Fonction servant à replacer un monstre une fois mort de façon à ce qu'il n'y ait aucun problème à instancier son loot s'il se trouvait sur un
 * autre loot.
 */
    void replacerItem(Ennemi * monstreMort);
/**
 * @brief Fonction servant à retirer le sol rouge une fois le boss vaincu.
 */
    void clearSol();
};

#endif // _TERRAIN
