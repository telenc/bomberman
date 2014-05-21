//
// CameraBomber.cpp for CameraBomber in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 14 07:57:08 2014 Remi telenczak
// Last update Wed May 21 06:02:06 2014 Remi telenczak
//

#include	"CameraBomber.hpp"
#include	"Player.hpp"

CameraBomber::CameraBomber(gdl::BasicShader *shader, EventManager *event) : _event(event), _shader(shader)
{
  glm::mat4 projection;
  glm::mat4 transformation;

  this->position.y = -4;
  this->position.z = -3;
  this->position.x = -3;
  this->rot = 4.98002;

  this->_occulus = new Occulus();
  _occulus->init();
  _occulus->displayInfo();
  this->stereo = 2;


  callPlayerMove = new CallBack<CameraBomber>(this, &CameraBomber::eventPlayerMove);
  event->listenEvent("playerMove", callPlayerMove);
  /*callKeyUp = new CallBack<CameraBomber>(this, &CameraBomber::eventKeyUp);
  event->listenEvent("playerUp", callKeyUp);
  callKeyLeft = new CallBack<CameraBomber>(this, &CameraBomber::eventKeyLeft);
  event->listenEvent("playerLeft", callKeyLeft);
  callKeyRight = new CallBack<CameraBomber>(this, &CameraBomber::eventKeyRight);
  event->listenEvent("playerRight", callKeyRight);
  callKeyDown = new CallBack<CameraBomber>(this, &CameraBomber::eventKeyDown);
  event->listenEvent("playerDown", callKeyDown);
  */
  callRotateLeft = new CallBack<CameraBomber>(this, &CameraBomber::eventRotateLeft);
  event->listenEvent("playerRotateLeft", callRotateLeft);
  callRotateRight = new CallBack<CameraBomber>(this, &CameraBomber::eventRotateRight);
  event->listenEvent("playerRotateRight", callRotateRight);
}


void	CameraBomber::eventRotateLeft(void *data)
{
  (void)data;
  this->rotation.y -= 5;
}

void	CameraBomber::eventRotateRight(void *data)
{
  (void)data;
  this->rotation.y += 5;
}

void	CameraBomber::eventPlayerMove(void *data)
{
  (void)data;
  glm::vec3 *test;

  test = (glm::vec3 *)data;
  this->translate(-1 * test->x, 0, -1 * test->z);
}

int	CameraBomber::getStereo()
{
  return this->stereo;
}

void CameraBomber::changeStereo(int a)
{
  this->stereo = a;
}

void		CameraBomber::translate(double x, double y, double z)
{
  glm::vec3 vector(x, y, z);
  glm::vec3 vectorRotate;

  //vectorRotate = glm::rotateY(vector, -1 * rotation.y);
  this->position += vector;
}

glm::mat4		CameraBomber::getTransformation()
{
  glm::vec3	vec;
  glm::mat4 transformation;


  transformation = glm::rotate(transformation, this->rotation.y, glm::vec3(0, 1, 0));
  transformation = glm::translate(transformation, position);
  return transformation;
}

glm::mat4		CameraBomber::getTransformationLeft()
{
  glm::vec3	vec;
  glm::mat4 transformation;

  vec = this->_occulus->getOrientation();

  transformation = glm::rotate(transformation, -1 * vec.z, glm::vec3(0, 0, 1));
  transformation = glm::rotate(transformation, -1 * vec.x, glm::vec3(1, 0, 0));
  transformation = glm::rotate(transformation, this->rotation.y, glm::vec3(0, 1, 0));

  transformation = glm::rotate(transformation, -1 * vec.y, glm::vec3(0, 1, 0));
  transformation = glm::rotate(transformation, this->rot *-1, glm::vec3(0, 1, 0));
  transformation = glm::translate(transformation, position);
  return transformation;
}

glm::mat4		CameraBomber::getTransformationRight()
{
  glm::vec3	vec;
  glm::mat4 transformation;

  vec = this->_occulus->getOrientation();
  transformation = glm::rotate(transformation, -1 * vec.z, glm::vec3(0, 0, 1));
  transformation = glm::rotate(transformation, -1 * vec.x, glm::vec3(1, 0, 0));
  transformation = glm::rotate(transformation, this->rotation.y, glm::vec3(0, 1, 0));
  transformation = glm::rotate(transformation, -1 * vec.y, glm::vec3(0, 1, 0));
  transformation = glm::rotate(transformation, this->rot, glm::vec3(0, 1, 0));
  transformation = glm::translate(transformation, position);
  return transformation;
}

glm::mat4 CameraBomber::getPerspective()
{
  glm::mat4 result;

  if (this->stereo == 1)
    {
      result = glm::perspective(60.0f, 1280.0f / 800.0f, 1.7f, 200.0f);
      return result;
    }
  return this->_occulus->getPerspective();
}

glm::vec3	CameraBomber::getPosition()
{
  return this->position;
}

glm::vec3	CameraBomber::getRotation()
{
  return this->rotation;
}
