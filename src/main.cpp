//
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Fri May 16 07:22:13 2014 Remi telenczak
//

#include <iostream>
#include	"Menu.hpp"
#include	"Graphics.hpp"
#include "ModelList.hpp"

int	main()
{
  Menu menu;
  Graphics engine;
  ModelList *mod;

  engine.initialize();
  mod = new ModelList();
  engine.setModelList(mod);
  while (engine.update())
    {
      engine.draw();
    }
  return (0);
}
