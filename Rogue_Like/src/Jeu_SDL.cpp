#include "Jeu_SDL.h"
#include "Terrain.h"
#include <iostream>

void Graphisme::afficherInit(SDL_Window * pWindow, SDL_Renderer *& renderer)
{

    pWindow = SDL_CreateWindow("Rogue Dungeon",SDL_WINDOWPOS_UNDEFINED,
                                                              SDL_WINDOWPOS_UNDEFINED,
                                                              480,
                                                              704,
                                                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Surface * Sol_surf = SDL_LoadBMP("assets/img/solClair2.bmp");
    SDL_Surface * HerosFace_surf = SDL_LoadBMP("assets/img/herosSol.bmp");
    SDL_Surface * HerosGauche_surf = SDL_LoadBMP("assets/img/herosSolGauche.bmp");
    SDL_Surface * HerosDos_surf = SDL_LoadBMP("assets/img/herosBackSol.bmp");
    SDL_Surface * HerosFaceAtt_surf = SDL_LoadBMP("assets/img/herosEpeeSol.bmp");
    SDL_Surface * HerosDosAtt_surf = SDL_LoadBMP("assets/img/herosEpeeDosSol.bmp");
    SDL_Surface * HerosDroiteAtt_surf = SDL_LoadBMP("assets/img/herosEpeeDroiteSol.bmp");
    SDL_Surface * HerosGaucheAtt_surf = SDL_LoadBMP("assets/img/herosEpeeGaucheSol.bmp");
    SDL_Surface * Ennemi_surf = SDL_LoadBMP("assets/img/ennemiSol.bmp");
    SDL_Surface * Mur_surf = SDL_LoadBMP("assets/img/obstacleUnique2.bmp");
    SDL_Surface * Porte_surf = SDL_LoadBMP("assets/img/porte2.bmp");
    SDL_Surface * Armure_surf = SDL_LoadBMP("assets/img/armureSol2.bmp");
    SDL_Surface * Arme_surf = SDL_LoadBMP("assets/img/epeeSol2.bmp");
    SDL_Surface * Potion_surf = SDL_LoadBMP("assets/img/potionSol2.bmp");
    SDL_Surface * Coeur_surf = SDL_LoadBMP("assets/img/coeurNoir.bmp");
    SDL_Surface * Boss_surf = SDL_LoadBMP("assets/img/bossSolRouge.bmp");
    SDL_Surface * SolR_surf = SDL_LoadBMP("assets/img/solRouge.bmp");
    SDL_Surface * Nb_0_surf = SDL_LoadBMP("assets/img/0noir.bmp");
    SDL_Surface * Nb_1_surf = SDL_LoadBMP("assets/img/1noir.bmp");
    SDL_Surface * Nb_2_surf = SDL_LoadBMP("assets/img/2noir.bmp");
    SDL_Surface * Nb_3_surf = SDL_LoadBMP("assets/img/3noir.bmp");
    SDL_Surface * Nb_4_surf = SDL_LoadBMP("assets/img/4noir.bmp");
    SDL_Surface * Nb_5_surf = SDL_LoadBMP("assets/img/5noir.bmp");
    SDL_Surface * Nb_6_surf = SDL_LoadBMP("assets/img/6noir.bmp");
    SDL_Surface * Nb_7_surf = SDL_LoadBMP("assets/img/7noir.bmp");
    SDL_Surface * Nb_8_surf = SDL_LoadBMP("assets/img/8noir.bmp");
    SDL_Surface * Nb_9_surf = SDL_LoadBMP("assets/img/9noir.bmp");
    SDL_Surface * Int_pot_surf = SDL_LoadBMP("assets/img/potionNoir.bmp");
    SDL_Surface * Int_arm_surf = SDL_LoadBMP("assets/img/epeeNoir.bmp");
    SDL_Surface * Int_armu_surf = SDL_LoadBMP("assets/img/armureNoir.bmp");
    SDL_Surface * Fin_Niveau_Surf = SDL_LoadBMP("assets/img/ecranDefaite.bmp");
    SDL_Surface * Fin_Niveau_Victoire_Surf = SDL_LoadBMP("assets/img/ecranVictoire.bmp");
    SDL_Surface * Escalier_surf = SDL_LoadBMP("assets/img/stairs.bmp");

    Sol_text = SDL_CreateTextureFromSurface(renderer, Sol_surf);
    HerosFace_text = SDL_CreateTextureFromSurface(renderer, HerosFace_surf);
    HerosGauche_text = SDL_CreateTextureFromSurface(renderer, HerosGauche_surf);
    HerosDos_text = SDL_CreateTextureFromSurface(renderer, HerosDos_surf);
    HerosFaceAttaque_text = SDL_CreateTextureFromSurface(renderer, HerosFaceAtt_surf);
    HerosDosAttaque_text = SDL_CreateTextureFromSurface(renderer, HerosDosAtt_surf);
    HerosDroiteAttaque_text = SDL_CreateTextureFromSurface(renderer, HerosDroiteAtt_surf);
    HerosGaucheAttaque_text = SDL_CreateTextureFromSurface(renderer, HerosGaucheAtt_surf);
    Ennemi_text = SDL_CreateTextureFromSurface(renderer, Ennemi_surf);
    Mur_text = SDL_CreateTextureFromSurface(renderer, Mur_surf);
    Porte_text = SDL_CreateTextureFromSurface(renderer, Porte_surf);
    Armure_text = SDL_CreateTextureFromSurface(renderer, Armure_surf);
    Arme_text = SDL_CreateTextureFromSurface(renderer, Arme_surf);
    Potion_text = SDL_CreateTextureFromSurface(renderer, Potion_surf);
    Coeur_text = SDL_CreateTextureFromSurface(renderer, Coeur_surf);
    Boss_text = SDL_CreateTextureFromSurface(renderer, Boss_surf);
    SolR_text = SDL_CreateTextureFromSurface(renderer, SolR_surf);
    Nb_0 = SDL_CreateTextureFromSurface(renderer, Nb_0_surf);
    Nb_1 = SDL_CreateTextureFromSurface(renderer, Nb_1_surf);
    Nb_2 = SDL_CreateTextureFromSurface(renderer, Nb_2_surf);
    Nb_3 = SDL_CreateTextureFromSurface(renderer, Nb_3_surf);
    Nb_4 = SDL_CreateTextureFromSurface(renderer, Nb_4_surf);
    Nb_5 = SDL_CreateTextureFromSurface(renderer, Nb_5_surf);
    Nb_6 = SDL_CreateTextureFromSurface(renderer, Nb_6_surf);
    Nb_7 = SDL_CreateTextureFromSurface(renderer, Nb_7_surf);
    Nb_8 = SDL_CreateTextureFromSurface(renderer, Nb_8_surf);
    Nb_9 = SDL_CreateTextureFromSurface(renderer, Nb_9_surf);
    Interface_potion_text = SDL_CreateTextureFromSurface(renderer, Int_pot_surf);
    Interface_arme_text = SDL_CreateTextureFromSurface(renderer, Int_arm_surf);
    Interface_armure_text = SDL_CreateTextureFromSurface(renderer, Int_armu_surf);
    Fin_Niveau_text = SDL_CreateTextureFromSurface(renderer, Fin_Niveau_Surf);
    Fin_Niveau_Victoire_text = SDL_CreateTextureFromSurface(renderer, Fin_Niveau_Victoire_Surf);
    Escalier_text = SDL_CreateTextureFromSurface(renderer, Escalier_surf);

    delete Sol_surf;
    delete HerosFace_surf;
    delete HerosGauche_surf;
    delete HerosDos_surf;
    delete Ennemi_surf;
    delete Mur_surf;
    delete Porte_surf;
    delete Armure_surf;
    delete Arme_surf;
    delete Potion_surf;
    delete Coeur_surf;
    delete Boss_surf;
    delete SolR_surf;
    delete Nb_0_surf;
    delete Nb_1_surf;
    delete Nb_2_surf;
    delete Nb_3_surf;
    delete Nb_4_surf;
    delete Nb_5_surf;
    delete Nb_6_surf;
    delete Nb_7_surf;
    delete Nb_8_surf;
    delete Nb_9_surf;
    delete Int_pot_surf;
    delete Int_arm_surf;
    delete Int_armu_surf;
    delete Fin_Niveau_Surf;
    delete Fin_Niveau_Victoire_Surf;
    delete Escalier_surf;
}

void Graphisme::afficherDetruit(SDL_Window * pWindow, SDL_Renderer * renderer)
{
    SDL_RenderClear(renderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

int Graphisme::afficherBoucle(SDL_Renderer * renderer, Terrain * ter, const int niveau)
{
    int fin=0;
    bool quit = false;
    int cCheat=0;
    int cCheatEquip=0;
    herosAttaque = false;
    porteOuverte=false;
    SDL_Event events;

    while(!quit&&fin==0) {
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT) quit = true;           /// Si l'utilisateur a clique sur la croix de fermeture
            else if (events.type == SDL_KEYDOWN) {              /// Si une touche est enfoncee
                switch (events.key.keysym.scancode) {
                    case SDL_SCANCODE_A:   /// appuye de la toucher Q car c'est du QWERTY
                        if(ter->getHeros()->peutAct())
                            ter->deplacement(113);
                        herosAttaque = false;
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_D:
                        if(ter->getHeros()->peutAct())
                            ter->deplacement(100);
                        herosAttaque = false;
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_W:   /// appuye de la toucher Z car c'est du QWERTY
                        if(ter->getHeros()->peutAct())
                            ter->deplacement(122);
                        herosAttaque = false;
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_S:
                        if(ter->getHeros()->peutAct())
                            ter->deplacement(115);
                        herosAttaque = false;
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_SPACE:
                        if(ter->getHeros()->peutAct())
                        {
                            ter->attaquePersonnage(ter->getHeros());
                            herosAttaque = true;
                        }
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_1:
                        ter->getHeros()->utiliserPotion(0);
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_2:
                        ter->getHeros()->utiliserPotion(1);
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_3:
                        ter->getHeros()->utiliserPotion(2);
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        quit = true;
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_KP_PLUS:
                        cCheat++;
                        if (cCheat==3)
                        {
                            if(niveau==50)
                                return 4;
                            return 100;
                        }
                        cCheatEquip=0;
                        break;
                    case SDL_SCANCODE_KP_MINUS:
                        cCheatEquip++;
                        if (cCheatEquip==3)
                        {
                            Item * armeTier3=new Item('w',3);
                            Item * armureTier3=new Item('a',3);
                            for(int cpt=0;cpt<20;++cpt)
                            {
                                ter->getHeros()->ramasserPotion(0);
                                ter->getHeros()->ramasserPotion(1);
                                ter->getHeros()->ramasserPotion(2);
                            }
                            ter->getHeros()->modifierStats(armeTier3);
                            ter->getHeros()->modifierStats(armureTier3);
                            delete armeTier3;
                            delete armureTier3;
                        }
                        cCheat=0;
                        break;
                    default:
                        cCheat=0;
                        cCheatEquip=0;
                        break;
                }
            }
        }
        if(porteOuverte&&ter->getHeros()->getPosX()==7&&ter->getHeros()->getPosY()==0)
        {
            fin=1;
        }
        if(porteOuverte&&ter->getHeros()->getPosX()==7&&ter->getHeros()->getPosY()==0&&niveau==50)
        {
            fin=4;
        }
        afficher(renderer, ter, niveau);
        if(niveau%5==0)
        {
            if(ter->deplacementBoss())
                fin=2;
            else if(!ter->getHeros()->getVivant())//on v�rifie si le h�ros est mort en marchant sur le sol rouge
                fin=2;
        }
        else
        {
            if(ter->deplacementEnnemi())
                fin=2;
        }
        /// ter->gettab() pour recuperer le tableau
    }
    return fin;
}

bool Graphisme::afficherFinJeu(SDL_Renderer * renderer)
{
    SDL_Rect pos = {80, 88, 320, 469};
    SDL_Rect dest = {64, 672, 32, 32};
    SDL_RenderCopy(renderer, Fin_Niveau_text, NULL, &pos);
    SDL_RenderCopy(renderer, Nb_0, NULL, &dest);
    dest.x +=32;
    SDL_RenderCopy(renderer, Nb_0, NULL, &dest);
    SDL_RenderPresent(renderer);
    char input;
    int fin=0;
    bool quit = false;
    SDL_Event events;

    while(!quit&&fin==0) {
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT) quit = true;           /// Si l'utilisateur a clique sur la croix de fermeture
            else if (events.type == SDL_KEYDOWN) {              /// Si une touche est enfoncee
                switch (events.key.keysym.scancode) {
                    case SDL_SCANCODE_R:
                        input = 'r';
                        quit = true;
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        input = 'a';
                        quit = true;
                    default: break;
                }
            }
        }
    }
    return input=='r';
}

bool Graphisme::afficherFinJeuVictoire(SDL_Renderer * renderer)
{
    SDL_Rect pos = {80, 88, 320, 469};
    SDL_RenderCopy(renderer, Fin_Niveau_Victoire_text, NULL, &pos);
    SDL_RenderPresent(renderer);
    char input;
    int fin=0;
    bool quit = false;
    SDL_Event events;

    while(!quit&&fin==0) {
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT) quit = true;           /// Si l'utilisateur a clique sur la croix de fermeture
            else if (events.type == SDL_KEYDOWN) {              /// Si une touche est enfoncee
                switch (events.key.keysym.scancode) {
                    case SDL_SCANCODE_R:
                        input = 'r';
                        quit = true;
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        input = 'a';
                        quit = true;
                    default: break;
                }
            }
        }
    }
    return input=='r';
}

void Graphisme::afficher(SDL_Renderer * renderer, Terrain * ter, const int niveau)
{
  SDL_Rect dest;
  char curTab;
  int i;
  int j;
  int largeur = ter->getLargeur();
  int hauteur = ter->getHauteur();
  SDL_Rect pos;
  pos = {0, 672, 32, 32};

  SDL_RenderClear(renderer);

  for(i = 0; i < hauteur*largeur; i++)
  {
      dest = {(i%largeur)*32,(i/largeur)*32,32,32};
      curTab=ter->getTab()[i];
      switch(curTab)
      {
        case 'o':
            Text_actu = Mur_text;
            break;
        case 'v':
            Text_actu = Sol_text;
            break;
        case 'E':
            if(niveau%5==0)
            {
                Text_actu = Boss_text;
            }
            else
            {
                Text_actu = Ennemi_text;
            }
            break;
        case 'P':
            if(herosAttaque)
            {
                if(ter->getHeros()->getOrientation() == 'h')
                {
                    Text_actu = HerosDosAttaque_text;
                }
                else if(ter->getHeros()->getOrientation() == 'b')
                {
                    Text_actu = HerosFaceAttaque_text;
                }
                else if(ter->getHeros()->getOrientation() == 'd')
                {
                    Text_actu = HerosDroiteAttaque_text;
                }
                else if(ter->getHeros()->getOrientation() == 'g')
                {
                    Text_actu = HerosGaucheAttaque_text;
                }
            }
            else if(ter->getHeros()->getOrientation() == 'h')
            {
                Text_actu = HerosDos_text;
            }
            else if(ter->getHeros()->getOrientation() == 'g')
            {
                Text_actu = HerosGauche_text;
            }
            else
            {
                Text_actu = HerosFace_text;
            }
            break;
        case 'S':
            Text_actu = Porte_text;
            porteOuverte=true;
            break;
        case 's':
        case 'm':
        case 'l':
            Text_actu=Potion_text;
            break;
        case 'w':
            Text_actu=Arme_text;
            break;
        case 'a':
            Text_actu=Armure_text;
            break;
        case 'r':
            Text_actu=SolR_text;
        default:
            break;
      }
      SDL_RenderCopy(renderer, Text_actu, NULL, &dest);
  }
  SDL_RenderCopy(renderer, Coeur_text, NULL, &pos);
      pos.x +=32;
      if(ter->getHeros()->getVie()/100 == 1)
        Text_actu = Nb_1;
      else if(ter->getHeros()->getVie()/100 == 2)
        Text_actu = Nb_2;
      else
        Text_actu = Nb_0;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      if((ter->getHeros()->getVie()%100)/10 == 0)
        Text_actu = Nb_0;
      else if((ter->getHeros()->getVie()%100)/10 == 1)
        Text_actu = Nb_1;
      else if((ter->getHeros()->getVie()%100)/10 == 2)
        Text_actu = Nb_2;
      else if((ter->getHeros()->getVie()%100)/10 == 3)
        Text_actu = Nb_3;
      else if((ter->getHeros()->getVie()%100)/10 == 4)
        Text_actu = Nb_4;
      else if((ter->getHeros()->getVie()%100)/10 == 5)
        Text_actu = Nb_5;
      else if((ter->getHeros()->getVie()%100)/10 == 6)
        Text_actu = Nb_6;
      else if((ter->getHeros()->getVie()%100)/10 == 7)
        Text_actu = Nb_7;
      else if((ter->getHeros()->getVie()%100)/10 == 8)
        Text_actu = Nb_8;
      else if((ter->getHeros()->getVie()%100)/10 == 9)
        Text_actu = Nb_9;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      if(ter->getHeros()->getVie()%10 == 0)
        Text_actu = Nb_0;
      else if(ter->getHeros()->getVie()%10 == 1)
        Text_actu = Nb_1;
      else if(ter->getHeros()->getVie()%100 == 2)
        Text_actu = Nb_2;
      else if(ter->getHeros()->getVie()%10 == 3)
        Text_actu = Nb_3;
      else if(ter->getHeros()->getVie()%10 == 4)
        Text_actu = Nb_4;
      else if(ter->getHeros()->getVie()%10 == 5)
        Text_actu = Nb_5;
      else if(ter->getHeros()->getVie()%10 == 6)
        Text_actu = Nb_6;
      else if(ter->getHeros()->getVie()%10 == 7)
        Text_actu = Nb_7;
      else if(ter->getHeros()->getVie()%10 == 8)
        Text_actu = Nb_8;
      else if(ter->getHeros()->getVie()%10 == 9)
        Text_actu = Nb_9;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      SDL_RenderCopy(renderer, Interface_potion_text, NULL, &pos);
      pos.x += 32;

      if(ter->getHeros()->getPotions()[0] == 0)
        Text_actu = Nb_0;
      else if(ter->getHeros()->getPotions()[0] == 1)
        Text_actu = Nb_1;
      else if(ter->getHeros()->getPotions()[0] == 2)
        Text_actu = Nb_2;
      else if(ter->getHeros()->getPotions()[0] == 3)
        Text_actu = Nb_3;
      else if(ter->getHeros()->getPotions()[0] == 4)
        Text_actu = Nb_4;
      else if(ter->getHeros()->getPotions()[0] == 5)
        Text_actu = Nb_5;
      else if(ter->getHeros()->getPotions()[0] == 6)
        Text_actu = Nb_6;
      else if(ter->getHeros()->getPotions()[0] == 7)
        Text_actu = Nb_7;
      else if(ter->getHeros()->getPotions()[0] == 8)
        Text_actu = Nb_8;
      else if(ter->getHeros()->getPotions()[0] >= 9)
        Text_actu = Nb_9;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      if(ter->getHeros()->getPotions()[1] == 0)
        Text_actu = Nb_0;
      else if(ter->getHeros()->getPotions()[1] == 1)
        Text_actu = Nb_1;
      else if(ter->getHeros()->getPotions()[1] == 2)
        Text_actu = Nb_2;
      else if(ter->getHeros()->getPotions()[1] == 3)
        Text_actu = Nb_3;
      else if(ter->getHeros()->getPotions()[1] == 4)
        Text_actu = Nb_4;
      else if(ter->getHeros()->getPotions()[1] == 5)
        Text_actu = Nb_5;
      else if(ter->getHeros()->getPotions()[1] == 6)
        Text_actu = Nb_6;
      else if(ter->getHeros()->getPotions()[1] == 7)
        Text_actu = Nb_7;
      else if(ter->getHeros()->getPotions()[1] == 8)
        Text_actu = Nb_8;
      else if(ter->getHeros()->getPotions()[1] >= 9)
        Text_actu = Nb_9;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      if(ter->getHeros()->getPotions()[2] == 0)
        Text_actu = Nb_0;
      else if(ter->getHeros()->getPotions()[2] == 1)
        Text_actu = Nb_1;
      else if(ter->getHeros()->getPotions()[2] == 2)
        Text_actu = Nb_2;
      else if(ter->getHeros()->getPotions()[2] == 3)
        Text_actu = Nb_3;
      else if(ter->getHeros()->getPotions()[2] == 4)
        Text_actu = Nb_4;
      else if(ter->getHeros()->getPotions()[2] == 5)
        Text_actu = Nb_5;
      else if(ter->getHeros()->getPotions()[2] == 6)
        Text_actu = Nb_6;
      else if(ter->getHeros()->getPotions()[2] == 7)
        Text_actu = Nb_7;
      else if(ter->getHeros()->getPotions()[2] == 8)
        Text_actu = Nb_8;
      else if(ter->getHeros()->getPotions()[2] >= 9)
        Text_actu = Nb_9;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      SDL_RenderCopy(renderer, Interface_arme_text, NULL, &pos);
      pos.x += 32;

      if(ter->getHeros()->getItems()[0].getTier() == 0)
        Text_actu = Nb_0;
      else if(ter->getHeros()->getItems()[0].getTier() == 1)
        Text_actu = Nb_1;
      else if(ter->getHeros()->getItems()[0].getTier() == 2)
        Text_actu = Nb_2;
      else if(ter->getHeros()->getItems()[0].getTier() == 3)
        Text_actu = Nb_3;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      SDL_RenderCopy(renderer, Interface_armure_text, NULL, &pos);
      pos.x += 32;

      if(ter->getHeros()->getItems()[1].getTier() == 0)
        Text_actu = Nb_0;
      else if(ter->getHeros()->getItems()[1].getTier() == 1)
        Text_actu = Nb_1;
      else if(ter->getHeros()->getItems()[1].getTier() == 2)
        Text_actu = Nb_2;
      else if(ter->getHeros()->getItems()[1].getTier() == 3)
        Text_actu = Nb_3;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      SDL_RenderCopy(renderer, Escalier_text, NULL, &pos);
      pos.x += 32;

      if(niveau/10 == 0)
        Text_actu = Nb_0;
      else if(niveau/10 == 1)
        Text_actu = Nb_1;
      else if(niveau/10 == 2)
        Text_actu = Nb_2;
      else if(niveau/10 == 3)
        Text_actu = Nb_3;
      else if(niveau/10 == 4)
        Text_actu = Nb_4;
      else if(niveau/10 == 5)
        Text_actu = Nb_5;
      else if(niveau/10 == 6)
        Text_actu = Nb_6;
      else if(niveau/10 == 7)
        Text_actu = Nb_7;
      else if(niveau/10 == 8)
        Text_actu = Nb_8;
      else if(niveau/10 == 9)
        Text_actu = Nb_9;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      if(niveau%10 == 0)
        Text_actu = Nb_0;
      else if(niveau%10 == 1)
        Text_actu = Nb_1;
      else if(niveau%10 == 2)
        Text_actu = Nb_2;
      else if(niveau%10 == 3)
        Text_actu = Nb_3;
      else if(niveau%10 == 4)
        Text_actu = Nb_4;
      else if(niveau%10 == 5)
        Text_actu = Nb_5;
      else if(niveau%10 == 6)
        Text_actu = Nb_6;
      else if(niveau%10 == 7)
        Text_actu = Nb_7;
      else if(niveau%10 == 8)
        Text_actu = Nb_8;
      else if(niveau%10 == 9)
        Text_actu = Nb_9;
      SDL_RenderCopy(renderer, Text_actu, NULL, &pos);
      pos.x += 32;

      pos.x = 0;
  SDL_RenderPresent(renderer);
}
