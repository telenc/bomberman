//
// CameraBomber.hpp for Carmerabomber in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 14 07:57:29 2014 Remi telenczak
// Last update Thu May 15 04:06:07 2014 Remi telenczak
//

#ifndef		_CAMERA_BOMBER
# define	_CAMERA_BOMBER

# include	<glm/glm.hpp>
# include	<BasicShader.hh>
# include	"Occulus.hpp"

class CameraBomber
{
public:
  CameraBomber(gdl::BasicShader *shader);
  void updateCamera();
  glm::mat4	      getTransformation();
  glm::mat4	      getTransformationLeft();
  glm::mat4	      getTransformationRight();
  glm::mat4 getTest();
  void	translate(double x, double y, double z);
  void changeRot(float a);
private:
  gdl::BasicShader	*_shader;
  Occulus		*_occulus;
  glm::vec3		position;
  float rot;
};

#endif
