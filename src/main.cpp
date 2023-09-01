#include <iostream>
#include "Jeu.h"
#include <cstdlib>   /// -> system("cls"); pour effacer la console


int main(int argc, char** argv)
{
    Jeu * jeuTest= new Jeu();
    srand (time(NULL));
    jeuTest->InitJeu();
    return 0;
}
