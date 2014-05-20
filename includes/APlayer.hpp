//
// APlayer.hpp for APlayer.hpp in /home/dedick_r/Tek2/c++/cpp_bomberman/includes
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:12:08 2014 dedicker remi
// Last update Sat May 17 09:57:13 2014 Remi telenczak
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
  APlayer(int, int, int, Map *, ModelList *, EventManager *);
  virtual ~APlayer();
  virtual void update(gdl::Clock const &clock, gdl::Input &input) = 0;
protected:
  Map	*_map;
  Inventory *_inventory;
  int	_z;
  int	_x;
  int	_y;
};

#endif
