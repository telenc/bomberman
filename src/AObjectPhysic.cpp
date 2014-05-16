//
// AObjectPhysic.cpp for bomberman in /home/choqua_m/blih/cpp_bomberman/src
//
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
//
// Started on  Wed May  7 16:17:56 2014 Mathieu Choquart
// Last update Fri May 16 00:57:02 2014 Remi telenczak
//

#include	"AObjectPhysic.hpp"
#include	"Graphics.hpp"
#include	"Model.hh"
# include		"EventManager.hpp"
# include		"Map.hpp"

AObjectPhysic::AObjectPhysic(Map *map, ModelList *modelList, EventManager *eventManager): _position(0, 0, 0), _rotation(0, 0, 0),_scale(1, 1, 1)
{
  this->_map = map;
  this->_eventManager = eventManager;
  this->_modelList = modelList;
}

AObjectPhysic::~AObjectPhysic()
{

}

bool	AObjectPhysic::initialize()
{
  return true;
}

void AObjectPhysic::setSkin(gdl::Model *nskin)
{
  this->_skin = nskin;
}

gdl::Model	*AObjectPhysic::getSkin() const
{
  return this->_skin;
}

void AObjectPhysic::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  this->_skin->draw(shader, this->getTransformation(), 0);
}

glm::mat4	AObjectPhysic::getTransformation()
{
  glm::mat4 transform(1);

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));

  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  return (transform);
}

void AObjectPhysic::translate(glm::vec3 const &v)
{
  this->_position += v;
}

void AObjectPhysic::rotate(glm::vec3 const& axis, float angle)
{
  this->_rotation += axis * angle;
}

void AObjectPhysic::scale(glm::vec3 const& scale)
{
  this->_scale *= scale;
}

double		AObjectPhysic::get_x() const
{
    return this->_position.x;
}

double		AObjectPhysic::get_y() const
{
    return this->_position.y;
}

double		AObjectPhysic::get_z() const
{
    return this->_position.z;
}

double		AObjectPhysic::get_vx() const
{
    return this->_speed.x;
}

double		AObjectPhysic::get_vy() const
{
    return this->_speed.y;
}

double		AObjectPhysic::get_vz() const
{
    return this->_speed.z;
}

double		AObjectPhysic::get_rotx() const
{
    return this->_rotation.x;
}

double		AObjectPhysic::get_roty() const
{
    return this->_rotation.y;
}

double		AObjectPhysic::get_rotz() const
{
    return this->_rotation.z;
}

double		AObjectPhysic::get_scax() const
{
    return this->_scale.x;
}

double		AObjectPhysic::get_scay() const
{
    return this->_scale.y;
}

double		AObjectPhysic::get_scaz() const
{
    return this->_scale.z;
}

int		AObjectPhysic::get_height() const
{
    return this->_height;
}

int		AObjectPhysic::get_width() const
{
    return this->_width;
}

Graphics	*AObjectPhysic::get_graphic() const
{
    return this->_graphic;
}

int		AObjectPhysic::get_color() const
{
    return this->_color;
}

Map		*AObjectPhysic::get_map() const
{
    return this->_map;
}

EventManager	*AObjectPhysic::get_eventManager() const
{
    return this->_eventManager;
}

void		AObjectPhysic::set_x(double x)
{
    this->_position.x = x;
}

void		AObjectPhysic::set_y(double y)
{
    this->_position.y = y;
}

void		AObjectPhysic::set_z(double z)
{
    this->_position.z = z;
}

void		AObjectPhysic::set_vx(double vx)
{
    this->_speed.x = vx;
}

void		AObjectPhysic::set_vy(double vy)
{
    this->_speed.y = vy;
}

void		AObjectPhysic::set_vz(double vz)
{
    this->_speed.z = vz;
}

void		AObjectPhysic::set_rotx(double x)
{
    this->_rotation.x = x;
}

void		AObjectPhysic::set_roty(double y)
{
    this->_rotation.y = y;
}

void		AObjectPhysic::set_rotz(double z)
{
    this->_rotation.z = z;
}

void		AObjectPhysic::set_scax(double x)
{
    this->_scale.x = x;
}

void		AObjectPhysic::set_scay(double y)
{
    this->_scale.y = y;
}
void		AObjectPhysic::set_scaz(double z)
{
    this->_scale.z = z;
}

void		AObjectPhysic::set_height(int height)
{
    this->_height = height;
}

void		AObjectPhysic::set_width(int width)
{
    this->_width = width;
}


void		AObjectPhysic::set_graphic(Graphics *graphic)
{
    this->_graphic = graphic;
}

void		AObjectPhysic::set_color(int color)
{
    this->_color = color;
}

void		AObjectPhysic::set_eventManager(EventManager *eventManager)
{
    this->_eventManager = eventManager;
}
