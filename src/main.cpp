//
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Wed May 14 03:36:28 2014 Remi telenczak
//

#include <iostream>
#include	"Menu.hpp"
#include	"Graphics.hpp"

int	main()
{
  Menu menu;
  Graphics engine;

  engine.initialize();
  std::cout << "Coucouc" << std::endl;
  while (engine.update())
    {
      engine.draw();
    }
  return (0);
}
