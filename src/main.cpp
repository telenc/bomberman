/*
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Sun Jun 15 19:01:33 2014 Steven Martreux
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
	  while (load->getFinish() != true);
	  engine = load->getEngine();

	  GenereMap gen(41, 41, 10, load->getEventManager(), load->getModel(), engine->getClock());
	  Map *m = gen.getMap();
	  Controller	joystick(load->getEventManager());;
	  m->setSkybox(new Skybox(m, load->getModel(), load->getEventManager(), engine->getClock()));
	  while (engine->update(m))
	    {
	      engine->draw(m);
	      joystick.update();
	    }
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
