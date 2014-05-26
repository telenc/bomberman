//
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Mon May 26 16:30:01 2014 dedicker remi
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
  try
    {
      Loader	*load = new Loader();
      Graphics *engine;
      Controller	*joystick;
      Menu *menu = new Menu();

      while (load->getFinish() != true);
      engine = load->getEngine();
      engine->setModelList(load->getModel());
      joystick = load->getController();
      GenereMap gen(21, 21, 0, load->getEventManager(), load->getModel());
      Map *m = gen.getMap();
      m->setSkybox(new Skybox(m, load->getModel(), load->getEventManager()));
      menu->setSkybox(new Skybox(m, load->getModel(), load->getEventManager()));
      load->getSound()->InGame();
      while (engine->update(menu))
	{
	  std::cout << "Draw" << std::endl;
	  engine->draw(menu);
	  joystick->update();
	}
    }
  catch(const myException *e)
    {
      std::cerr << "Error :" << e->what() << std::endl;
    }
  return (0);
}
