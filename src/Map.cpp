//
// map.cpp for map.cpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 16:02:44 2014 dedicker remi
// Last update Sun Jun 15 22:01:59 2014 thomas mendez
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Map.hpp"
#include "Player.hpp"
#include "Skybox.hpp"
#include	"EventManager.hpp"
#include	<GL/freeglut.h>
#include	"ABomb.hpp"
#include	"ABonus.hpp"
#include	"AFire.hpp"
#include	"IaBomber.hpp"
#include	"PoBonus.hpp"
#include	"BombBonus.hpp"

Map::Map(int width, int height, EventManager *event) : _width(width), _height(height), _event(event), _pause(false), _select(false)
{
  glm::vec2	size;

  callPause = new CallBack<Map>(this, &Map::eventCallPause);
  event->listenEvent("pause", callPause);
  size.x = width;
  size.y = height;
  event->dispatchEvent("newMap", &size);
  callSelect = new CallBack<Map>(this, &Map::eventCallSelect);
  event->listenEvent("select", callSelect);
  _typeMap = NORMAL;
}

Map::Map(int width, int height, EventManager *event, TypeMap type) : _width(width), _height(height), _event(event), _pause(false), _typeMap(type)
{
  glm::vec2	size;

  this->vague = 0;
  this->nbrZombie = 5;
  this->vagueFini = true;
  this->nbrZomb = 0;
  xZomb = 6;
  yZomb =  6;
  time(&_timeVague);
  callPause = new CallBack<Map>(this, &Map::eventCallPause);
  event->listenEvent("pause", callPause);
  size.x = width;
  size.y = height;
  event->dispatchEvent("newMap", &size);
  callSelect = new CallBack<Map>(this, &Map::eventCallSelect);
  event->listenEvent("select", callSelect);
}

void    Map::setSelect(bool select)
{
  _select = select;
}

bool    Map::getSelect() const
{
  return _select;
}

void    Map::eventCallSelect(void *data)
{
  (void)data;
  _select = true;
  std::cout << "Select Detected" << std::endl;
}


Map::~Map()
{
  std::cout << "Map Destroyed!" << std::endl;
}

TypeMap		Map::getTypeMap() const
{
  return this->_typeMap;
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

void	Map::updateIa(gdl::Clock clock, gdl::Input input)
{
  std::list<IaBomber *>::iterator itO;

  itO = this->_ia.begin();
  while (itO != this->_ia.end())
    {
      if ((*itO) != NULL)
	{
	  if ((*itO)->update(clock, input) == false)
	    itO = _ia.erase(itO);
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

void				Map::updateBonus(gdl::Clock clock, gdl::Input input)
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

void				Map::updateFire(gdl::Clock clock, gdl::Input input)
{
  std::list<AFire *>::iterator	itO;

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

bool				Map::isFire(int x, int z)
{
  std::list<AFire *>::iterator	itO;

  itO = this->_fire.begin();
  while (itO != this->_fire.end())
    {
      if ((*itO) != NULL)
	{
	  if ((*itO)->get_x() == x && (*itO)->get_z() == z)
	    return true;
	}
      itO++;
    }
  return false;
}

bool				Map::isBlock(int x, int z, bool bomb)
{
  std::list<ABloc *>::iterator	 itO;
  std::list<ABomb *>::iterator itB;

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
  if (bomb)
    {
      itB = this->_bombs.begin();
      while (itB != this->_bombs.end())
	{
	  if ((*itB) != NULL)
	    {
	      if ((*itB)->get_x() == x && (*itB)->get_z() == z)
		return true;
	    }
	  itB++;
	}
    }
  return false;
}

bool	Map::isFinish()
{
  if (this->_typeMap == NORMAL && _ia.size() == 0)
    return true;
  if (_player->getLife() == 0)
    return true;
  return false;
}

void					Map::updateZombie(gdl::Clock clock, gdl::Input input)
{
  time_t				curTime;
  std::list<IaBomber *>::iterator	itO;
  int					i;
  int					x;
  int					y;
  int					type;
  APlayer				*play;

  (void)clock;
  (void)input;
  y = 0;
  if (nbrZomb > 0)
    {
      this->setIa(new IaBomber(xZomb, 0, yZomb, this, _player->getModelList(), this->_event, &clock));
      xZomb += 3;
      if (yZomb != 6 && yZomb < 39 * 3)
	{
	  yZomb += 3;
	  xZomb = 6;
	}
      if (xZomb > 39 * 3)
	{
	  if (yZomb > 39 * 3)
	    {
	      xZomb = 6;
	      yZomb = 6;
	    }
	  else
	    {
	      yZomb += 3;
	      xZomb = 6;
	    }
	}
      nbrZomb -= 1;
    }
  if (vagueFini == true)
    {
      time(&curTime);
      if (difftime(curTime, _timeVague) > 2)
	{
	  i = 0;
	  xZomb = 6;
	  yZomb = 6;
	  nbrZomb = nbrZombie;
	  vagueFini = false;
	}
    }
  else
    {
      if (nbrZomb == 0 && this->_ia.size() == 0)
	{
	  this->nbrZombie += 5;
	  if (this->nbrZombie > 25)
	    this->nbrZombie = 25;
	  this->vague += 1;
	  this->vagueFini = true;
	  time(&_timeVague);
	  i = 0;
	  while (i < 20)
	    {
	      x = rand() % 35 + 2;
	      x *= 3;
	      y = rand() % 35 + 2;
	      y *= 3;
	      type = rand() % 2;
	      if (type == 1)
		{
		  PoBonus *po = new PoBonus(this, _player->getModelList(), this->_event, &clock);
		  po->set_x(x);
		  po->set_y(0);
		  po->set_z(y);
		  this->setBonus(po);
		}
	      else
		{
		  BombBonus *poo = new BombBonus(this, _player->getModelList(), this->_event, &clock);
		  poo->set_x(x);
		  poo->set_y(0);
		  poo->set_z(y);
		  this->setBonus(poo);
		}
	      i++;
	    }
	}
      else
	{
	  itO = this->_ia.begin();
	  while (itO != this->_ia.end())
	    {
	      if (this->_player->collision((*itO)) == true)
		{
		  play = *itO;

		  itO = _ia.erase(itO);
		  delete play;
		  this->_player->decLife();
		}
	      itO++;
	    }

	}
    }
}

void	Map::update(gdl::Clock clock, gdl::Input input)
{
  if (this->_pause == true)
    return;
  if (this->_typeMap == ZOMBIE)
    updateZombie(clock, input);
  this->updateBloc(clock, input);
  this->updateBomb(clock, input);
  this->updateBonus(clock, input);
  this->updateFire(clock, input);
  this->updateIa(clock, input);
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

int	Map::distanceObj(AObjectPhysic *obj, AObjectPhysic *obj2)
{
  return glm::distance2(obj->getPosition(), obj2->getPosition());
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

std::vector<AObjectPhysic *>		Map::getObjectsPos(AObjectPhysic *obj, int dist, TypeObject type)
{
  std::list<AObjectPhysic *>::iterator	itO;
  std::vector<AObjectPhysic *>		result;
  glm::vec3				position;
  std::list<AObjectPhysic *>		_map;

  _map = this->getAllObject();
  itO = _map.begin();
  while (itO != _map.end())
    {
      if ((*itO) != NULL)
	if ((*itO) != obj)
	  {
	  if (glm::distance2(obj->getPosition(), (*itO)->getPosition()) < dist)
	    if (type == NONE || obj->getType() == type)
	      result.push_back((*itO));
	  }
      itO++;
    }
  return result;
}


std::vector<AObjectPhysic *>		Map::getObjectsPrecisPos(AObjectPhysic *obj, int dist, TypeObjectPrecis type)
{
  std::list<AObjectPhysic *>::iterator	itO;
  std::vector<AObjectPhysic *>		result;
  glm::vec3				position;
  std::list<AObjectPhysic *>		_map;

  _map = this->getAllObject();
  itO = _map.begin();
  while (itO != _map.end())
    {
      if ((*itO) != NULL)
	if ((*itO) != obj)
	  if (glm::distance2(obj->getPosition(), (*itO)->getPosition()) < dist)
	    if (type == NONEPRECIS || (*itO)->getTypePrecis() == type)
	      result.push_back((*itO));
      itO++;
    }
  return result;
}

std::vector<AObjectPhysic *>		Map::getObjectsList(AObjectPhysic *obj, int dist, std::list<AObjectPhysic *> list)
{
  std::list<AObjectPhysic *>::iterator	itO;
  std::vector<AObjectPhysic *>		result;
  glm::vec3				position;


  itO = list.begin();
  while (itO != list.end())
    {
      if ((*itO) != NULL)
	if ((*itO) != obj)
	  {
	    if (glm::distance2(obj->getPosition(), (*itO)->getPosition()) < dist)
	      {
		if ((*itO)->getTypePrecis() == DESTRUCTWALL)
		  {
		    result.push_back((*itO));
		  }
	      }
	  }
      itO++;
    }
  return result;
}

void			Map::drawBomb(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<ABomb *>::iterator	itO;

  itO = this->_bombs.begin();
  while (itO != this->_bombs.end())
    {
      if (this->_pause == true && glm::distance2(glm::vec3(camera->getPositionPause().x,0, camera->getPositionPause().z), (*itO)->getPosition()) < 600)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && (*itO)->isInView(camera) && this->distanceObj(*itO) < 400)
	(*itO)->draw(shader, clock);
      itO++;
    }
}

void				Map::drawSol(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<ABloc *>::iterator	itO;

  itO = this->_sol.begin();
  while (itO != this->_sol.end())
    {
      if (this->_pause == true && glm::distance2(glm::vec3(camera->getPositionPause().x,0, camera->getPositionPause().z), (*itO)->getPosition()) < 600)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && this->distanceObj(*itO) < 400)
	(*itO)->draw(shader, clock);
      itO++;
    }
}

void				Map::drawFire(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<AFire *>::iterator	itO;

  itO = this->_fire.begin();
  while (itO != this->_fire.end())
    {
      if (this->_pause == true && glm::distance2(glm::vec3(camera->getPositionPause().x,0, camera->getPositionPause().z), (*itO)->getPosition()) < 600)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && (*itO)->isInView(camera) && this->distanceObj(*itO) < 400)
	(*itO)->draw(shader, clock);
      itO++;
    }
}

void					Map::drawIa(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<IaBomber *>::iterator	itO;

  itO = this->_ia.begin();
  while (itO != this->_ia.end())
    {
      (void)camera;
      if (this->_pause == true && glm::distance2(glm::vec3(camera->getPositionPause().x,0, camera->getPositionPause().z), (*itO)->getPosition()) < 600)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && this->distanceObj(*itO) < 800)
	(*itO)->draw(shader, clock);
      itO++;
    }
}

void				Map::drawBloc(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<ABloc *>::iterator	itO;

  itO = this->_blocs.begin();
  while (itO != this->_blocs.end())
    {
      if (this->_pause == true && glm::distance2(glm::vec3(camera->getPositionPause().x,0, camera->getPositionPause().z), (*itO)->getPosition()) < 600)
	(*itO)->draw(shader, clock);
      else if ((*itO) != NULL && (*itO)->isInView(camera) && this->distanceObj(*itO) < 400)
	(*itO)->draw(shader, clock);
      itO++;
    }
}

void				Map::drawBonus(gdl::BasicShader shader, gdl::Clock clock, CameraBomber *camera)
{
  std::list<ABonus *>::iterator	itO;

  itO = this->_bonus.begin();
  while (itO != this->_bonus.end())
    {
      if (this->_pause == true && glm::distance2(glm::vec3(camera->getPositionPause().x,0, camera->getPositionPause().z), (*itO)->getPosition()) < 600)
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
  this->drawIa(shader, clock, camera);
  this->drawSol(shader, clock, camera);
  this->_player->draw(shader, clock);
  this->_skybox->draw(shader, clock);
  (void)shader;
  (void)clock;
  (void)camera;
}

bool					Map::hasPlayer(int x, int y, bool autour)
{
  std::vector<APlayer *>		list;
  std::vector<APlayer *>::iterator	itO;
  int					xObj;
  int					yObj;

  list = this->getPlayers();
  itO = list.begin();
  while (itO != list.end())
    {
      if ((*itO) != NULL)
	{
	  if ((*itO)->get_x() == x && (*itO)->get_z() == y)
	    return true;
	  else if (autour)
	    {
	      xObj = (*itO)->get_x();
	      yObj = (*itO)->get_z();
	      if (std::max(x, xObj) - std::min(x, xObj) <= 6)
		{
		  if (y == yObj)
		    return true;
		  else if (std::max(y, yObj) - std::min(y, yObj) <= 6)
		    return true;
		}
	      if (std::max(y, yObj) - std::min(y, yObj) <= 6)
		{
		  if (x == xObj)
		    return true;
		  else if (std::max(x, xObj) - std::min(x, xObj) <= 6)
		    return true;
		}
	    }
	}
      itO++;
    }
  return false;
}

std::list<IaBomber *>		Map::getIa() const
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

void				Map::setSol(ABloc *bloc)
{
  if (bloc)
    this->_sol.push_back(bloc);
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

std::list<ABloc *>		Map::getSol() const
{
  return _sol;
}

std::vector<APlayer *>		Map::getPlayers()
{
  std::vector<APlayer *>	result;
  std::list<IaBomber *>::iterator	it;

  result.push_back(this->_player);
  it = _ia.begin();
  while (it != _ia.end())
    {
      result.push_back(*it);
      it++;
    }
  return result;
}

void	Map::setSkybox(Skybox *skybox)
{
  this->_skybox = skybox;
}

void	Map::setPlayer(Player *player)
{
  if (this->getTypeMap() == ZOMBIE)
    player->setLife(10);
  this->_player = player;
}

void	Map::setIa(IaBomber	*ia)
{
  this->_ia.push_back(ia);
}
