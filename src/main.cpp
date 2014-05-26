//
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Mon May 26 04:08:50 2014 Remi telenczak
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


int	main()
{
  //Menu *menu = new Menu();
  try
    {
      Loader	*load;

      load = new Loader();
      Graphics *engine;
      //ModelList *mod;
      //EventManager *eventManager;
      Controller	*joystick;
      //Sound		*sound;

      //eventManager = new EventManager();
      while (load->getFinish() != true);
      engine = load->getEngine();
      engine->setModelList(load->getModel());
      joystick = load->getController();
      //sound = new Sound(eventManager);
      //engine = new Graphics(eventManager);
      //engine->initialize();
      //mod = new ModelList();
      //engine->setModelList(mod);
      GenereMap gen(21, 21, 0, load->getEventManager(), load->getModel());
      //GenereMap gen(21, 21, 0, eventManager, mod);
      Map *m = gen.getMap();
      //joystick = new Controller(eventManager);
      m->setSkybox(new Skybox(m, load->getModel(), load->getEventManager()));
      //m->setSkybox(new Skybox(m, mod, eventManager));
      load->getSound()->InGame();
      //sound->InGame();
      //(void)menu;
      while (engine->update(m))
	{
	  std::cout << "Draw" << std::endl;;
	  engine->draw(m);
	  joystick->update();
	}
    }
  catch(const myException *e)
    {
      std::cerr << "Error :" << e->what() << std::endl;
    }
  return (0);
}
