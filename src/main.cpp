//
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Thu Jun  5 16:26:13 2014 Steven Martreux
//

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

int	main(int ac, char **av)
{
  try
    {
      Loader	*load = new Loader();
      Graphics *engine;
      Controller	*joystick;
      //LoadGame	*save;

      while (load->getFinish() != true);
      engine = load->getEngine();

      joystick = load->getController();
      GenereMap gen(21, 21, 0, load->getEventManager(), load->getModel(), engine->getClock());
      //Map *m;
      //save = new LoadGame("save/test.xml", load->getEventManager(), load->getModel(), engine->getClock());
      //m = save->getMap();
      Map *m = gen.getMap();
      Menu *menu = new Menu(load->getModel(), load->getEventManager());
      m->setSkybox(new Skybox(m, load->getModel(), load->getEventManager(), engine->getClock()));
      //m->setSkybox(new Skybox(m, mod, eventManager));
      //load->getSound()->InGame();
      //sound->InGame();
      //(void)menu;
      if (ac == 2 && av[1][0] == 'm')
	{
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
	  Skybox *test = new Skybox(m, load->getModel(), load->getEventManager(), engine->getClock());
	  menu->setSkybox(test);
	  load->getSound()->InGame();
	  while (engine->update(menu))
	    {
	      engine->draw(menu);
	      joystick->update();
	    }
	}
    }
  catch(const myException *e)
    {
      std::cerr << "Error :" << e->what() << std::endl;
    }
  return (0);
}
