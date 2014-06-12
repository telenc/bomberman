//
// map.cpp for map.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 16:02:44 2014 dedicker remi
// Last update Thu Jun 12 14:59:40 2014 Remi telenczak
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Map.hpp"
#include "Player.hpp"
#include "Skybox.hpp"
#include	"EventManager.hpp"
#include	<GL/freeglut.h>
#include	"drawtext.h"
#include	"ABomb.hpp"
#include	"ABonus.hpp"
#include	"AFire.hpp"

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

}

Map::~Map()
{
  std::cout << "Map Destroyed!" << std::endl;
}

void	Map::updateBomb(gdl::Clock clock, gdl::Input input)
{
  std::list<ABomb *>::iterator itO;

  itO = this->_bombs.begin();
  while (itO != this->_bombs.end())
    {
      if ((*itO) != NULL)
	{
	  if ((*itO)->update(clock, input) == false)
	    itO = _bombs.erase(itO);
	  else
	    itO++;
	}
      else
	itO++;
    }
}

void	Map::updateBloc(gdl::Clock clock, gdl::Input input)
{
  std::list<ABloc *>::iterator itO;

  itO = this->_blocs.begin();
  while (itO != this->_blocs.end())
    {
      if ((*itO) != NULL)
	{
	  if ((*itO)->update(clock, input) == false)
	    itO = _blocs.erase(itO);
	  else
	    itO++;
	}
      else
	itO++;
    }
}

void	Map::updateBonus(gdl::Clock clock, gdl::Input input)
{
  std::list<ABonus *>::iterator itO;

  itO = this->_bonus.begin();
  while (itO != this->_bonus.end())
    {
      if ((*itO) != NULL)
	{
	  if ((*itO)->update(clock, input) == false)
	    itO = _bonus.erase(itO);
	  else
	    itO++;
	}
      else
	itO++;
    }
}

void	Map::updateFire(gdl::Clock clock, gdl::Input input)
{
  std::list<AFire *>::iterator itO;

  itO = this->_fire.begin();
  while (itO != this->_fire.end())
    {
      if ((*itO) != NULL)
	{
	  if ((*itO)->update(clock, input) == false)
	    itO = _fire.erase(itO);
	  else
	    itO++;
	}
      else
	itO++;
    }
}

std::list<ABomb *>	Map::getBombs() const
{
  return this->_bombs;
}

std::list<ABloc *>	Map::getBloc() const
{
  return this->_blocs;
}

std::list<ABonus *>	Map::getBonus() const
{
  return this->_bonus;
}

std::list<AFire *>	Map::getFire() const
{
  return this->_fire;
}

bool	Map::isBlock(int x, int z)
{
  std::list<ABloc *>::iterator itO;

  itO = this->_blocs.begin();
  while (itO != this->_blocs.end())
    {
      if ((*itO) != NULL && (*itO)->getType() == BLOC)
	{
	  if ((*itO)->get_x() == x && (*itO)->get_z() == z)
	    return true;
	}
      itO++;
    }
  return false;
}

void	Map::update(gdl::Clock clock, gdl::Input input)
{
  if (this->_pause == true)
    return;
  this->updateBloc(clock, input);
  this->updateBomb(clock, input);
  this->updateBonus(clock, input);
  this->updateFire(clock, input);
  this->_player->update(clock, input);
  this->_skybox->update(clock, input);
}

void	Map::eventCallPause(void *data)
{
  if (this->_pause == true)
      this->_pause = false;
  else
    this->_pause = true;
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

std::list<AObjectPhysic *>		Map::getAllObject()
{
  std::list<AObjectPhysic *>		result;
  std::list<ABloc *>::iterator		blocs;
  std::list<ABomb *>::iterator		bombs;
  std::list<ABonus *>::iterator		bonus;
  std::list<AFire *>::iterator		fire;

  blocs = _blocs.begin();
  while (blocs != _blocs.end())
    {
      result.push_back(*blocs);
      blocs ++;
    }
  bombs = _bombs.begin();
  while (bombs != _bombs.end())
    {
      result.push_back(*bombs);
      bombs ++;
    }
  bonus = _bonus.begin();
  while (bonus != _bonus.end())
    {
      result.push_back(*bonus);
      bonus ++;
    }
  fire = _fire.begin();
  while (fire != _fire.end())
    {
      result.push_back(*fire);
      fire ++;
    }
  return result;
}

std::vector<AObjectPhysic *>		Map::getObjectsPos(AObjectPhysic *obj)
{
  std::list<AObjectPhysic *>::iterator	itO;
  std::vector<AObjectPhysic *>		result;
  glm::vec3				position;
  std::list<AObjectPhysic *>	_map;

  _map = this->getAllObject();
  itO = _map.begin();
  while (itO != _map.end())
    {
      if ((*itO) != NULL)
	if ((*itO) != obj)
	  {
	  if (glm::distance2(obj->getPosition(), (*itO)->getPosition()) < 30)
	    result.push_back((*itO));
	  }
      itO++;
    }
  return result;
}

void		Map::drawBomb(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<ABomb *>::iterator	itO;

  itO = this->_bombs.begin();
  while (itO != this->_bombs.end())
    {
      if (this->_pause == true)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && (*itO)->isInView(camera) && this->distanceObj(*itO) < 400)
	(*itO)->draw(shader, clock);
      itO++;
    }
}

void		Map::drawFire(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<AFire *>::iterator	itO;

  itO = this->_fire.begin();
  while (itO != this->_fire.end())
    {
      if (this->_pause == true)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && (*itO)->isInView(camera) && this->distanceObj(*itO) < 400)
	(*itO)->draw(shader, clock);
      itO++;
    }
}

void		Map::drawBloc(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<ABloc *>::iterator	itO;

  itO = this->_blocs.begin();
  while (itO != this->_blocs.end())
    {
      if (this->_pause == true)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && (*itO)->isInView(camera) && this->distanceObj(*itO) < 400)
	(*itO)->draw(shader, clock);
      itO++;
    }
}

void		Map::drawBonus(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<ABonus *>::iterator	itO;

  itO = this->_bonus.begin();
  while (itO != this->_bonus.end())
    {
      if (this->_pause == true)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && (*itO)->isInView(camera) && this->distanceObj(*itO) < 400)
	(*itO)->draw(shader, clock);
      itO++;
    }
}

void					Map::draw(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{

  this->drawBloc(shader, clock, camera);
  this->drawBomb(shader, clock, camera);
  this->drawBonus(shader, clock, camera);
  this->drawFire(shader, clock, camera);
  this->_player->draw(shader, clock);
  this->_skybox->draw(shader, clock);
  (void)shader;
  (void)clock;
  (void)camera;
}

std::vector<APlayer *>		Map::getIa() const
{
  return _ia;
}

void				Map::setBloc(ABloc *bloc)
{
  if (bloc)
    this->_blocs.push_back(bloc);
}

void				Map::setBomb(ABomb *bloc)
{
  if (bloc)
    this->_bombs.push_back(bloc);
}

void				Map::setBonus(ABonus *bloc)
{
  if (bloc)
    this->_bonus.push_back(bloc);
}

void				Map::setFire(AFire *bloc)
{
  if (bloc)
    this->_fire.push_back(bloc);
}

int				Map::getWidth() const
{
  return _width;
}

int				Map::getHeight() const
{
  return _height;
}

Player				*Map::getPlayer() const
{
  return this->_player;
}

std::list<AObjectPhysic *>	Map::getObject()
{
  return this->getAllObject();
}

std::vector<APlayer *>		Map::getPlayers()
{
  std::vector<APlayer *>	result;

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
