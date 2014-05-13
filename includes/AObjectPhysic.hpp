//
// AObjectPhysic.hh for bomberman in /home/choqua_m/blih/cpp_bomberman/src
//
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
//
// Started on  Wed May  7 15:52:43 2014 Mathieu Choquart
// Last update Tue May 13 17:41:44 2014 thomas mendez
//

#ifndef			_AOBJECTPHYSIC_HH_
# define		_AOBJECTPHYSIC_HH_

# include		<string>
# include		<iostream>
# include		<glm/glm.hpp>
# include		<glm/gtc/matrix_transform.hpp>
# include		<Model.hh>
# include		<BasicShader.hh>
# include		"IObjectPhysic.hh"
# include		"EventManager.hpp"
# include		"Map.hpp"
# include		"Graphics.hpp"

class	AObjectPhysic : public	IObjectPhysic
{
public:
  AObjectPhysic(Map *map, EventManager *eventManager);
  virtual 	~AObjectPhysic();
  virtual bool	initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  void		translate(glm::vec3 const &v);
  void		rotate(glm::vec3 const& axis, float angle);
  void		scale(glm::vec3 const& scale);
  double	get_x() const;
  double	get_y() const;
  double	get_z() const;
  double	get_vx() const;
  double	get_vy() const;
  double	get_vz() const;
  double	get_rotx() const;
  double	get_roty() const;
  double	get_rotz() const;
  double	get_scax() const;
  double	get_scay() const;
  double	get_scaz() const;
  int		get_height() const;
  int		get_width() const;
  gdl::Model	get_skin() const;
  Graphics	*get_graphic() const;
  int		get_color() const;
  Map		*get_map() const;
  EventManager	*get_eventManager() const;
  void		set_x(double x);
  void		set_y(double y);
  void		set_z(double z);
  void		set_vx(double vx);
  void		set_vy(double vy);
  void		set_vz(double vz);
  void		set_rotx(double x);
  void		set_roty(double y);
  void		set_rotz(double z);
  void		set_scax(double x);
  void		set_scay(double y);
  void		set_scaz(double z);
  void		set_height(int height);
  void		set_width(int width);
  void		set_skin(const std::string *skin);
  void		set_graphic(Graphics *graphic);
  void		set_color(int color);
  void		set_map(Map *map);
  void		set_eventManager(EventManager *eventManager);
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
  glm::vec3	_speed;
  int		_height;
  int		_width;
  gdl::Model	_skin;
  Graphics	*_graphic;
  int		_color;
  Map		*_map;
  EventManager	*_eventManager;
};

# endif
