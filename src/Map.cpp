//
// map.cpp for map.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 16:02:44 2014 dedicker remi
// Last update Mon May 26 05:00:43 2014 Remi telenczak
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Map.hpp"
#include "Player.hpp"
#include "Skybox.hpp"

Map::Map(int width, int height) : _width(width), _height(height)
{
  if (width <= 20 || height <= 20)
    {
      std::cout << "Map trop pitite!" << std::endl;
      exit(0);
    }
}

Map::~Map()
{
  std::cout << "Map Destroyed!" << std::endl;
}

void	Map::update(gdl::Clock clock, gdl::Input input)
{
  std::list<AObjectPhysic *>::iterator itO;

  itO = this->_map.begin();
  while (itO != this->_map.end())
    {
      if ((*itO) != NULL)
	{
	  if ((*itO)->update(clock, input) == false)
	    itO = _map.erase(itO);
	  else
	    itO++;
	}
      else
	itO++;
    }
  this->_player->update(clock, input);
  this->_skybox->update(clock, input);
}

std::vector<AObjectPhysic *>	Map::getObjectsPos(AObjectPhysic *obj)
{
  std::list<AObjectPhysic *>::iterator itO;
  std::vector<AObjectPhysic *> result;
  glm::vec3	position;

  itO = this->_map.begin();
  while (itO != this->_map.end())
    {
      if ((*itO) != NULL)
	if ((*itO) != obj)
	  if (glm::distance2(obj->getPosition(), (*itO)->getPosition()) < 30)
	    result.push_back((*itO));
      itO++;
    }
  return result;
}

void	Map::draw(gdl::BasicShader shader, gdl::Clock clock)
{
  std::list<AObjectPhysic *>::iterator itO;

  itO = this->_map.begin();
  while (itO != this->_map.end())
    {
      if ((*itO) != NULL)
	(*itO)->draw(shader, clock);
      itO++;
    }
  this->_player->draw(shader, clock);
  this->_skybox->draw(shader, clock);
}

std::vector<APlayer *> Map::getIa() const
{
  return _ia;
}

void	Map::setMap(AObjectPhysic *bloc)
{
  if (bloc)
    this->_map.push_back(bloc);
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

std::vector<APlayer *> Map::getPlayer()
{
  std::vector<APlayer *> result;

  result.push_back(this->_player);
  return result;
}

void	Map::setSkybox(Skybox *skybox)
{
  this->_skybox = skybox;
}

void	Map::setPlayer(Player *player)
{
  this->_player = player;
}
