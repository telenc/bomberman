//
// APlayer.cpp for APlayer.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman/src
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:11:40 2014 dedicker remi
// Last update Thu May 15 08:54:34 2014 Remi telenczak
//

#include	"APlayer.hpp"

APlayer::APlayer(int x, int y, int z, Map *map, ModelList *model, EventManager *event) : AObjectLife(1), AObjectPhysic(map, model, event)
{

}

APlayer::~APlayer()
{

}

void	APlayer::draw(gdl::AShader &shader, gdl::Clock const &clock)
{

}
