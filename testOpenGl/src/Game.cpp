//
// Game.cpp for Game in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 07:26:40 2014 telenc_r
// Last update Sun Apr  6 22:39:05 2014 dedicker remi
//

#include	<dlfcn.h>
#include	<ctype.h>
#include	"Game.hpp"
#include	"myException.hpp"
#include	"ALibGraphic.hpp"
#include	"Snake.hpp"
#include	"ParserXml.hpp"

Game::Game(int w, int h, const std::string path)
{
  this->_w = w;
  this->_h = h;
  this->_path = "./" + path;
  this->_end = 1;
  this->_parser = new ParserXml();
  this->_parser->parseFile();
  this->launchMenu();
}

void	Game::launchGame()
{
  this->_map = new Map(_w, _h, this);
  this->_score = 0;
  this->_scoreMulti = 1;
  this->_sauvScoreMulti = 1;
  this->_speed = 200000;
  this->_currentSpeed = 200000;
  this->_menu = 0;
}

void	Game::launchMenu()
{
  this->_menu = 1;
  this->_speed = 80000;
  this->_currentSpeed = 80000;
}

void	Game::launchHardGame()
{
  int		x;
  int		y;

  this->launchGame();
  this->_scoreMulti = 2;
  this->_sauvScoreMulti = 2;
  y = 4;
  while (y < _map->getHeight())
    {
      x = 4;
      while (x < this->_map->getWidth())
	{
	  this->_map->getTile(y, x)->setType('w');
	  x += 4;
	}
      y += 4;
    }
}

std::list<int>	Game::getScores() const
{
  return this->_parser->getScores();
}

void		Game::addFinalScore(int newScore)
{
  this->_parser->addScore(newScore);
  this->_parser->generateXml();
}

ALibGraphic *Game::getClassLib() const
{
  return this->classLib;
}

int		Game::getMenu() const
{
  return this->_menu;
}

void	Game::initLib()
{
  void	*lib;
  int	loopEnd;
  constructor_graphic_t func_load;

  loopEnd = 1;
  lib = dlopen(this->_path.c_str(), RTLD_LAZY | RTLD_GLOBAL);
  if (lib != NULL)
    {
      func_load = (constructor_graphic_t)(dlsym(lib, "constructor_graphic"));
      if (func_load)
	{
	  this->func_load = func_load;
	  this->classLib = this->func_load(this);
	  while (loopEnd)
	    {
	      if (this->_menu == 0)
		{
		  if (this->getMap()->isAlive())
		    {
		      this->_map->getSnake()->move();
		      this->_map->checkSnake();
		      this->_map->checkEvent();
		    }
		}
	      if (!this->_end)
		{
		  loopEnd = 0;
		}
	      else
		{
		  this->getClassLib()->refresh();
		}
	      usleep(this->_speed);
	    }
	  delete this->classLib;
	}
      dlclose(lib);
    }
  else
    throw new myException(" Loading Librairie");
}

int	Game::getSpeed() const
{
  return _speed;
}

void	Game::setSpeed(int speed)
{
  this->_speed = speed;
}

void	Game::setScore(int score)
{
  this->_score = score;
}

int	Game::getScore() const
{
  return this->_score;
}

void	Game::addScore(int add)
{
  int	i;

  this->_score += (add * _scoreMulti);
  if (this->_score <= 500)
    {
      i = _score / 10;
      this->_speed = 200000 - i * 3900;
      this->_currentSpeed = 200000 - i * 3900;
    }
  if (this->_score >= 100 && this->_score < 1000)
    {
      this->_map->clearRandWall();
      i = _score / 100;
      while (i != 0)
	{
	  this->_map->addWall();
	  i--;
	}
    }
}

int	Game::getScoreMulti()
{
  return this->_scoreMulti;
}

void	Game::setScoreMulti(int score)
{
  this->_scoreMulti = score;
}

void	Game::resetScoreMulti()
{
  this->_scoreMulti = this->_sauvScoreMulti;
}

void	Game::resetSpeed()
{
  this->_speed = _currentSpeed;
}

Map	*Game::getMap() const
{
  return this->_map;
}

int	Game::getEnd() const
{
  return (this->_end);
}

void	Game::setEnd(int nb)
{
  this->_end = nb;
}
