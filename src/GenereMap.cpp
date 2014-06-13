//
// Random.cpp for Random.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 17:53:20 2014 dedicker remi
// Last update Fri Jun 13 17:02:03 2014 Remi telenczak
//

#include	<iostream>
#include	<vector>
#include	<ctime>
#include	<cstdlib>
#include	"GenereMap.hpp"
#include	"Player.hpp"
#include	"EventManager.hpp"
#include	"DestrucWall.hpp"
#include	"SolWall.hpp"
#include	"Ia.hpp"
void	GenereMap::putInside()
{

}

/*
void	GenereMap::putCorner()
{
  switch(_pos)
    {
    case 0:
      _map[1][_height - 3] = 3;
      break;
    case 1:
      _map[_width - 2][1] = 3;
      break;
    case 2:
      _map[_width - 2][_height - 2] = 3;
      break;
    default:
      putInside();
      break;
    }
  _pos++;
  _ia--;
}
*/

Map	*GenereMap::getMap() const
{
  return this->_map;
}

void	GenereMap::putIa()
{
  int	size;

  size = (_height * _width) / 5;
  if (size < _ia)
    std::cout << "Map trop petite par rapport au nombre d'IA" << std::endl;
  else
    std::cout << "Pour les IA: Ok " << size << std::endl;
  /*  while (_ia > 0)
      putCorner();*/
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
	  else if (wall == 1 && (y < (_width - 1)) && (i % 2 == 0))
	    {
	      wallObject = new DefaultWall(this->_map, this->_model, this->_event, _clock);
	      wallObject->set_x(i * 3);
	      wallObject->set_z(y * 3);
	      this->_map->setBloc(wallObject);
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
	  if (wall != 0 && ((i > 2  && i < _width-2) || (y > 2 && y < _height - 3) ))
	    {
	      wallObject = new DestrucWall(this->_map, this->_model, this->_event, _clock);
	      wallObject->set_x(i * 3);
	      wallObject->set_z(y * 3);
	      this->_map->setBloc(wallObject);
	      wallObject = new SolWall(this->_map, _model, _event, _clock);
	      wallObject->set_x(i * 3);
	      wallObject->set_z(y * 3);
	      wallObject->set_y(-3);
	      this->_map->setSol(wallObject);
	    }
	  y++;
	}
      i++;
    }
}

void	GenereMap::putPlayer()
{
  if (this->_event == NULL)
    std::cout << "EVENNVENEVN NUL" << std::endl;
  this->_map->setPlayer(new Player(1 * 2, 0, 1 * 2, this->_map, this->_model, this->_event, _clock));
  this->_map->setIa(new Ia(_width * 3 - 6, 0, 3, this->_map, this->_model, this->_event, _clock));
}

GenereMap::GenereMap(int width, int height, int ia, EventManager *event, ModelList *model, gdl::Clock *clock) : _width(width), _height(height), _ia(ia), _event(event), _model(model), _clock(clock)
{

  _pos = 0;
  std::cout << "Mapp" << std::endl;
  _map = new Map(width, height, event);
  std::cout << "Put player" << std::endl;
  //  std::cout << "Nombre possible d'IA : " << ((width * height) / 5) << std::endl;
  putWall();
  std::cout << "Put wall" << std::endl;
  putPlayer();
  std::cout << "ici" << std::endl;
  //  putIa();
}

GenereMap::~GenereMap()
{
  std::cout << "GenereMap Destroyed!" << std::endl;
}
