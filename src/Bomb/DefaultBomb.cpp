//
// DefaultBomb.cpp for defaultbomb in /home/remi/cpp_bomberman/src
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 21 01:36:36 2014 Remi telenczak
// Last update Thu May 22 09:23:32 2014 Remi telenczak
//

#include	"DefaultBomb.hpp"
#include	"ModelList.hpp"
#include	"APlayer.hpp"
DefaultBomb::DefaultBomb(Map *map, ModelList *model, EventManager *event, APlayer *player) : ABomb(map, model, event, player)
{
  this->_skin = _modelList->getModel("defaultBomb");
  this->rotate(glm::vec3(0, 1, 0), 45);
  this->rotate(glm::vec3(1, 0, 0), -25);
  this->rotate(glm::vec3(0, 0, 1), -25);
}

void	DefaultBomb::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->get_scax() >= 1)
    this->_direction = -1;
  else if (this->get_scax() <= 0.5)
    this->_direction = 1;
  this->set_scax(this->get_scax() + (0.05 * this->_direction));
  this->set_scay(this->get_scay() + (0.05 * this->_direction));
  this->set_scaz(this->get_scaz() + (0.05 * this->_direction));
  if (this->_playerColl == false)
    {
      if (this->collision((AObjectPhysic *)this->_player) == false)
	this->_playerColl = true;
    }
  (void)clock;
  (void)input;
}

void	DefaultBomb::createDeflag()
{

}
