//
// APlayer.cpp for APlayer.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman/src
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:11:40 2014 dedicker remi
// Last update Tue Jun 10 16:23:37 2014 Remi telenczak
//

#include	"APlayer.hpp"

//Player
// x /y /z = la base en bas
//height 3.33
//width 1
//depth 1

APlayer::APlayer(int x, int y, int z, Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : AObjectLife(2), AObjectPhysic(map, model, event, clock)
{
  this->_skin = model->getModel("marvin");
  /*
  this->_skin->createSubAnim(0, "run", 20, 46);
  this->_skin->createSubAnim(0, "beginRun", 0, 20);
  this->_skin->createSubAnim(0, "endRun", 46, 100);
  this->_skin->createSubAnim(0, "none", 0, 0);
  this->_skin->setCurrentSubAnim("none", true);
  */

  //  this->_skin->setCurrentAnim(0);
  this->scale(glm::vec3(0.005, 0.005, 0.005));
  this->_position.x = 3;
  this->_position.y = 0;
  this->_position.z = 3;
  this->_type = PLAYER;
  this->_width = 2.8;
  this->_height = 2.8;
  this->_depth = 2.8;
  this->_po = 2;
  this->_nbrBomb = 1;
  this->_nbrBombMax = 1;

  (void)y;
  (void)x;
  (void)z;
}

void	APlayer::incNbrBomb()
{
  this->_nbrBomb++;
}

void	APlayer::incNbrBombMax()
{
  this->_nbrBombMax++;
  this->_nbrBomb++;
}
void	APlayer::incPo()
{
  this->_po++;
}

int	APlayer::getPo() const
{
  return _po;
}

int	APlayer::getNbrMaxBomb() const
{
  return _nbrBombMax;
}

int	APlayer::getNbrBomb() const
{
  return _nbrBomb;
}

void	APlayer::setPo(int po)
{
  this->_po = po;
}

void	APlayer::setNbrBomb(int bomb)
{
  this->_nbrBomb = bomb;
}

void	APlayer::setNbrMaxBomb(int bomb)
{
  this->_nbrBombMax = bomb;
}

APlayer::~APlayer()
{

}
