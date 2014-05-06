//
// main.cpp for nibbler in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 07:25:37 2014 telenc_r
// Last update Tue May  6 05:27:53 2014 Remi telenczak
//

#include	<cstdlib>
#include	<cstring>
#include	<exception>
#include	<sstream>
#include	<X11/Xlib.h>
#include	"myException.hpp"
#include	"ALibGraphic.hpp"
#include	"Game.hpp"

Game	*parseArgs(int ac, char **av)
{
  int w;
  int h;
  std::stringstream ss;

  if (ac != 4)
    {
      throw new myException(" args\nUsage : ./nibbler [width] [height] [lib.so]");
    }
  ss << av[1];
  ss >> w;
  ss.clear();
  ss << av[2];
  ss >> h;
  if (w <= 0 || h <= 0)
    throw new myException(" args can't be under or equal to 0");
  else if (w < 20 || h < 20)
    {
      throw new myException(" args need to be : Weight > 20 and Height > 20");
    }
  else if (w > 300 || h > 300)
      throw new myException(" args need to be : Weight < 300 and Height < 300");
  return new Game(w, h, av[3]);
}

void	check_env()
{
  char	*display;

  if ((display = getenv("DISPLAY")) != NULL)
    {
      std::cout << display << std::endl;
    }
  else
    throw new myException("DISPLAY on env don't exist!");
}

int	main(int ac, char **av)
{
  Game	*game;

  try
    {
      check_env();
      game = parseArgs(ac, av);
      if (game == NULL)
	throw new myException("Game is Null");
      game->initLib();
    }
  catch(const myException *e)
    {
      std::cerr << "Error :" << e->what() << std::endl;
    }
  return (0);
}
