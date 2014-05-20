//
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Sat May 17 09:17:57 2014 Remi telenczak
//

#include <iostream>
#include	"Menu.hpp"
#include	"Graphics.hpp"
#include "ModelList.hpp"
#include "GenereMap.hpp"
#include "Map.hpp"
#include	"EventManager.hpp"
int	main()
{
  Menu menu;
  Graphics *engine;
  ModelList *mod;
  EventManager *eventManager;

  eventManager = new EventManager();
  engine = new Graphics(eventManager);
  engine->initialize();
  mod = new ModelList();
  engine->setModelList(mod);
  GenereMap gen(21, 21, 0, eventManager, mod);
  Map *m = gen.getMap();
  while (engine->update())
    {
      engine->draw(m);
    }
  return (0);
}
