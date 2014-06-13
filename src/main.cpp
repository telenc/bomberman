/*
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Fri Jun 13 17:43:22 2014 dedicker remi
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
#include	<stdlib.h>

int	main(int ac, char **av)
{
  try
    {
      /*      if (getenv("DISPLAY") == NULL)
	      throw new myException("Where is env ?");
	      Loader	*load = new Loader();
	      Graphics *engine;
	      Controller	*joystick;
	      //LoadGame	*save;

      
	      while (load->getFinish() != true);
	      engine = load->getEngine();

	      joystick = load->getController();
	      //Map *m;
	      //save = new LoadGame("save/test.xml", load->getEventManager(), load->getModel(), engine->getClock());
	      //m = save->getMap();
	      Menu *menu = new Menu(load->getModel(), load->getEventManager(), engine->getClock());

	      //m->setSkybox(new Skybox(m, mod, eventManager));
	      //load->getSound()->InGame();
	      //sound->InGame();
	      //(void)menu;
	      //LoadGame *charge = new LoadGame("test.xml", load->getEventManager(), load->getModel(), engine->getClock());
	      if (ac == 2 && av[1][0] == 'm')
	      {
	      GenereMap gen(21, 21, 0, load->getEventManager(), load->getModel(), engine->getClock());
	      Map *m = gen.getMap();//charge->getMap();//gen.getMap();
	      m->setSkybox(new Skybox(m, load->getModel(), load->getEventManager(), engine->getClock()));
	      //(void)charge;
	      while (engine->update(m))
	      {
	      engine->draw(m);
	      joystick->update();
	      }
	      SaveGame *test;
	      test = new SaveGame(m, "test.xml");
	      (void)test;
	      }
	      else
	      {
	      Skybox *test = new Skybox(NULL, load->getModel(), load->getEventManager(), engine->getClock());
	      menu->setSkybox(test);
	      load->getSound()->InGame();
	      while (engine->update(menu))
	      {
	      //m->setSkybox(new Skybox(m, mod, eventManager));
	      load->getSound()->InGame();
	      //sound->InGame();
	      //(void)menu;
	      if (ac == 2 && av[1][0] == 'm')
	      {
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
	      Skybox *test = new Skybox(NULL, load->getModel(), load->getEventManager(), engine->getClock());
	      menu->setSkybox(test);
	      load->getSound()->InGame();
	      while (engine->update(menu))
	      {
	      engine->draw(menu);
	      joystick->update();
	      }
	      }
	      (void)av;
	      (void)ac;
	      Game	game;

	      while (game.isFinish())
	      game.draw();
	      {
	      Skybox *test = new Skybox(NULL, load->getModel(), load->getEventManager(), engine->getClock());
	      menu->setSkybox(test);
	      load->getSound()->InGame();
	      while (engine->update(menu))
	      {
	      engine->draw(menu);
	      joystick->update();
	      }
	      }*/
      (void)av;
      (void)ac;
	      
      Game	game;

      while (game.isFinish())
	game.draw();
      //    }
      //}
    }
  catch(const myException *e)
    {
      std::cerr << "Error :" << e->what() << std::endl;
    }
  return (0);
}
