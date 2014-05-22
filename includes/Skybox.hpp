//
// Skybox.hpp for skybox in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 22 07:22:23 2014 Remi telenczak
// Last update Thu May 22 07:27:06 2014 Remi telenczak
//

#ifndef		_SKYBOX_BOMBER
# define	_SKYBOX_BOMBER

# include	"AObjectPhysic.hpp"

class Skybox : public AObjectPhysic
{
public:
  Skybox(Map *, ModelList *, EventManager *);
  ~Skybox();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
};
#endif
