/*
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Fri Jun 13 17:57:30 2014 thomas mendez
// Last update Fri Jun 13 15:56:55 2014 thomas mendez
// Last update Thu Jun 12 14:58:42 2014 Remi telenczak
*/

#include <iostream>
#include	"Menu.hpp"
#include	"Graphics.hpp"
#include "ModelList.hpp"
#include "GenereMap.hpp"
#include "Map.hpp"
#include	"EventManager.hpp"
#include	"Controller.hpp"
#include	"Skybox.hpp"
#include	"Sound.hpp"
#include	"Loader.hpp"
#include	"LoadGame.hpp"
#include	"SaveGame.hpp"
#include	"Game.hpp"

int	main(int ac, char **av)
{
  try
    {
      (void)av;
      (void)ac;
      Game	game;

      while (game.isFinish())
	game.draw();
    }
  catch(const myException *e)
    {
      std::cerr << "Error :" << e->what() << std::endl;
    }
  return (0);
}
