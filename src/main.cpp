//
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Thu May 22 07:32:37 2014 Remi telenczak
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
int	main()
{
  Menu menu;
  Graphics *engine;
  ModelList *mod;
  EventManager *eventManager;
  Controller	*joystick;

  eventManager = new EventManager();
  engine = new Graphics(eventManager);
  engine->initialize();
  mod = new ModelList();
  engine->setModelList(mod);
  GenereMap gen(21, 21, 0, eventManager, mod);
  Map *m = gen.getMap();
  joystick = new Controller(eventManager);
  m->setSkybox(new Skybox(m, mod, eventManager));
  while (engine->update(m))
    {
      engine->draw(m);
      joystick->update();
    }
  return (0);
}
