//
// Skybox.hpp for skybox in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 22 07:22:23 2014 Remi telenczak
// Last update Fri May 23 07:45:56 2014 Remi telenczak
//

#ifndef		_SKYBOX_BOMBER
# define	_SKYBOX_BOMBER

# include	"AObjectPhysic.hpp"
# include	"EventManager.hpp"

class Skybox : public AObjectPhysic
{
public:
Skybox(Map *, ModelList *, EventManager *);
  void eventPlayerMove(void *);
  ~Skybox();
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
private:
  ICallBack *callPlayerMove;
};
#endif
