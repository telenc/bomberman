/*
** test.cpp for test in /home/bernar_x/Tech2/Projets/cpp_bomberman/AllTest/testOpenGl
** 
** Made by mattieu bernard-guêle
** Login <bernar_x@epitech.eu>
** 
** Started on  Fri May  9 14:37:04 2014 mattieu bernard-guêle
** Last update Fri May  9 14:37:06 2014 mattieu bernard-guêle
*/

#include <SDL2/SDL.h>
#include <iostream>


int main(int argc, char **argv)
{
  // Notre fenêtre
  
  SDL_Window* fenetre(0);
  SDL_Event evenements;
  bool terminer(false);
  
  
  // Initialisation de la SDL_Event
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
      SDL_Quit();
      
      return -1;
    }
  
  
  // Création de la fenêtre
  fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

  if(fenetre == 0)
    {
      std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
      SDL_Quit();

      return -1;
    }
  
  
  // Boucle principale
  
  while(!terminer)
    {
      SDL_WaitEvent(&evenements);
      
      if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
	terminer = true;
    }
  
  
  // On quitte la SDL_WINDOWEVENT_CLOSE
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
  
  return 0;
}
