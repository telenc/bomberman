//
// Player.cpp for Player.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman/src
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:27:38 2014 dedicker remi
// Last update Tue May 20 10:34:41 2014 Remi telenczak
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
  (void)data;
  // this->rotation.y -= 5;
  this->rotate(glm::vec3(0, 1, 0), -5);
  this->_event->dispatchEvent("playerRotateLeft", this);
}

void	Player::eventRotateRight(void *data)
{
  (void)data;
  //this->rotation.y += 5;
  this->rotate(glm::vec3(0, 1, 0), 5);
  this->_event->dispatchEvent("playerRotateRight", this);
}

bool	Player::checkPositionCollision()
{
  std::vector<AObjectPhysic *>	objects;
  std::vector<AObjectPhysic *>::iterator	it;

  objects = this->_map->getObjectsPos(this);
  it = objects.begin();
  while (it != objects.end())
    {
      if (this->collision(*it) == true)
	{
	  //this->_position = posSauv;
	  return false;
	}
      it++;
    }
  return true;
}

void Player::move(glm::vec3 direct, std::string event)
{
  glm::vec3	posSauv;
  glm::vec3	positionTrans;

  posSauv = this->_position;
  positionTrans = this->translate(direct);
  if (checkPositionCollision() == false)
    {
      this->_position.x -= positionTrans.x;
      if (checkPositionCollision() == false)
	{
	  this->_position.x += positionTrans.x;
	  this->_position.z -= positionTrans.z;
	  if (checkPositionCollision() == false)
	    {
	      this->_position = posSauv;
	    }
	  else
	    {
	      positionTrans.z = 0;
	      this->_event->dispatchEvent(event, &positionTrans);
	    }
	}
      else
	{
	  positionTrans.x = 0;
	  this->_event->dispatchEvent(event, &positionTrans);
	}
    }
  else
    this->_event->dispatchEvent(event, &positionTrans);
}

void	Player::eventKeyUp(void *data)
{
  (void)data;
  this->move(glm::vec3(0, 0, -0.5), "playerUp");
}

void	Player::eventKeyDown(void *data)
{
    (void)data;
  this->move(glm::vec3(0, 0, 0.5), "playerDown");
  //this->translate(glm::vec3(0, 0, 0.5));
  //this->_event->dispatchEvent("playerDown", this);
}

void	Player::eventKeyRight(void *data)
{
    (void)data;
    this->move(glm::vec3(0.5, 0, 0), "playerRight");
    //this->translate(glm::vec3(0.5, 0, 0));
    //this->_event->dispatchEvent("playerRight", this);
}

void	Player::eventKeyLeft(void *data)
{
  (void)data;
    this->move(glm::vec3(-0.5, 0, 0), "playerLeft");
    //  this->translate(glm::vec3(-0.5, 0, 0));
    //this->_event->dispatchEvent("playerLeft", this);
}

void Player::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
  std::cout << "Update Player" << std::endl;
}

Player::~Player()
{
  std::cout << "Player Destroyed" << std::endl;
}
