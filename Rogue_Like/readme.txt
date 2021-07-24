Etudiants : - NOUVEL Alexandre (p1710464) forge : NOUVEL ALEXANDRE p1710464
	    	- JUSTIN Gabriel (p1920022) forge : JUSTIN GABRIEL p1920022
	    	- BERNOT Camille (p1908800) forge : BERNOT CAMILLE p1908800

##### COMPILATION
Le projet doit être compilé avec CodeBlocks. Pour cela, ouvrir CodeBlocks, sélectionner "open an existing project" puis choisir le fichier Projet.cbp à la racine du projet. Une fois cela fait, sélectionner l'option "build" dans la barre d'outil.


##### EXECUTION
Après la compilation, l'exécution doit se faire via codeblocks pour éviter une erreur liée à SDL. Il faut donc, une fois le projet ouvert sur CodeBlocks et le code compilé sélectionner l'option "Run" pour lancer l'exécutable.


##### ORGANISATION DE L'ARCHIVE :
* p1908800_p1920022_p1710464 : Répertoire principal,. Il s'y trouve le Projet CodeBlocks, le Readme.txt ainsi que les sous-répertoires détaillés plus bas.

* assets : Contiens les sous-dossiers "img" et "terrains" contenant respectivement les images utilisées par l'affichage SDL avec l'extension .bmp, et les differents terrains stockés sous la forme de fichiers sans extension, à l'exception de ter1Lisible qui est un fichier exemple permettant de comprendre le fonctionnement des fichiers terrains.

* bin : Répertoire contenant l'executables du projet, dans le sous-répertoire Debug. Le répertoire et son sous-répertoire ne sont pas dans l'archive de base mais sont créés à la compilation.

* obj : Répertoire contenant les fichiers objets (.o) dans le sous-répertoire src du sous-répertoire Debug. Le répertoire et ses sous-répertoires ne sont pas dans l'archive de base mais sont créés à la compilation.

* doc : Emplacement de la documentation générée par Doxygen, index.html ouvre la page d'accueil de la documentation. image.doxy donne la configuration de doxygen. On y trouve aussi le diagramme de classe ainsi que le diagramme de Gantt du projet.

* include : Dossier contenant tout les .h de la librairie SDL.

* lib : Librairie locale de SDL pour pouvoir compiler sans avoir SDL d'installé sur une machine.

* src : Emplacement des fichiers sources : les headers (.h) et le code (.cpp) des differentes classes ainsi que le main.

* Projet.cbp : Projet CodeBlocks.


##### FONCTIONNEMENT DU JEU :

Le jeu est un Rogue Like dont le but est de finir tout les étages d'un donjon (à savoir 50 dans notre cas) en partant de l'etage 1. Pour passer à l'étage suivant, il faut vaincre tous les ennemis du niveau pour faire apparaître la porte de sortie et arriver au niveau suivant.

Pour vous aider dans votre progression, les ennemis pourront vous donner, à leur mort des potions (des petites régénérant 30 pv, des moyennes regénérant 60 pv et des grandes régénérant 90 pv) ainsi que de l'équipement dont la puissance est définie par son "tier" allant de 0 pour les équipements de départ à 3 (une épée, améliorant votre attaque ou une armure, réduisant les dégats subis et augmentant vos points de vie).

Vos points de vie, vos potions, le tier de votre équipement et l'étage auquel vous vous trouvez sont indiqués dans l'interface en bas de la fenêtre d'affichage à l'aide d'icône les représentant.

Tout les 5 niveaux, vous rencontrerez un boss qui rendra votre progression dans le donjon plus difficile. Le boss est plus resistant et inflige plus de dégats qu'un ennemi normal. De plus, il brûle le sol derrière lui, ce qui vous infligera des dégats si vous marchez sur les cases brûlées par le boss.

Les ennemis deviendront plus résistants, plus puissants et plus rapides au fil de votre partie donc utilisez vos potions avec parcimonie. La partie se termine après avoir vaincu le boss du 50ème étage et avoir passé la porte de sortie ou lorsque vos points de vie tombent à 0.

Les differentes commandes sont :
- zqsd : pour se déplacer.
- espace : pour attaquer.
- 1, 2, 3 : utiliser les differentes potions (petite, moyenne, grande)
- escape : pour quitter l'application.
- r : pour redemarrer une partie après une victoire ou après la mort de votre personnage.

Pour faciliter la démonstration du jeu, des commandes de "triche" ont été ajoutées :
- appuyer 3 fois de suite sur "+" vous fera passer automatiquement au niveau suivant.
- appuyer 3 fois de suite sur "-" vous équipera d'une arme et d'une armure de tier 3 et vous donnera 20 potions de chaque type.