#ifndef _JEUSDL
#define _JEUSDL

#include <SDL.h>
#include <stdio.h>
#include "Terrain.h"

class Graphisme{
private :

    SDL_Texture * Sol_text;

    SDL_Texture * HerosFace_text;

    SDL_Texture * HerosGauche_text;

    SDL_Texture * HerosDos_text;

    SDL_Texture * HerosFaceAttaque_text;

    SDL_Texture * HerosDosAttaque_text;

    SDL_Texture * HerosDroiteAttaque_text;

    SDL_Texture * HerosGaucheAttaque_text;

    SDL_Texture * Ennemi_text;

    SDL_Texture * Mur_text;

    SDL_Texture * Porte_text;

    SDL_Texture * Armure_text;

    SDL_Texture * Arme_text;

    SDL_Texture * Potion_text;

    SDL_Texture * Boss_text;

    SDL_Texture * SolR_text;

    SDL_Texture * Text_actu;

    SDL_Texture * Nb_0;

    SDL_Texture * Nb_1;

    SDL_Texture * Nb_2;

    SDL_Texture * Nb_3;

    SDL_Texture * Nb_4;

    SDL_Texture * Nb_5;

    SDL_Texture * Nb_6;

    SDL_Texture * Nb_7;

    SDL_Texture * Nb_8;

    SDL_Texture * Nb_9;

    SDL_Texture * Coeur_text;

    SDL_Texture * Interface_potion_text;

    SDL_Texture * Interface_arme_text;

    SDL_Texture * Interface_armure_text;

    SDL_Texture * Fin_Niveau_text;

    SDL_Texture * Fin_Niveau_Victoire_text;

    SDL_Texture * Escalier_text;

    bool porteOuverte;
    bool finNiveau;
    bool herosAttaque;

public :

/**
 * @brief Fonction initialisant la fenetre SDL, cette fonction va aussi initialiser toutes les textures presentes dans le jeu.
 * @param pWindow (SDL_Window) est la variable representant la fenetre, renderer (SDL_Renderer) est la variable de rendu utiliser pour tout les affichages.
*/
    void afficherInit(SDL_Window * pWindow, SDL_Renderer *& renderer);

/**
 * @brief Fonction detruisant la fenetre SDL.
 * @param pWindow (SDL_Window) est la variable representant la fenetre, renderer (SDL_Renderer) est la variable de rendu utiliser pour tout les affichages.
*/
    void afficherDetruit(SDL_Window * pWindow, SDL_Renderer * renderer);

/**
 * @brief Fonction gerant toutes les interactions entre le clavier et les fonctions. Elle permet aussi le changement de niveau.
 * @param renderer (SDL_Renderer) est la variable de rendu utiliser pour tout les affichages, ter (Terrain) permet l'interaction avec toutes les entités, niveau (int) est le niveau actuel.
*/
    int afficherBoucle(SDL_Renderer * renderer, Terrain * ter, const int niveau);

/**
 * @brief Fonction affichant le jeu avec les chagement du au deplacement ou à la mort des ennemis.
 * @param renderer (SDL_Renderer) est la variable de rendu utiliser pour tout les affichages, ter (Terrain) permet l'interaction avec toutes les entités, niveau (int) est le niveau actuel.
 * @return un code indiquant aux methodes de la classe jeu la terminaison du programme (0 = l'application a été quitter,1 = niveau suivant, 2 = mort du personnage, 4 = victoire, 100 = code de triche)
*/
    void afficher(SDL_Renderer * renderer, Terrain * ter, const int niveau);

/**
 * @brief Fonction affichant l'ecran de mort, elle permet aussi de relancer la partie.
 * @param renderer (SDL_Renderer) est la variable de rendu utiliser pour tout les affichages.
 * @return si le joueur a appuyé sur 'r' pour recommencer une partie à la fin
*/
    bool afficherFinJeu(SDL_Renderer * renderer);

/**
 * @brief Fonction affichant l'ecran de victoire, elle permet aussi de relancer la partie.
 * @param renderer (SDL_Renderer) est la variable de rendu utiliser pour tout les affichages.
 * @return si le joueur a appuyé sur 'r' pour recommencer une partie à la fin
*/
    bool afficherFinJeuVictoire(SDL_Renderer * renderer);

};

#endif // _JEUSDL


