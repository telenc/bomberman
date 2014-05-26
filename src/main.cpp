//
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
<<<<<<< HEAD
// Last update Mon May 26 05:54:07 2014 Remi telenczak
=======
// Last update Mon May 26 17:28:18 2014 dedicker remi
>>>>>>> 86fd066f3cca2a094e91194976398fe97236bc1e
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

      while (load->getFinish() != true);
      engine = load->getEngine();

      joystick = load->getController();
      GenereMap gen(21, 21, 0, load->getEventManager(), load->getModel());
      Map *m = gen.getMap();
      Menu *menu = new Menu(load->getModel(), load->getEventManager());
      m->setSkybox(new Skybox(m, load->getModel(), load->getEventManager()));
<<<<<<< HEAD
      //m->setSkybox(new Skybox(m, mod, eventManager));
      //load->getSound()->InGame();
      //sound->InGame();
      //(void)menu;
      while (engine->update(m))
	{
	  engine->draw(m);
=======
      menu->setSkybox(new Skybox(m, load->getModel(), load->getEventManager()));
      menu->setBox();
      load->getSound()->InGame();
      while (engine->update(menu))
	{
	  std::cout << "Draw" << std::endl;
	  engine->draw(menu);
>>>>>>> 86fd066f3cca2a094e91194976398fe97236bc1e
	  joystick->update();
	}
    }
  catch(const myException *e)
    {
      std::cerr << "Error :" << e->what() << std::endl;
    }
  return (0);
}
