//
// defaultWall.cpp for dede in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:26:53 2014 Remi telenczak
// Last update Sun Jun 15 19:38:10 2014 Remi telenczak
//

#include	"DestrucWall.hpp"
#include	"ModelList.hpp"
#include	"PoBonus.hpp"
#include	"BombBonus.hpp"
#include	"BombDownBonus.hpp"
#include	"Map.hpp"

DestrucWall::DestrucWall(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABloc(map, model, event, clock), AObjectLife(3)
{
  int lifeRand = rand() % 10;

  this->modelLife2 = model->getModel("cubeDest2");
  this->modelLife1 = model->getModel("cubeDest1");
  if (lifeRand <= 7)
    this->setLife(1);
  else
    this->setLife(2);
  this->_skin = modelLife2;
  this->currentModel = "cubeDest2";
  this->_height = 3;
  this->_width = 3;
  this->_typePrecis = DESTRUCTWALL;
}

bool DestrucWall::update(gdl::Clock const &clock, gdl::Input &input)
{
  PoBonus	*po;
  BombBonus	*bomb;
  int		v1;

  if (this->_life == 2)
    {
      this->_skin = modelLife2;
      this->currentModel = "cubeDest2";
    }
  else
    {
      this->_skin = modelLife1;
      this->currentModel = "cubeDest1";
    }
  (void)clock;
  (void)input;
  if (this->_life <= 0)
    {
      v1 = rand() % 7;
      if (v1 == 0 || v1 == 2)
	{
	  po = new PoBonus(this->_map, _modelList, _event, _clock);
	  po->set_x(this->getPosition().x);
	  po->set_y(this->getPosition().y);
	  po->set_z(this->getPosition().z);
	  this->_map->setBonus(po);
	}
      else if (v1 == 1 || v1 == 3)
	{
	  bomb = new BombBonus(this->_map, _modelList, _event, _clock);
	  bomb->set_x(this->getPosition().x);
	  bomb->set_y(this->getPosition().y);
	  bomb->set_z(this->getPosition().z);
	  this->_map->setBonus(bomb);
	}
      return false;
    }
  return true;
}

bool	DestrucWall::fireTouch()
{
  this->decLife();
  if (this->_life <= 0)
    return false;
  return true;
}
