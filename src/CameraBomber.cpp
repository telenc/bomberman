//
// CameraBomber.cpp for CameraBomber in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 14 07:57:08 2014 Remi telenczak
// Last update Thu May 15 06:08:28 2014 Remi telenczak
//

#include	"CameraBomber.hpp"

CameraBomber::CameraBomber(gdl::BasicShader *shader) : _shader(shader)
{
  glm::mat4 projection;
  glm::mat4 transformation;

  this->position.y = -10;
  this->position.z = -90;
  this->rot = 4.98002;
  projection = glm::perspective(60.0f, 1280.0f/2 / 800.0f, 0.5f, 200.0f);
  transformation = glm::lookAt(this->position, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader->setUniform("view", transformation);
  _shader->setUniform("projection", projection);
  this->_occulus = new Occulus();
  _occulus->init();
  _occulus->displayInfo();
  this->stereo = 2;
}

int	CameraBomber::getStereo()
{
  return this->stereo;
}

void CameraBomber::changeStereo()
{
  if (this->stereo == 2)
    this->stereo = 1;
  else
    this->stereo = 2;
}

void CameraBomber::changeRot(float a)
{
  this->rot += a;
  std::cout << rot << std::endl;
}

void		CameraBomber::translate(double x, double y, double z)
{
  glm::vec3 a(x/20, y/20, z/20);
  this->position += a;
}

void		CameraBomber::updateCamera()
{
  glm::vec3	vec;
  glm::mat4 transformation;

  vec = this->_occulus->getOrientation();
  transformation = glm::rotate(transformation, -1 * vec.x, glm::vec3(1, 0, 0));
  transformation = glm::rotate(transformation, -1 * vec.y, glm::vec3(0, 1, 0));
  transformation = glm::rotate(transformation, -1 * vec.z, glm::vec3(0, 0, 1));
  transformation = glm::translate(transformation, position);

  _shader->setUniform("view", transformation);
  std::cout << "Here " << std::endl;
}

glm::mat4		CameraBomber::getTransformation()
{
  glm::vec3	vec;
  glm::mat4 transformation;

  vec = this->_occulus->getOrientation();

  if (this->stereo == 2)
    {
      transformation = glm::rotate(transformation, -1 * vec.x, glm::vec3(1, 0, 0));
      transformation = glm::rotate(transformation, -1 * vec.y, glm::vec3(0, 1, 0));
      transformation = glm::rotate(transformation, -1 * vec.z, glm::vec3(0, 0, 1));
    }
  transformation = glm::translate(transformation, position);

  return transformation;
}

glm::mat4		CameraBomber::getTransformationLeft()
{
  glm::vec3	vec;
  glm::mat4 transformation;
  glm::vec3 positionTmp;
  glm::vec3 positionTmp2;

  positionTmp = this->position;
  positionTmp.x += 1.50;
  vec = this->_occulus->getOrientation();
  positionTmp2 = position;

  if (this->stereo == 2)
    {
      transformation = glm::rotate(transformation, -1 * vec.x, glm::vec3(1, 0, 0));
      transformation = glm::rotate(transformation, -1 * vec.y, glm::vec3(0, 1, 0));
      transformation = glm::rotate(transformation, this->rot *-1, glm::vec3(0, 1, 0));
      transformation = glm::rotate(transformation, -1 * vec.z, glm::vec3(0, 0, 1));
    }
  transformation = glm::translate(transformation, positionTmp);

  return transformation;
}

glm::mat4		CameraBomber::getTransformationRight()
{
  glm::vec3	vec;
  glm::mat4 transformation;
  glm::vec3 positionTmp;
  glm::vec3 positionTmp2;

  positionTmp = this->position;
  positionTmp.x -= 1.50;
  vec = this->_occulus->getOrientation();
  positionTmp2 = position;

  if (this->stereo == 2)
    {
      transformation = glm::rotate(transformation, -1 * vec.x, glm::vec3(1, 0, 0));
      transformation = glm::rotate(transformation, -1 * vec.y, glm::vec3(0, 1, 0));
      transformation = glm::rotate(transformation, this->rot, glm::vec3(0, 1, 0));
      transformation = glm::rotate(transformation, -1 * vec.z, glm::vec3(0, 0, 1));
    }
  transformation = glm::translate(transformation, positionTmp);

  return transformation;
}

glm::mat4 CameraBomber::getTest()
{
  glm::mat4 result;

  if (this->stereo == 1)
    {
 result = glm::perspective(60.0f, 1280.0f/2 / 800.0f, 0.5f, 200.0f);
 return result;
    }
  return this->_occulus->getTest();
}
