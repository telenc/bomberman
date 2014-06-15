/*
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
// Last update Sun Jun 15 18:57:38 2014 Remi telenczak
=======
// Last update Sun Jun 15 07:10:28 2014 Steven Martreux
>>>>>>> 2c4c4cadbef375c9030ec89010ba100e149344a4
=======
// Last update Sun Jun 15 12:06:33 2014 Steven Martreux
>>>>>>> 2c520a45a5444d70184b94c02915bf43f88178dd
=======
// Last update Sun Jun 15 18:37:25 2014 Steven Martreux
>>>>>>> 9ee29913410d3ee66aec99ec00e3fc6e6dedb447
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
	  GenereMap gen(41, 41, 0, load->getEventManager(), load->getModel(), engine->getClock(), ZOMBIE);
	  Map *m = gen.getMap();
	  Controller	joystick(load->getEventManager());;
	  m->setSkybox(new Skybox(m, load->getModel(), load->getEventManager(), engine->getClock()));
	  while (engine->update(m))
	    {
	      engine->draw(m);
	      joystick.update();
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
