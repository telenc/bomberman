/*
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Sun Jun 15 05:54:07 2014 Steven Martreux
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
      if (ac == 2)
	{
	  Loader	*load = new Loader();
	  Graphics *engine;
	  //LoadGame	*save;
	  while (load->getFinish() != true);
	  engine = load->getEngine();

	  //save = new LoadGame("save/test.xml", load->getEventManager(), load->getModel(), engine->getClock());
	  //m = save->getMap();
	  GenereMap gen(21, 21, 0, load->getEventManager(), load->getModel(), engine->getClock());
	  Map *m = gen.getMap();
	  m->setSkybox(new Skybox(m, load->getModel(), load->getEventManager(), engine->getClock()));
	  while (engine->update(m))
	    {
	      engine->draw(m);
	    }
	  SaveGame *test;
	  test = new SaveGame(m, "test.xml");
	  (void)test;
	}
      else
	{
	  Game	game;
	  
	  while (game.isFinish())
	    game.draw();
	}
    }
  catch(const myException *e)
    {
      std::cerr << "Error :" << e->what() << std::endl;
    }
  return (0);
}
