//
// Random.cpp for Random.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 17:53:20 2014 dedicker remi
// Last update Tue May 27 03:07:57 2014 Remi telenczak
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
	      this->_map->setMap(wallObject);
	      wallObject = new DefaultWall(this->_map, this->_model, this->_event, _clock);
	      wallObject->set_x(i * 3);
	      wallObject->set_z(y * 3);
	      wallObject->set_y(3);
	      this->_map->setMap(wallObject);
	    }
	  else if (wall == 1 && (y < (_width - 1)) && (i % 2 == 0))
	    {
	      wallObject = new DefaultWall(this->_map, this->_model, this->_event, _clock);
	      wallObject->set_x(i * 3);
	      wallObject->set_z(y * 3);
	      this->_map->setMap(wallObject);
	      wall = 0;
	    }
	  else
	      wall++;
	  if (wall != 0 && ((i > 2  && i < _width-2) || (y > 2 && y < _height - 3) ))
	    {
	      std::cout << "i = " << i  * 3<< "  y =" << y * 3<< std::endl;
	      std::cout << "width  = " << _width *3 << "  height =" << _height *3<< std::endl;
	      wallObject = new DestrucWall(this->_map, this->_model, this->_event, _clock);
	      wallObject->set_x(i * 3);
	      wallObject->set_z(y * 3);
	      this->_map->setMap(wallObject);
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
}

GenereMap::GenereMap(int width, int height, int ia, EventManager *event, ModelList *model, gdl::Clock *clock) : _width(width), _height(height), _ia(ia), _event(event), _model(model), _clock(clock)
{

  _pos = 0;
  _map = new Map(width, height);
  //  std::cout << "Nombre possible d'IA : " << ((width * height) / 5) << std::endl;
  putWall();
  putPlayer();
  std::cout << "ici" << std::endl;
  //  putIa();
}

GenereMap::~GenereMap()
{
  std::cout << "GenereMap Destroyed!" << std::endl;
}
