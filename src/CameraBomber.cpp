//
// CameraBomber.cpp for CameraBomber in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 14 07:57:08 2014 Remi telenczak
// Last update Fri Jun  6 11:53:14 2014 Remi telenczak
//

#include	"CameraBomber.hpp"
#include	"Player.hpp"

CameraBomber::CameraBomber(gdl::BasicShader *shader, EventManager *event) : _event(event), _pause(false), _shader(shader)
{
  glm::mat4 projection;
  glm::mat4 transformation;

  degCam = 85;
  degCam2 = 80;
  this->position.y = -4;
  this->position.z = -3;
  this->position.x = -3;
  this->position.z = -3;
  this->position.x = -3;
  this->rot = 4.98002;

  this->_occulus = new Occulus();
  _occulus->init();
  _occulus->displayInfo();
  this->stereo = 2;


  callPlayerMove = new CallBack<CameraBomber>(this, &CameraBomber::eventPlayerMove);
  event->listenEvent("playerMove", callPlayerMove);
  callTypeDeplacement = new CallBack<CameraBomber>(this, &CameraBomber::eventChangeTypeDeplacement);
  event->listenEvent("playerMove", callTypeDeplacement);
  callRotateLeft = new CallBack<CameraBomber>(this, &CameraBomber::eventRotateLeft);
  event->listenEvent("playerRotateLeft", callRotateLeft);
  callRotateRight = new CallBack<CameraBomber>(this, &CameraBomber::eventRotateRight);
  event->listenEvent("playerRotateRight", callRotateRight);
  callPause = new CallBack<CameraBomber>(this, &CameraBomber::eventCallPause);
  event->listenEvent("pause", callPause);

  this->_typeDeplacement = 0;
}

void	CameraBomber::eventChangeTypeDeplacement(void *data)
{
  int	*newType;

  newType = (int *)data;
  this->_typeDeplacement = *newType;
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

void CameraBomber::changeStereoo(int a)
{
  this->degCam += a;
  std::cout << degCam << std::endl;
}

void CameraBomber::changeStereooo(int a)
{
  this->degCam2 += a;
  std::cout << "Cam 2" << degCam2 << std::endl;
}

void		CameraBomber::translate(double x, double y, double z)
{
  glm::vec3 vector(x, y, z);
  glm::vec3 vectorRotate;

  this->position += vector;
}

glm::mat4		CameraBomber::getTransformation()
{
  glm::vec3	vec;
  glm::mat4 transformation;

  if (this->_pause == false)
    {
      transformation = glm::rotate(transformation, this->rotation.y, glm::vec3(0, 1, 0));

      transformation = glm::rotate(transformation, 90.f, glm::vec3(1, 0, 0));
      transformation = glm::translate(transformation, position);
    }
  else
    {
      std::cout << "seg ici?" << std::endl;
      transformation = glm::lookAt(glm::vec3(position.x, position.y + 20, position.z-20), position, glm::vec3(0, 1, 0));
      std::cout << "oui" << std::endl;
    }
  return transformation;
}

void	CameraBomber::eventCallPause(void *data)
{
  if (this->_pause == true)
    {
      std::cout << "false" << std::endl;
      this->_pause = false;
    }
  else
    {
      this->_pause = true;
      this->positionPause.x = this->position.x;
      this->positionPause.z = this->position.z;
      this->positionPause.y = 20;
      std::cout << "true" << std::endl;
    }
  (void)data;
}

glm::mat4		CameraBomber::getTransformationMenu()
{
  glm::vec3	vec;
  glm::mat4 transformation;


  transformation = glm::rotate(transformation, this->rotation.y, glm::vec3(0, 1, 0));
  return transformation;
}

glm::mat4		CameraBomber::getTransformationLeft()
{
  glm::vec3	vec;
  glm::mat4 transformation;

  vec = this->_occulus->getOrientation();

  if (this->_pause == false)
    {
      transformation = glm::rotate(transformation, -1 * vec.z, glm::vec3(0, 0, 1));
      transformation = glm::rotate(transformation, -1 * vec.x, glm::vec3(1, 0, 0));
      if (this->_typeDeplacement == 1)
	transformation = glm::rotate(transformation, this->rotation.y, glm::vec3(0, 1, 0));
      transformation = glm::rotate(transformation, -1 * vec.y, glm::vec3(0, 1, 0));
      transformation = glm::rotate(transformation, this->rot *-1, glm::vec3(0, 1, 0));
      transformation = glm::translate(transformation, position);
    }
  else
    {
      transformation = glm::lookAt(glm::vec3(position.x - 10, position.y + 20, position.z), position, glm::vec3(0, 1, 0));
    }
  return transformation;
}

glm::mat4		CameraBomber::getTransformationRight()
{
  glm::vec3	vec;
  glm::mat4 transformation;

  if (this->_pause == false)
    {
      vec = this->_occulus->getOrientation();
      transformation = glm::rotate(transformation, -1 * vec.z, glm::vec3(0, 0, 1));
      transformation = glm::rotate(transformation, -1 * vec.x, glm::vec3(1, 0, 0));
      if (this->_typeDeplacement == 1)
	transformation = glm::rotate(transformation, this->rotation.y, glm::vec3(0, 1, 0));
      transformation = glm::rotate(transformation, -1 * vec.y, glm::vec3(0, 1, 0));
      transformation = glm::rotate(transformation, this->rot, glm::vec3(0, 1, 0));
      transformation = glm::translate(transformation, position);
    }
  else
    {
      transformation = glm::lookAt(glm::vec3(position.x - 10, position.y + 20, position.z), position, glm::vec3(0, 1, 0));
    }
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
  this->rotation = this->_occulus->getOrientation();
  return this->rotation;
}

void	CameraBomber::setPosition(float x, float y, float z)
{
  this->position.x = x;
  this->position.y = y;
  this->position.z = z;
}
