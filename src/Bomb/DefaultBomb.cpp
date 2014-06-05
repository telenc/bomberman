//
// DefaultBomb.cpp for defaultbomb in /home/remi/cpp_bomberman/src
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 21 01:36:36 2014 Remi telenczak
// Last update Tue Jun  3 16:11:20 2014 Steven Martreux
//

#include	"DefaultBomb.hpp"
#include	"ModelList.hpp"
#include	"APlayer.hpp"
#include	"DefaultFire.hpp"

DefaultBomb::DefaultBomb(Map *map, ModelList *model, EventManager *event, APlayer *player, gdl::Clock *clock) : ABomb(map, model, event, player, clock)
{
  this->_skin = _modelList->getModel("defaultBomb");
  this->rotate(glm::vec3(0, 1, 0), 45);
  this->rotate(glm::vec3(1, 0, 0), -25);
  this->rotate(glm::vec3(0, 0, 1), -25);
  this->_time = 4000;
  this->_po = 10;
  this->_typePrecis = DEFAULTBOMB;
}

bool	DefaultBomb::update(gdl::Clock const &clock, gdl::Input &input)
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
  time_t currTime;

  time(&currTime);
  if (this->_died == true)
    {
      this->_player->incNbrBomb();
      return false;
    }
  if (difftime(currTime, this->_timeCreate) * 1000 >= this->_time)
    {
      this->_died = true;
      this->createDeflag();
      this->_player->incNbrBomb();
      //this->_map->deleteObject(this);
      return false;
    }
  return true;
  (void)clock;
  (void)input;
}

void	DefaultBomb::createDeflag()
{
  DefaultFire	*fire;
  int		x;
  int		z;
  std::vector<APlayer *> *listPlayer;
  ABloc		*bloc;

  listPlayer = new std::vector<APlayer *>;
  (void)listPlayer;
  x = this->_position.x;// - (this->_po * 3);
  std::cout << "Hereeeeeee" << std::endl;
  std::cout << "1" << std::endl;
  while (x >= (this->_position.x - this->_po * 3))
    {
      if (x != this->_position.x)
	{
	  fire = new DefaultFire(_map, _modelList, _event, listPlayer, _clock);
	  fire->set_x(x);
	  fire->set_z(this->_position.z);
	  if ((bloc = (ABloc *)fire->checkPositionCollision(BLOC)) != NULL)
	    {
	      //if (bloc->fireTouch() == false)
	      bloc->fireTouch();
	      //this->_map->setMap(fire);
	      delete fire;
	      x = this->_position.x - (this->_po * 3) - 1;
	    }
	  else
	    this->_map->setMap(fire);
	}
      x -= 3;
    }

  x = this->_position.x;// - (this->_po * 3);
  while (x <= (this->_position.x + this->_po * 3))
    {
      if (x != this->_position.x)
	{
	  fire = new DefaultFire(_map, _modelList, _event, listPlayer, _clock);
	  fire->set_x(x);
	  fire->set_z(this->_position.z);
	  if ((bloc = (ABloc *)fire->checkPositionCollision(BLOC)) != NULL)
	    {
	      bloc->fireTouch();
	      //if (bloc->fireTouch() == false)
	      //this->_map->setMap(fire);
	      delete fire;
	      x = this->_position.x + (this->_po * 3) + 1;
	    }
	  else
	    this->_map->setMap(fire);
	}
      x += 3;
    }

  z = this->_position.z;// - (this->_po * 3);
  while (z >= this->_position.z - (this->_po * 3))
    {
      if (z != this->_position.z)
	{
	  fire = new DefaultFire(_map, _modelList, _event, listPlayer, _clock);
	  fire->set_z(z);
	  fire->set_x(this->_position.x);
	  if ((bloc = (ABloc *)fire->checkPositionCollision(BLOC)) != NULL)
	    {
	      bloc->fireTouch();
	      //if (bloc->fireTouch() == false)
	      //this->_map->setMap(fire);
	      delete fire;
	      z = this->_position.z - (this->_po * 3) - 1;
	    }
	  else
	    this->_map->setMap(fire);

	}
      z -= 3;
    }

  z = this->_position.z;// - (this->_po * 3);
  while (z <= this->_position.z + (this->_po * 3))
    {
      if (z != this->_position.z)
	{
	  fire = new DefaultFire(_map, _modelList, _event, listPlayer, this->_clock);
	  fire->set_z(z);
	  fire->set_x(this->_position.x);
	  if ((bloc = (ABloc *)fire->checkPositionCollision(BLOC)) != NULL)
	    {
	      bloc->fireTouch();
	      //if (bloc->fireTouch() == false)
	      //this->_map->setMap(fire);
	      delete fire;
	      z = this->_position.z + (this->_po * 3) + 1;
	    }
	  else
	    this->_map->setMap(fire);
	}
      z += 3;
    }

  fire = new DefaultFire(_map, _modelList, _event, listPlayer, _clock);
  fire->set_z(this->_position.z);
  fire->set_x(this->_position.x);
  this->_map->setMap(fire);
}
