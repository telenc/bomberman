//
// Ia.hpp for Ia in /home/telenc_r/cpp_bomberman
//
// Made by Remi telenczak
// Login   <telenc_r@epitech.net>
//
// Started on  Fri Jun 13 12:28:24 2014 Remi telenczak
// Last update Sat Jun 14 18:06:14 2014 Remi telenczak
//

#ifndef		_IABOMBER
# define	_IABOMBER

# include	<map>
# include	"APlayer.hpp"
# include	"Input.hh"

class Ia : public APlayer
{
public:
  Ia(int x, int y, int z, Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool	update(gdl::Clock const &clock, gdl::Input &input);
  ~Ia();
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
private:
  std::map<std::string, int (Ia::*)() > _mapName;
  std::map<std::string, bool (Ia::*)() > _mapAction;

};

#endif
