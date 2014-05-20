//
// APlayer.cpp for APlayer.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman/src
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:11:40 2014 dedicker remi
// Last update Tue May 20 10:11:55 2014 Remi telenczak
//

#include	"APlayer.hpp"


//Player
// x /y /z = la base en bas
//height 3.33
//width 1
//depth 1
APlayer::APlayer(int x, int y, int z, Map *map, ModelList *model, EventManager *event) : AObjectLife(1), AObjectPhysic(map, model, event)
{
  this->_skin = model->getModel("marvin");
  this->_skin->setCurrentAnim(0);
  //this->translate(glm::vec3(3,0,0));
  this->scale(glm::vec3(0.005, 0.005, 0.005));
  this->_position.x = 2;
  this->_position.y = 0;
  this->_position.z = 2;
  (void)y;
  (void)x;
  (void)z;

}

APlayer::~APlayer()
{

}
