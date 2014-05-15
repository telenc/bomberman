//
// map.cpp for map.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 16:02:44 2014 dedicker remi
// Last update Thu May 15 07:39:50 2014 Remi telenczak
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Map.hpp"
#include "Player.hpp"

Map::Map(int width, int height) : _width(width), _height(height)
{
  if (width <= 20 || height <= 20)
    {
      std::cout << "Map trop pitite!" << std::endl;
      exit(0);
    }
  std::cout << "Map Created!" << std::endl;
}

Map::~Map()
{
  std::cout << "Map Destroyed!" << std::endl;
}

void	Map::update()
{

}

std::vector< std::vector<AObjectPhysic *> > Map::getMap() const
{
  return _map;
}

std::vector<Player *> Map::getIa() const
{
  return _ia;
}

void	Map::setMap(int x, int y, AObjectPhysic *bloc)
{
  if (bloc == NULL)
    exit(0);
  _map[x][y] = bloc;
}

AObjectPhysic *Map::getObject(int y, int x) const
{
  return this->_map[y][x];
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
