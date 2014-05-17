//
// map.cpp for map.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 16:02:44 2014 dedicker remi
// Last update Sat May 17 07:04:08 2014 Remi telenczak
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Map.hpp"
#include "Player.hpp"

Map::Map(int width, int height) : _width(width), _height(height)
{
  int	pos;

  pos = 0;
  if (width <= 20 || height <= 20)
    {
      std::cout << "Map trop pitite!" << std::endl;
      exit(0);
    }
  while (pos < height)
    {
      this->_map.push_back(std::vector<AObjectPhysic *>());
      pos++;
    }
}

Map::~Map()
{
  std::cout << "Map Destroyed!" << std::endl;
}

void	Map::update()
{

}

void	Map::draw(gdl::BasicShader shader, gdl::Clock clock)
{
  std::vector<std::vector<AObjectPhysic *> >::iterator itO;
  std::vector<AObjectPhysic *>::iterator itT;

  itO = this->_map.begin();
  while (itO != this->_map.end())
    {
      itT = itO->begin();
      while (itT != itO->end())
	{
	  if ((*itT) != NULL)
	    (*itT)->draw(shader, clock);
	  itT++;
	}
      itO++;
    }
}

std::vector< std::vector<AObjectPhysic *> > Map::getMap() const
{
  return _map;
}

std::vector<APlayer *> Map::getIa() const
{
  return _ia;
}

void	Map::setMap(int x, int y, AObjectPhysic *bloc)
{
  /*  if (bloc == NULL)
      exit(0); */
  std::cout << "SET OK" << std::endl;
  //_map[x][y] = bloc;
  this->_map[x].push_back(bloc);
}

AObjectPhysic *Map::getObject(int x, int y) const
{
  std::cout << _map.size() << std::endl << _map[x].size() << std::endl;
  return this->_map[x][y];
}

int	Map::getWidth() const
{
  return _width;
}

int	Map::getHeight() const
{
  return _height;
}

Player	*Map::getPlayer() const
{
  return this->_player;
}

void	Map::setPlayer(Player *player)
{
  this->_player = player;
}
