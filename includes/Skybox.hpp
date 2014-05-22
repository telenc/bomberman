//
// Skybox.hpp for skybox in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 22 07:22:23 2014 Remi telenczak
// Last update Thu May 22 09:00:37 2014 Remi telenczak
//

#ifndef		_SKYBOX_BOMBER
# define	_SKYBOX_BOMBER

# include	"AObjectPhysic.hpp"

class Skybox : public AObjectPhysic
{
public:
  Skybox(Map *, ModelList *, EventManager *);
  //void eventPlayerMove(void *);
  ~Skybox();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
private:
  //ICallBack *callPlayerMove;
};
#endif
