//
// Player.cpp for Player.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman/src
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:27:38 2014 dedicker remi
// Last update Fri May 16 13:48:57 2014 Remi telenczak
//

#include "Player.hpp"


Player::Player(int x, int y, int z, Map *map, ModelList *model, EventManager *event) : APlayer(x, y, z, map, model, event)
{
  std::cout << "Player Created" << std::endl;
}

void Player::update(gdl::Clock const &clock, gdl::Input &input)
{
  std::cout << "Update Player" << std::endl;
}

Player::~Player()
{
  std::cout << "Player Destroyed" << std::endl;
}
