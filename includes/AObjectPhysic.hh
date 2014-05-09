//
// AObjectPhysic.hh for bomberman in /home/choqua_m/blih/cpp_bomberman/src
// 
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
// 
// Started on  Wed May  7 15:52:43 2014 Mathieu Choquart
// Last update Wed May  7 15:52:44 2014 Mathieu Choquart
//

#ifndef			_AOBJECTPHYSIC_HH_
# define		_AOBJECTPHYSIC_HH_

# include		<string>
# include		<iostream>
# include		"IObjectPhysic.hh"
# include		"EventManager.hpp"
# include		"Map.hpp"
# include		"Graphics.hpp"

class	AObjectPhysic : public	IObjectPhysic
{
public:
  virtual 	AObjectPhysic(Map *map, EventManager *eventManager);
  virtual 	~AObjectPhysic();
  double	get_x() const;
  double	get_y() const;
  double	get_z() const;
  double	get_vx() const;
  double	get_vy() const;
  double	get_vz() const;
  int		get_height() const;
  int		get_width() const;
  std::string	get_skin() const;
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
  void		set_height(int height);
  void		set_width(int width);
  void		set_skin(const std::string *skin);
  void		set_graphic(Graphics *graphic);
  void		set_color(int color);
  void		set_map(Map *map);
  void		set_eventManager(EventManager *eventManager);
protected:
  double	_x;
  double	_y;
  double	_z;
  double	_vx;
  double	_vy;
  double	_vz;
  int		_height;
  int		_width;
  std::string	_skin;
  Graphics	*_graphic;
  int		_color;
  Map		*_map;
  EventManager	*_eventManager;
};

# endif