//
// AObjectPhysic.cpp for bomberman in /home/choqua_m/blih/cpp_bomberman/src
//
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
//
// Started on  Wed May  7 16:17:56 2014 Mathieu Choquart
// Last update Thu Jun 12 13:47:23 2014 Remi telenczak
//

#include	"AObjectPhysic.hpp"
#include	"Graphics.hpp"
#include	"Model.hh"
# include		"EventManager.hpp"
# include		"Map.hpp"
#include		"ABomb.hpp"
#include		"APlayer.hpp"

AObjectPhysic::AObjectPhysic(Map *map, ModelList *modelList, EventManager *eventManager, gdl::Clock *clock): _position(0, 0, 0), _rotation(0, 0, 0),_scale(1, 1, 1), _width(2), _height(2), _depth(2), _type(NONE), _clock(clock), _typePrecis(NONEPRECIS)
{
  static int idCur = 0;
  this->_map = map;
  this->_event = eventManager;
  this->_modelList = modelList;
  this->_id = idCur;
  idCur++;
}

AObjectPhysic::~AObjectPhysic()
{

}

int		AObjectPhysic::getId() const
{
  return this->_id;
}

void		AObjectPhysic::setId(int id)
{
  this->_id = id;
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
  this->_skin->draw(shader, this->getTransformation(), clock.getElapsed());
}


bool AObjectPhysic::isInView(CameraBomber *camera)
{
  glm::vec3	A(0, 0, 0);
  glm::vec3	B(0, 0, 0);
  glm::vec3	C(0, 0, 0);
  glm::vec3	D(0, 0, 0);
  glm::vec3	direc(0, 0, 0);
  glm::vec3	pos(0, 0, 0);
  glm::vec3	dir(0,0,0);
  float or1;
  float or2;

  A.x = camera->getPosition().x;
  A.z = camera->getPosition().z;
  direc.x = 100;
  direc.z = 0;
  direc = glm::rotateY(direc, 85 + camera->getRotation().y);
  B = glm::rotateY(direc, camera->degCam2 *-1);
  C = glm::rotateY(direc, camera->degCam2);
  D.x = this->_position.x - (camera->getPosition().x * -1);
  D.z = this->_position.z - (camera->getPosition().z * -1);
  D.y = 0;

  if (D.x == 0 && D.z == 0)
    return false;

  or1 = glm::orientedAngle(glm::normalize(D), glm::normalize(B), glm::vec3(0,1,0));
  or2 = glm::orientedAngle(glm::normalize(C), glm::normalize(D), glm::vec3(0, 1, 0));
  if ((or1 < 0 && or2 < 0))
    {
      return true;
    }
  return false;
}

glm::mat4	AObjectPhysic::getTransformation()
{
  glm::mat4 transform;

  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, -1 * _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  return (transform);
}

glm::vec3 AObjectPhysic::translate(glm::vec3 const &v)
{
  glm::vec3 b = v * static_cast<float>(_clock->getElapsed()) * 10.f;
  glm::vec3 test = glm::rotateY(b,  -1 * (_rotation.y - 180));
  this->_position += test;
  return test;
}

void AObjectPhysic::rotate(glm::vec3 const& axis, float angle)
{
  this->_rotation += axis * angle;
}

bool	AObjectPhysic::collision(AObjectPhysic *object)
{
  std::vector<glm::vec3>	arretePos;
  std::vector<glm::vec3>::iterator	it;
  glm::vec3	maxPos;
  glm::vec3	minPos;
  ABomb		*bomb;

  if (this->_type == PLAYER && object->getType() == BOMB)
    {
      bomb = (ABomb *)object;
      //(void)bomb;
      if (bomb->getPlayerColl() == false && this->getId() == bomb->getPlayer()->getId())
	{
	  return false;
	}
    }
  else if (this->_type == PLAYER && object->getType() == BONUS)
    return false;
  minPos.x = object->get_x() - (object->get_width() / 2);
  minPos.y = object->get_y();// - (object->get_height() / 2);
  minPos.z = object->get_z() - (object->get_depth() / 2);
  maxPos.x = object->get_x() + (object->get_width() / 2);
  maxPos.y = object->get_y() + (object->get_height());// / 2);
  maxPos.z = object->get_z() + (object->get_depth() / 2);
  arretePos = this->getAllCorner();
  it = arretePos.begin();
  while (it != arretePos.end())
    {
      if (it->x <= maxPos.x && it->x >= minPos.x)
	if (it->y <= maxPos.y && it->y >= minPos.y)
	  if (it->z <= maxPos.z && it->z >= minPos.z)
	    return true;
      it++;
    }
  return false;
}

bool	AObjectPhysic::collisionNo(AObjectPhysic *object)
{
  std::vector<glm::vec3>	arretePos;
  std::vector<glm::vec3>::iterator	it;
  glm::vec3	maxPos;
  glm::vec3	minPos;

  minPos.x = object->get_x() - (object->get_width() / 2);
  minPos.y = object->get_y();// - (object->get_height() / 2);
  minPos.z = object->get_z() - (object->get_depth() / 2);
  maxPos.x = object->get_x() + (object->get_width() / 2);
  maxPos.y = object->get_y() + (object->get_height());// / 2);
  maxPos.z = object->get_z() + (object->get_depth() / 2);
  arretePos = this->getAllCorner();
  it = arretePos.begin();
  while (it != arretePos.end())
    {
      if (it->x <= maxPos.x && it->x >= minPos.x)
	if (it->y <= maxPos.y && it->y >= minPos.y)
	  if (it->z <= maxPos.z && it->z >= minPos.z)
	    return true;
      it++;
    }
  return false;
}

void	AObjectPhysic::setType(TypeObject type)
{
  this->_type = type;
}

TypeObject	AObjectPhysic::getType() const
{
  return this->_type;
}

std::vector<glm::vec3>	AObjectPhysic::getAllCorner()
{
  std::vector<glm::vec3>	result;

  result.push_back(this->getCornerOne());
  result.push_back(this->getCornerTwo());
  result.push_back(this->getCornerThree());
  result.push_back(this->getCornerFour());
  result.push_back(this->getCornerFive());
  result.push_back(this->getCornerSix());
  result.push_back(this->getCornerSeven());
  result.push_back(this->getCornerHeight());
  return (result);
}

glm::vec3	AObjectPhysic::getCornerOne()
{
  glm::vec3	result;

  result.x = this->_position.x - (this->get_width() / 2);
  result.y = this->_position.y;// - (this->get_height() / 2);
  result.z = this->_position.z - (this->get_depth() / 2);
  return result;
}

glm::vec3	AObjectPhysic::getCornerTwo()
{
  glm::vec3	result;

  result.x = this->_position.x - (this->get_width() / 2);
  result.y = this->_position.y + (this->get_height());// / 2);
  result.z = this->_position.z - (this->get_depth() / 2);
  return result;
}

glm::vec3	AObjectPhysic::getCornerThree()
{
  glm::vec3	result;

  result.x = this->_position.x + (this->get_width() / 2);
  result.y = this->_position.y;// - (this->get_height() / 2);
  result.z = this->_position.z - (this->get_depth() / 2);
  return result;
}

glm::vec3	AObjectPhysic::getCornerFour()
{
  glm::vec3	result;

  result.x = this->_position.x + (this->get_width() / 2);
  result.y = this->_position.y + (this->get_height());// / 2);
  result.z = this->_position.z - (this->get_depth() / 2);
  return result;
}

glm::vec3	AObjectPhysic::getCornerFive()
{
  glm::vec3	result;

  result.x = this->_position.x - (this->get_width() / 2);
  result.y = this->_position.y;// - (this->get_height() / 2);
  result.z = this->_position.z + (this->get_depth() / 2);
  return result;
}

glm::vec3	AObjectPhysic::getCornerSix()
{
  glm::vec3	result;

  result.x = this->_position.x - (this->get_width() / 2);
  result.y = this->_position.y + (this->get_height());// / 2);
  result.z = this->_position.z + (this->get_depth() / 2);
  return result;
}

glm::vec3	AObjectPhysic::getCornerSeven()
{
  glm::vec3	result;

  result.x = this->_position.x + (this->get_width() / 2);
  result.y = this->_position.y;// - (this->get_height() / 2);
  result.z = this->_position.z + (this->get_depth() / 2);
  return result;
}

glm::vec3	AObjectPhysic::getCornerHeight()
{
  glm::vec3	result;

  result.x = this->_position.x + (this->get_width() / 2);
  result.y = this->_position.y + (this->get_height());// / 2);
  result.z = this->_position.z + (this->get_depth() / 2);
  return result;
}

TypeObjectPrecis	AObjectPhysic::getTypePrecis() const
{
  return this->_typePrecis;
}

AObjectPhysic	*AObjectPhysic::checkPositionCollision(TypeObject type)
{
  std::vector<AObjectPhysic *>	objects;
  std::vector<AObjectPhysic *>::iterator	it;

  objects = this->_map->getObjectsPos(this);
  it = objects.begin();
  while (it != objects.end())
    {
      if (this->collisionNo(*it) == true)
	{
	  if (type == NONE)
	    return (*it);
	  else if ((*it)->getType() == type)
	    return (*it);
	}
      it++;
    }
  return NULL;
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

int		AObjectPhysic::get_depth() const
{
    return this->_depth;
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
    return this->_event;
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

void		AObjectPhysic::set_depth(int depth)
{
    this->_depth = depth;
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
    this->_event = eventManager;
}

glm::vec3	AObjectPhysic::getPosition() const
{
  return this->_position;
}

void	AObjectPhysic::setPosition(glm::vec3 pos)
{
  this->_position = pos;
}
