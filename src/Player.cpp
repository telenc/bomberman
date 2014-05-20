//
// Player.cpp for Player.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman/src
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:27:38 2014 dedicker remi
// Last update Tue May 20 07:34:30 2014 Remi telenczak
//

#include "Player.hpp"
#include	"EventManager.hpp"

Player::Player(int x, int y, int z, Map *map, ModelList *model, EventManager *event) : APlayer(x, y, z, map, model, event)
{
  std::cout << "Player Created" << std::endl;
  this->rotate(glm::vec3(0, 1, 0), 180);
  if (event == NULL)
    {
      std::cout << "Event null" << std::endl;
      exit(0);
    }
  //callPosPlayer = new CallBack<Player>(this, &Player::eventPosPlayer);
  //_event->listenEvent("posPlayer", callPosPlayer);
  callKeyUp = new CallBack<Player>(this, &Player::eventKeyUp);
  event->listenEvent("keyUp", callKeyUp);
  callKeyLeft = new CallBack<Player>(this, &Player::eventKeyLeft);
  event->listenEvent("keyLeft", callKeyLeft);
  callKeyRight = new CallBack<Player>(this, &Player::eventKeyRight);
  event->listenEvent("keyRight", callKeyRight);
  callKeyDown = new CallBack<Player>(this, &Player::eventKeyDown);
  event->listenEvent("keyDown", callKeyDown);
  callRotateLeft = new CallBack<Player>(this, &Player::eventRotateLeft);
  event->listenEvent("rotateLeft", callRotateLeft);
  callRotateRight = new CallBack<Player>(this, &Player::eventRotateRight);
  event->listenEvent("rotateRight", callRotateRight);
}


void	Player::eventRotateLeft(void *data)
{
  // this->rotation.y -= 5;
  this->rotate(glm::vec3(0, 1, 0), -5);
  this->_event->dispatchEvent("playerRotateLeft", this);
}

void	Player::eventRotateRight(void *data)
{
  //this->rotation.y += 5;
  this->rotate(glm::vec3(0, 1, 0), 5);
  this->_event->dispatchEvent("playerRotateRight", this);
}

void	Player::eventKeyUp(void *data)
{
  this->translate(glm::vec3(0, 0, -0.5));
  this->_event->dispatchEvent("playerUp", this);
}

void	Player::eventKeyDown(void *data)
{
  this->translate(glm::vec3(0, 0, 0.5));
  this->_event->dispatchEvent("playerDown", this);
}

void	Player::eventKeyRight(void *data)
{
  this->translate(glm::vec3(0.5, 0, 0));
  this->_event->dispatchEvent("playerRight", this);
}

void	Player::eventKeyLeft(void *data)
{
  this->translate(glm::vec3(-0.5, 0, 0));
  this->_event->dispatchEvent("playerLeft", this);
}



void Player::update(gdl::Clock const &clock, gdl::Input &input)
{
  std::cout << "Update Player" << std::endl;
}

Player::~Player()
{
  std::cout << "Player Destroyed" << std::endl;
}
