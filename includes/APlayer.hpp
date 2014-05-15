//
// APlayer.hpp for APlayer.hpp in /home/dedick_r/Tek2/c++/cpp_bomberman/includes
// 
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
// 
// Started on  Tue May 13 17:12:08 2014 dedicker remi
// Last update Wed May 14 16:27:56 2014 dedicker remi
//

#ifndef _APLAYER_HPP_
# define _APLAYER_HPP_


# include	<glm/glm.hpp>
# include	<glm/gtc/matrix_transform.hpp>
# include	<Model.hh>
# include	<BasicShader.hh>
# include	"EventManager.hpp"
# include	"AObjectLife.hpp"
# include	"AObjectPhysic.hpp"
# include	"Inventory.hpp"
# include	"Map.hpp"
# include	"Graphics.hpp"

class Map;
class APlayer : public AObjectLife//, public AObjectPhysic
{
public:
  APlayer(int x, int y, int z);
  virtual ~APlayer();
  virtual void	update() const = 0;
  void draw(gdl::AShader &shader, gdl::Clock const &clock);
protected:
  Map	*_map;
  EventManager *_event;
  Inventory *_inventory;
  int	_z;
  int	_x;
  int	_y;
};

#endif
