/*
// main.cpp for main in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 04:21:54 2014 Remi telenczak
// Last update Sun Jun 15 22:05:48 2014 thomas mendez
*/

#include <iostream>
#include	"Game.hpp"

int	main(int ac, char **av)
{
  (void)ac;
  (void)av;
  try
    {
      Game	game;

      while (game.isFinish())
	game.draw();
    }
  catch(const myException *e)
    {
      std::cerr << "Error :" << e->what() << std::endl;
    }
  return (0);
}
