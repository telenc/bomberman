//
// Cube.hpp<2> for Cube in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 22 02:54:48 2014 Remi telenczak
// Last update Sun Jun 15 05:35:14 2014 Steven Martreux
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
  float		_speed;
public:
  Cube(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual ~Cube();
  virtual bool initialize();
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
