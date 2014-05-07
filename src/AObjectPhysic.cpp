//
// AObjectPhysic.cpp for bomberman in /home/choqua_m/blih/cpp_bomberman/src
// 
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
// 
// Started on  Wed May  7 16:17:56 2014 Mathieu Choquart
// Last update Wed May  7 16:17:57 2014 Mathieu Choquart
//

#include	"AObjectPhysic.hh"

AObjectPhysic::AObjectPhysic(Map *map, EventManager *eventManager)
{
  this->_map = map;
  this->_eventManager = eventManager;
}

AObjectPhysic::~AObjectPhysic()
{
  
}

double		AObjectPhysic::get_x() const
{
    return this->_x;
}

double		AObjectPhysic::get_y() const
{
    return this->_y;
}

double		AObjectPhysic::get_z() const
{
    return this->_z;
}

double		AObjectPhysic::get_vx() const
{
    return this->_vx;
}

double		AObjectPhysic::get_vy() const
{
    return this->_vy;
}

double		AObjectPhysic::get_vz() const
{
    return this->_vz;
}

int		AObjectPhysic::get_height() const
{
    return this->_height;
}

int		AObjectPhysic::get_width() const
{
    return this->_width;
}

std::string	AObjectPhysic::get_skin() const
{
    return this->_skin;
}

Graphics	*AObjectPhysic::get_graphic() const
{
    return this->_graphic;
}

int		AObjectPhysic::get_color() const
{
    return this->_color;
}

Map		AObjectPhysic::get_map() const
{
    return this->_map;
}

EventManager	AObjectPhysic::get_eventManager() const
{
    return this->_eventManager;
}

void		AObjectPhysic::set_x(double x)
{
    this->_x = x;
}

void		AObjectPhysic::set_y(double y)
{
    this->_y = y;
}

void		AObjectPhysic::set_z(double z)
{
    this->_z = z;
}

void		AObjectPhysic::set_vx(double vx)
{
    this->_vx = vx;
}

void		AObjectPhysic::set_vy(double vy)
{
    this->_vy = vy;
}

void		AObjectPhysic::set_vz(double vz)
{
    this->_vz = vz;
}

void		AObjectPhysic::set_height(int height)
{
    this->_height = height;
}

void		AObjectPhysic::set_width(int width)
{
    this->_width = width;
}

void		AObjectPhysic::set_skin(std::string *skin)
{
    this->_skin = skin;
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