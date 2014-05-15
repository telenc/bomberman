//
// map.cpp for map.cpp in /home/dedick_r/Bomberman
// 
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
// 
// Started on  Wed May  7 16:02:44 2014 dedicker remi
// Last update Wed May 14 15:35:09 2014 dedicker remi
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Map.hpp"

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
    exit();
  _map[x][y] = bloc;
}

ObjectPhysic *Map::getObject(int y, int x) const
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
