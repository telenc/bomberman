//
// APlayer.hpp for APlayer.hpp in /home/dedick_r/Tek2/c++/cpp_bomberman/includes
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:12:08 2014 dedicker remi
// Last update Fri Jun  6 17:13:47 2014 Steven Martreux
//

#ifndef _APLAYER_HPP_
# define _APLAYER_HPP_


# include	<glm/glm.hpp>
# include	<glm/gtc/matrix_transform.hpp>
# include	<Model.hh>
# include	<BasicShader.hh>
# include	"AObjectLife.hpp"
//# include	"AObjectPhysic.hpp"
# include	"Inventory.hpp"
# include	"Map.hpp"
# include	"Graphics.hpp"

class Map;
class APlayer : public AObjectLife, public AObjectPhysic
{
public:
  APlayer(int, int, int, Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual ~APlayer();
  void	incPo();
  void	incNbrBombMax();
  void	incNbrBomb();
  int	getPo(void) const;
  int	getNbrBomb(void) const;
  int	getNbrMaxBomb(void) const;
  void	setPo(int);
  void	setNbrBomb(int);
  void	setNbrMaxBomb(int);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input) = 0;
protected:
  Inventory *_inventory;
  int	_z;
  int	_x;
  int	_y;
  int	_po;
  int	_nbrBomb;
  int	_nbrBombMax;
};

#endif
