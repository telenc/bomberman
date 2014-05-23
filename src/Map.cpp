//
// map.cpp for map.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 16:02:44 2014 dedicker remi
// Last update Fri May 23 07:54:14 2014 Remi telenczak
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
  std::vector<AObjectPhysic *>::iterator itO;
  std::vector<AObjectPhysic *>::iterator itT;

  itO = this->_map.begin();
  while (itO != this->_map.end())
    {
      //std::cout << "Size map " << this->_map.size() << std::endl;
      //std::cout << "capacity " << this->_map.capacity() << std::endl;
      //std::cout << "max " << this->_map.max_size() << std::endl;
      if ((*itO) != NULL)
	{
	  std::cout <<  "adresse:  "<< *itO <<std::endl;
	  std::cout << "Plahyer :"<< PLAYER << std::endl;
	  std::cout << "Pas null "<< (*itO)->getType() << " adresse:  "<< *itO <<std::endl;
	  if ((*itO)->update(clock, input) == false)
	    {
	      std::cout << "Ca seg ici?"<<std::endl;
	      itO = _map.erase(itO);
	      std::cout << "non" << std::endl;
	    }
	  else
	    itO++;
	}
      else
	itO++;
    }
  //std::cout << this << std::endl;
  this->_player->update(clock, input);
  this->_skybox->update(clock, input);
  //this->refreshDeleteObject();
}

std::vector<AObjectPhysic *>	Map::getObjectsPos(AObjectPhysic *obj)
{
  std::vector<AObjectPhysic *>::iterator itO;
  std::vector<AObjectPhysic *> result;
  glm::vec3	position;

  itO = this->_map.begin();
  while (itO != this->_map.end())
    {
      if ((*itO) != NULL)
	{
	  if ((*itO) != obj)
	    {
	      if (glm::distance2(obj->getPosition(), (*itO)->getPosition()) < 30)
		{
		  result.push_back((*itO));
		}
	    }
	}
      itO++;
    }
  return result;
}

void	Map::refreshDeleteObject()
{
  std::vector<AObjectPhysic *>::iterator it;
  std::vector<AObjectPhysic *>::iterator it2;
  AObjectPhysic *obj;

  it2 = _objectToDelete.begin();
  while (it2 != _objectToDelete.end())
    {
      if ((it = std::find(this->_map.begin(), this->_map.end(), *it2)) != this->_map.end())
	{
	  obj = *it;
	  _map.erase(it);
	  //std::cout << "Size map " << this->_map.size() << std::endl;
	  delete (obj);
	}
      it2++;
    }
  _objectToDelete.clear();


  it2 = _objectToPush.begin();
  while (it2 != _objectToPush.end())
    {
      this->_map.push_back(*it2);
      it2++;
    }
  _objectToPush.clear();
}

void	Map::deleteObject(AObjectPhysic *obj)
{
  //this->_objectToDelete.push_back(obj);
  (void)obj;
}

void	Map::draw(gdl::BasicShader shader, gdl::Clock clock)
{
  std::vector<AObjectPhysic *>::iterator itO;

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

std::vector<AObjectPhysic *> Map::getMap() const
{
  return _map;
}

std::vector<APlayer *> Map::getIa() const
{
  return _ia;
}

void	Map::setMap(int x, int y, AObjectPhysic *bloc)
{
  (void)y;
  (void)x;
  //_map[x][y] = bloc;
  //std::cout << "On set map" << std::endl;
  if (bloc)
    this->_map.push_back(bloc);
  //this->_map2.push_back(bloc);
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

void	Map::setSkybox(Skybox *skybox)
{
  this->_skybox = skybox;
}

void	Map::setPlayer(Player *player)
{
  this->_player = player;
}
