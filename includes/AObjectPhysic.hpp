//
// AObjectPhysic.hh for bomberman in /home/choqua_m/blih/cpp_bomberman/src
//
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
//
// Started on  Wed May  7 15:52:43 2014 Mathieu Choquart
// Last update Sun Jun 15 19:31:42 2014 Steven Martreux
//

#ifndef			_AOBJECTPHYSIC_HPP_
# define		_AOBJECTPHYSIC_HPP_

#include		<Clock.hh>
#include		<Input.hh>
# include		<iostream>
# include		<glm/glm.hpp>
# include		<glm/gtc/matrix_transform.hpp>
# include		<glm/gtx/rotate_vector.hpp>
# include		<glm/gtx/vector_angle.hpp>
# include		<glm/gtx/norm.hpp>
# include		<Model.hh>
# include		<BasicShader.hh>
# include		<vector>

# include		"CameraBomber.hpp"
# include		"IObjectPhysic.hh"

class EventManager;
class Map;
class Graphics;
class ModelList;

enum	TypeObject
  {
    NONE,
    BOMB,
    BONUS,
    PLAYER,
    FIRE,
    BLOC
  };

enum	TypeObjectPrecis
  {
    NONEPRECIS,
    DEFAULTBOMB,
    POBONUS,
    BOMBBONUS,
    PLAYERPRECIS,
    IA,
    FIREPRECIS,
    DEFAULTWALL,
    DESTRUCTWALL,
    SOLWALL,
  };

class	AObjectPhysic : public	IObjectPhysic
{
public:
  AObjectPhysic(Map *map, ModelList *,EventManager *eventManager, gdl::Clock *clock);
  virtual ~AObjectPhysic();
  virtual bool	collision(IObjectPhysic *) { return false; }
  virtual bool	initialize();
  virtual void	display(){}
  virtual bool update(gdl::Clock const &clock, gdl::Input &input) = 0;
  AObjectPhysic *checkPositionCollision(TypeObject);
  void draw(gdl::AShader &shader, gdl::Clock const &clock);
  bool		collision(AObjectPhysic *object);
  bool		collisionNo(AObjectPhysic *object);
  glm::vec3		translate(glm::vec3 const &v);
  void		rotate(glm::vec3 const& axis, float angle);
  void		scale(glm::vec3 const& scale);
  bool		isInView(CameraBomber *camera);
  bool		isInViewSol(CameraBomber *camera);
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
  int		get_depth() const;
  int		get_width() const;
  gdl::Model	*getSkin() const;
  void		setSkin(gdl::Model *);
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
  void		set_depth(int depth);
  void		set_width(int width);
  void		set_graphic(Graphics *graphic);
  void		set_color(int color);
  void		set_map(Map *map);
  void		set_eventManager(EventManager *eventManager);
  glm::mat4	getTransformation();
  glm::vec3	getCornerOne();
  glm::vec3	getCornerTwo();
  glm::vec3	getCornerThree();
  glm::vec3	getCornerFour();
  glm::vec3	getCornerFive();
  glm::vec3	getCornerSix();
  glm::vec3	getCornerSeven();
  glm::vec3	getCornerHeight();
  std::vector<glm::vec3> getAllCorner();
  glm::vec3	getPosition() const;
  void		setPosition(glm::vec3);
  void		setType(TypeObject);
  TypeObject	getType() const;
  int		getId() const;
  void		setId(int);
  TypeObjectPrecis	getTypePrecis() const;
  ModelList	*getModelList() const;
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
  glm::vec3	_speed;
  int		_width;
  int		_height;
  int		_depth;
  Graphics	*_graphic;
  int		_color;
  Map		*_map;
  gdl::Model	*_skin;
  EventManager	*_event;
  ModelList	*_modelList;
  int		_id;
  TypeObject	_type;
  gdl::Clock	*_clock;
  TypeObjectPrecis _typePrecis;
};

# endif
