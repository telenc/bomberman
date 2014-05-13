//
// APlayer.hpp for APlayer.hpp in /home/dedick_r/Tek2/c++/cpp_bomberman/includes
// 
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
// 
// Started on  Tue May 13 17:12:08 2014 dedicker remi
// Last update Tue May 13 17:38:51 2014 dedicker remi
//

#include	"EventManager.hpp"
#include	"AObjectPhysic.hpp"
#include	"Inventory.hpp"
#include	"Map.hpp"

class APlayer : public AObjectPhysic//, public AObjectLife
{
public:
  APlayer(int x, int y, int z);
  virtual ~APlayer();
  virtual void	update() const = 0;
private:
  Map	*_map;
  EventManager *_event;
  Inventory *_inventory;
  int	_z;
  int	_x;
  int	_y;
};
