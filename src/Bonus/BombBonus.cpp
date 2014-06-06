//
// BombBonus.cpp for BombBonus in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 30 04:40:51 2014 Remi telenczak
// Last update Tue Jun  3 16:11:22 2014 Steven Martreux
//

#include	"BombBonus.hpp"
#include	"ModelList.hpp"
#include	"Map.hpp"
#include	"APlayer.hpp"

BombBonus::BombBonus(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABonus(map, model, event, clock)
{
  this->_skin = model->getModel("bombBonus");
  this->_skin->setCurrentAnim(0, false);
  this->scale(glm::vec3(0.04, 0.04, 0.04));
  this->_typePrecis = BOMBBONUS;
}

bool	BombBonus::update(gdl::Clock const &clock, gdl::Input &input)
{
  float b = 5 * static_cast<float>(_clock->getElapsed()) * 10.f;
  this->rotate(glm::vec3(0, 1, 0), b);
  (void)clock;
  (void)input;

  std::vector<APlayer *>	players;
  std::vector<APlayer *>::iterator it;

  if (this->_died == true)
    return false;
  players = this->_map->getPlayers();
  it = players.begin();
  while (it != players.end())
    {
      if (this->collision(*it) == true)
	{
	  (*it)->incNbrBombMax();
	  return false;
	}
      it++;
    }
  return true;
}

BombBonus::~BombBonus()
{
}
