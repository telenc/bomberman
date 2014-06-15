//
// BombBonus.cpp for BombBonus in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 30 04:40:51 2014 Remi telenczak
// Last update Sun Jun 15 20:04:05 2014 Remi telenczak
//

#include	"BombDownBonus.hpp"
#include	"ModelList.hpp"
#include	"Map.hpp"
#include	"APlayer.hpp"

BombDownBonus::BombDownBonus(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABonus(map, model, event, clock)
{
  this->_skin = model->getModel("bombDownBonus");
  this->scale(glm::vec3(0.04, 0.04, 0.04));
  this->_typePrecis = BOMBBONUS;
}

bool					BombDownBonus::update(gdl::Clock const &clock, gdl::Input &input)
{
  std::vector<APlayer *>		players;
  std::vector<APlayer *>::iterator	it;
  float					b;

  b = 5 * static_cast<float>(_clock->getElapsed()) * 10.f;
  this->rotate(glm::vec3(0, 1, 0), b);
  if (this->_died == true)
    return false;
  players = this->_map->getPlayers();
  it = players.begin();
  while (it != players.end())
    {
      if (this->collision(*it) == true)
	{
	  (*it)->decNbrBombMax();
	  return false;
	}
      it++;
    }
  return true;
  (void)clock;
  (void)input;
}

BombDownBonus::~BombDownBonus()
{
}
