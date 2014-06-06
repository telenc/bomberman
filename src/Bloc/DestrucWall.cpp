//
// defaultWall.cpp for dede in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:26:53 2014 Remi telenczak
// Last update Thu Jun  5 18:19:22 2014 Steven Martreux
//

#include	"DestrucWall.hpp"
#include	"ModelList.hpp"
#include	"PoBonus.hpp"
#include	"BombBonus.hpp"
#include	"Map.hpp"

DestrucWall::DestrucWall(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABloc(map, model, event, clock), AObjectLife(3)
{
  this->modelLife3 = model->getModel("cubeDest3");
  this->modelLife2 = model->getModel("cubeDest2");
  this->modelLife1 = model->getModel("cubeDest1");
  this->_skin = modelLife3;
  this->currentModel = "cubeDest3";
  this->_height = 3;
  this->_width = 3;
  this->_typePrecis = DESTRUCTWALL;
}

bool DestrucWall::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_life >= 3 && this->_life > 0)
    {
      this->_skin = modelLife3;//_modelList->getModel("cubeDest3");
      this->currentModel = "cubeDest3";
    }
  else if (this->_life == 2)
    {
      this->_skin = modelLife2;
      //this->_skin = _modelList->getModel("cubeDest2");
      this->currentModel = "cubeDest2";
    }
  else
    {
      this->_skin = modelLife1;
      //this->_skin = _modelList->getModel("cubeDest1");
      this->currentModel = "cubeDest1";
    }
  (void)clock;
  (void)input;
  if (this->_life <= 0)
    {
      int v1 = rand() % 4;
      if (v1 == 0)
	{
	  PoBonus *po = new PoBonus(this->_map, _modelList, _event, _clock);
	  po->set_x(this->getPosition().x);
	  po->set_y(this->getPosition().y);
	  po->set_z(this->getPosition().z);
	  this->_map->setMap(po);
	}
      if (v1 == 1)
	{
	  BombBonus *po = new BombBonus(this->_map, _modelList, _event, _clock);
	  po->set_x(this->getPosition().x);
	  po->set_y(this->getPosition().y);
	  po->set_z(this->getPosition().z);
	  this->_map->setMap(po);
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
