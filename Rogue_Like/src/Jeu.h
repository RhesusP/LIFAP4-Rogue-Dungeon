#ifndef _JEU
#define _JEU
#include "Terrain.h"
#include <fstream>
#include<iostream>
#include<string>
#include "Jeu_SDL.h"
class Jeu
{
    private:
        int niveau;
        Terrain * terrainCourant;
        Personnage * herosJeu;
        Graphisme jeuSDL;
        SDL_Window * jeuWindow;
        SDL_Renderer * jeuRenderer;

    public:

/**
 * @brief Constructeur de la classe Jeu.
 * Instancie un héros grâce au constructeur par défaut de la classe Personnage. Le niveau est initialisé à 0 et le terrainCourant à n NULL.
 */
        Jeu();

/**
 * @brief Desctructeur de la classe Jeu.
 * Supprime le terrain courant ainsi que le héros du jeu.
 */
        ~Jeu();

/**
 * @brief Fonction initialisant un terrain depuis un fichier situé dans le sous-dossier terrain du dossier assets. Le nom du fichier est de la forme ter(terNum).
 * Cette fonction lit dans le fichier la disposition des ennemis, de personnage et des obstacle. Elle initialise tous les attributs de terrain selon le niveau et
 * génère aléatoirement le loot des ennemis.
 * @param terNum (int) l'entier qui sera concaténé à "ter" pour ouvrir le fichier terrain correspondant
*/
        void initTerrain(int const terNum);
/**
 * @brief Une alternative d'initTerrain adaptée aux niveaux de boss.
 */
        void initTerrainBoss(int const terNum);
/**
 * @brief Fonction servant à initialiser le Jeu, créant l'objet Graphisme servant à gérer SDL, appelant initTerrain pour initialiser le premier terrain et démarrant
 * le jeu. Le terrain initialisé est choisi aléatoirement mis à part pour les niveaux de boss.
 */
        void InitJeu();
/**
 * @brief Fonction chargeant un nouveau terrain (avec initTerrain) une fois que le terrain courant a été passé.
 */
        void loadNewTerrain();
/**
 * @brief Fonction réinitialisant le jeu après une mort ou une victoire.
 */
        void resetJeu();
};


#endif
