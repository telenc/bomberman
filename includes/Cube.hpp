//
// Cube.hpp<2> for Cube in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 22 02:54:48 2014 Remi telenczak
// Last update Thu May 22 03:03:30 2014 Remi telenczak
//

#ifndef		_CUBE_HPP
# define	_CUBE_HPP

# include	"AObjectPhysic.hpp"
# include	"Texture.hh"
# include	"Geometry.hh"

class Cube : public AObjectPhysic
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float	_speed;
public:
  Cube(Map *, ModelList *, EventManager *);
  virtual ~Cube();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
