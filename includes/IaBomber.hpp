//
// Ia.hpp for Ia in /home/telenc_r/cpp_bomberman
//
// Made by Remi telenczak
// Login   <telenc_r@epitech.net>
//
// Started on  Fri Jun 13 12:28:24 2014 Remi telenczak
// Last update Sun Jun 15 11:59:11 2014 Remi telenczak
//

#ifndef		_IABOMBER
# define	_IABOMBER

# include	<map>
# include	"APlayer.hpp"
# include	"Input.hh"
# include	<tinyxml.h>
# include	<time.h>
struct		IaXml
{
  std::string	name;
  int		condition;
  std::string	action;
};

class IaBomber : public APlayer
{
public:
  IaBomber(int x, int y, int z, Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool	update(gdl::Clock const &clock, gdl::Input &input);
  ~IaBomber();
  bool		poseBomb();
  APlayer	*minDistanceEnemy();
  AObjectPhysic	*minDistanceDestruc();
  bool		isInRisk(int x = -1, int z = -1);
  glm::vec2	getPositionNoRisk();
  bool		move(glm::vec3 direct);
  ABonus	*getBonus(int);
  void		changeRot(int, int);
  int		isInRiskIa();
  int		enemyDistanceIa();
  int		wallDistanceIa();
  int		bonusDistanceIa();
  int		enemyNearIa();
  bool		goSafeIa();
  bool		poseBombIa();
  bool		goBonusIa();
  bool		goWallIa();
  bool		goEnemyNearIa();
  void		getList();
  int		calcPositionNoRisk(glm::vec2 position, glm::vec2 old, int taille);
  glm::vec2	getChemin(int, int);
private:
  time_t					_timeBomb;
  std::map<std::string, int (IaBomber::*)() >	_mapName;
  std::map<std::string, bool (IaBomber::*)() >	_mapAction;
  std::list<IaXml *>				listXml;
  IaXml						*_IaX;
  glm::vec2					_positionTo;
};

#endif
