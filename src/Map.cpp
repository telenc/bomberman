//
// map.cpp for map.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 16:02:44 2014 dedicker remi
// Last update Tue Jun 10 15:00:10 2014 Remi telenczak
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Map.hpp"
#include "Player.hpp"
#include "Skybox.hpp"
#include	"EventManager.hpp"
#include	<GL/freeglut.h>
Map::Map(int width, int height, EventManager *event) : _width(width), _height(height), _event(event), _pause(false)
{
  glm::vec2	size;

  if (width <= 20 || height <= 20)
    {
      std::cout << "Map trop pitite!" << std::endl;
      exit(0);
    }
  callPause = new CallBack<Map>(this, &Map::eventCallPause);
  event->listenEvent("pause", callPause);
  size.x = width;
  size.y = height;
  event->dispatchEvent("newMap", &size);
  if (text.load("./assets/aplha.tga") == false)
    {
      std::cout << "Eroor"<<std::endl;
    }
}

Map::~Map()
{
  std::cout << "Map Destroyed!" << std::endl;
}

void	Map::update(gdl::Clock clock, gdl::Input input)
{
  std::list<AObjectPhysic *>::iterator itO;

  if (this->_pause == true)
    return;
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

void	Map::testTexture()
{
  glDisable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1280, 800, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  text.bind();
  glBegin(GL_QUADS);
  glTexCoord2f(.0f,.0f); glVertex2d(0, 0);
  glTexCoord2f(.11f,.0f); glVertex2d(100, 0);
  glTexCoord2f(.11f,.3f); glVertex2d(100, 100);
  glTexCoord2f(.0f,.3f); glVertex2d(0, 100);
  glEnd();
  std::cout <<"DRAW" <<std::endl;

  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

void	Map::eventCallPause(void *data)
{
  if (this->_pause == true)
    {
      std::cout << "false" << std::endl;
      this->_pause = false;
    }
  else
    {
    this->_pause = true;
    std::cout << "true" << std::endl;
    }
  (void)data;
}

bool	Map::isPause()
{
  return this->_pause;
}

int	Map::distanceObj(AObjectPhysic *obj)
{
  return glm::distance2(obj->getPosition(), this->_player->getPosition());
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

void	Map::draw(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<AObjectPhysic *>::iterator itO;

  itO = this->_map.begin();
  while (itO != this->_map.end())
    {
      if (this->_pause == true)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && (*itO)->isInView(camera) && this->distanceObj(*itO) < 400)
	(*itO)->draw(shader, clock);
      itO++;
    }
  (void)camera;
  this->_player->draw(shader, clock);
  this->_skybox->draw(shader, clock);
  testTexture();
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

std::list<AObjectPhysic *> Map::getObject() const
{
  return this->_map;
}

std::vector<APlayer *> Map::getPlayers()
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
