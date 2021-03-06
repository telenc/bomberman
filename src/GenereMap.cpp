/*
// Random.cpp for Random.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 17:53:20 2014 dedicker remi
// Last update Sun Jun 15 19:47:18 2014 Remi telenczak
*/

#include	<iostream>
#include	<vector>
#include	<ctime>
#include	<cstdlib>
#include	"GenereMap.hpp"
#include	"Player.hpp"
#include	"EventManager.hpp"
#include	"DestrucWall.hpp"
#include	"SolWall.hpp"
#include	"IaBomber.hpp"

void	GenereMap::putInside()
{

}

Map	*GenereMap::getMap() const
{
  return this->_map;
}

void	GenereMap::putIa()
{
  int	i;
  int x;
  int y;

  i = 0;
  while (i < _ia )
    {
      if (i == 0)
	this->_map->setIa(new IaBomber( _width * 3 - 6, 0,_height * 3 - 6, this->_map, this->_model, this->_event, _clock));
      else if (i == 1)
	this->_map->setIa(new IaBomber( 3, 0,_height * 3 - 6, this->_map, this->_model, this->_event, _clock));
      else if (i == 2)
	this->_map->setIa(new IaBomber(_width * 3 - 6, 0, 3, this->_map, this->_model, this->_event, _clock));
      else
	{
	  x = 0;
	  y = 0;
	  while (x <= 6 && y <= 6)
	    {
	      x = rand() % (_width * 3 - 9);
	      y = rand() % (_height * 3 - 9);
	      x = x - (x % 3);
	      y = y - (y % 3);
	    }
	  this->_map->setIa(new IaBomber(x, 0, y, this->_map, this->_model, this->_event, _clock));
	}
      i++;
    }
}

void	GenereMap::putWall()
{
  int	i;
  int	y;
  int	wall;
  ABloc	*wallObject;

  i = 0;
  while (i < _width)
    {
      y = 0;
      wall = 0;
      while (y < _height)
	{
	  if (i == 0 || y == 0 || i == (_width - 1) || y == (_height - 1))
	    {
	      wallObject = new DefaultWall(this->_map, this->_model, this->_event, _clock);
	      wallObject->set_x(i * 3);
	      wallObject->set_z(y * 3);
	      this->_map->setBloc(wallObject);
	    }
	  else if (_typeMap == NORMAL && wall == 1 && (y < (_width - 1)) && (i % 2 == 0))
	    {
	      if (_map->hasPlayer(i * 3, y * 3, false) == false)
		{
		  wallObject = new DefaultWall(this->_map, this->_model, this->_event, _clock);
		  wallObject->set_x(i * 3);
		  wallObject->set_z(y * 3);
		  this->_map->setBloc(wallObject);
		}
	      else
		{
		  wallObject = new SolWall(this->_map, _model, _event, _clock);
		  wallObject->set_x(i * 3);
		  wallObject->set_z(y * 3);
		  wallObject->set_y(-3);
		  this->_map->setSol(wallObject);
		}
	      wall = 0;
	    }
	  else
	    {
	      wallObject = new SolWall(this->_map, _model, _event, _clock);
	      wallObject->set_x(i * 3);
	      wallObject->set_z(y * 3);
	      wallObject->set_y(-3);
	      this->_map->setSol(wallObject);
	      wall++;
	    }
	  if (_typeMap == NORMAL && wall != 0 && ((i > 0  && i < _width) || (y > 0 && y < _height) ))
	    {
	      if (_map->hasPlayer(i * 3, y * 3, true) == false)
		{
		  wallObject = new DestrucWall(this->_map, this->_model, this->_event, _clock);
		  wallObject->set_x(i * 3);
		  wallObject->set_z(y * 3);
		  this->_map->setBloc(wallObject);
		}
	    }
	  y++;
	}
      i++;
    }
}

void	GenereMap::putPlayer()
{
  this->_map->setPlayer(new Player(1 * 2, 0, 1 * 2, this->_map, this->_model, this->_event, _clock));
}

GenereMap::GenereMap(int width, int height, int ia, EventManager *event, ModelList *model, gdl::Clock *clock, TypeMap type) : _width(width), _height(height), _ia(ia), _typeMap(type), _event(event), _model(model), _clock(clock)
{
  (void)type;
  _pos = 0;
  _map = new Map(width, height, event, type);
  putIa();
  putPlayer();
  putWall();
}

GenereMap::GenereMap(int width, int height, int ia, EventManager *event, ModelList *model, gdl::Clock *clock) : _width(width), _height(height), _ia(ia), _event(event), _model(model), _clock(clock)
{
  _typeMap = NORMAL;
  _pos = 0;
  _map = new Map(width, height, event);
  putIa();
  putPlayer();
  putWall();
}

GenereMap::~GenereMap()
{
}
