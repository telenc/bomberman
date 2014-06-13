//
// Player.cpp for Player.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman/src
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:27:38 2014 dedicker remi
// Last update Fri Jun 13 14:09:53 2014 Remi telenczak
//

#include	"Player.hpp"
#include	"EventManager.hpp"
#include	"DefaultBomb.hpp"
#include	<algorithm>

Player::Player(int x, int y, int z, Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : APlayer(x, y, z, map, model, event, clock)
{
  std::cout << "Player Created" << std::endl;
  this->rotate(glm::vec3(0, 1, 0), 180);
  if (event == NULL)
    {
      std::cout << "Event null" << std::endl;
      exit(0);
    }
  callKeyUp = new CallBack<Player>(this, &Player::eventKeyUp);
  event->listenEvent("keyUp", callKeyUp);

  callKeyLeft = new CallBack<Player>(this, &Player::eventKeyLeft);
  event->listenEvent("keyLeft", callKeyLeft);

  callKeyRight = new CallBack<Player>(this, &Player::eventKeyRight);
  event->listenEvent("keyRight", callKeyRight);

  callKeyDown = new CallBack<Player>(this, &Player::eventKeyDown);
  event->listenEvent("keyDown", callKeyDown);

  callRotate = new CallBack<Player>(this, &Player::eventRotate);
  event->listenEvent("occulusRotate", callRotate);

  callKeyA = new CallBack<Player>(this, &Player::eventKeyA);
  event->listenEvent("keyA", callKeyA);

  this->none = true;
  this->checkRun = false;
  this->_typePrecis = PLAYERPRECIS;
}


void	Player::eventRotateLeft(void *data)
{
  (void)data;
  if (this->_map->isPause() == true)
    return;
  this->rotate(glm::vec3(0, 1, 0), -5);
  this->_event->dispatchEvent("playerRotateLeft", this);
}

void	Player::eventKeyA(void *data)
{
  (void)data;
  DefaultBomb	*bomb;
  int		x;
  int		z;

  if (this->_map->isPause() == true)
    return ;
  if (this->_nbrBomb <= 0)
    return ;
  if (this->checkPositionCollision(BOMB) != NULL)
    return ;
  this->_nbrBomb--;
  bomb = new DefaultBomb(_map, _modelList, _event, this, _clock);
  bomb->setPo(this->_po);
  x = (int)this->_position.x;
  z = (int)this->_position.z;
  while (x % 3 != 0)
    x++;
  while (z % 3 != 0)
    z++;
  bomb->set_x(x);
  bomb->set_z(z);
  glm::vec3 t;
  t.x = x;
  t.y  = 0;
  t.z = z;
  _event->dispatchEvent("bombDrop", &(t));
  this->_map->setBomb(bomb);
}

void	Player::eventRotateRight(void *data)
{
  (void)data;
  if (this->_map->isPause() == true)
    return ;
  //this->rotation.y += 5;
  this->rotate(glm::vec3(0, 1, 0), 5);
  this->_event->dispatchEvent("playerRotateRight", this);
}

void	Player::eventRotate(void *data)
{
  glm::vec3 *test;
  (void)data;

  if (this->_map->isPause() == true)
    return ;
  test = (glm::vec3 *)data;
  //this->rotation.y += 5;
  this->set_roty((-1 * test->y) + 180);
  //this->rotate(glm::vec3(0, 1, 0), 5);
  //this->_event->dispatchEvent("playerRotateRight", this);
}

void	Player::resetAnim()
{
  this->run = false;
  this->none = false;
  this->beginRun = false;
  this->endRun = false;
}

void Player::move(glm::vec3 direct, std::string event)
{
  glm::vec3	posSauv;
  glm::vec3	positionTrans;

  posSauv = this->_position;
  positionTrans = this->translate(direct);
  if (this->run == false)
    {
      this->resetAnim();
      this->_skin->setCurrentSubAnim("beginRun", true);
      this->run = true;
    }
  if (checkPositionCollisionPlayer() == false)
    {
      this->_position.x -= positionTrans.x;
      if (checkPositionCollisionPlayer() == false)
	{
	  this->_position.x += positionTrans.x;
	  this->_position.z -= positionTrans.z;
	  if (checkPositionCollisionPlayer() == false)
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
  this->_event->dispatchEvent("playerPosition", &this->_position);
  //getFrameDuration
}

void	Player::eventKeyUp(void *data)
{
  (void)data;
    if (this->_map->isPause() == true)
    return ;
  this->move(glm::vec3(0, 0, -0.5), "playerMove");
}

void	Player::eventKeyDown(void *data)
{
    if (this->_map->isPause() == true)
    return ;
    (void)data;
  this->move(glm::vec3(0, 0, 0.5), "playerMove");
}

void	Player::eventKeyRight(void *data)
{
  if (this->_map->isPause() == true)
    return ;
    (void)data;
    this->move(glm::vec3(0.5, 0, 0), "playerMove");
}

void	Player::eventKeyLeft(void *data)
{
  if (this->_map->isPause() == true)
    return ;
  (void)data;
  this->move(glm::vec3(-0.5, 0, 0), "playerMove");
}

bool Player::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;

  //if (this->_life <= 0)
    //std::cout << "PLAYER EST MORT CE CON" << std::endl;
  return true;
}



Player::~Player()
{
  std::cout << "Player Destroyed" << std::endl;
}
