//
// CameraBomber.hpp for Carmerabomber in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 14 07:57:29 2014 Remi telenczak
// Last update Wed May 28 04:25:33 2014 Remi telenczak
//

#ifndef		_CAMERA_BOMBER
# define	_CAMERA_BOMBER

# include	<glm/glm.hpp>
# include	<BasicShader.hh>
# include	"Occulus.hpp"
# include	"EventManager.hpp"
class CameraBomber
{
public:
  CameraBomber(gdl::BasicShader *shader, EventManager *event);
  glm::mat4	      getTransformation();
  glm::mat4	      getTransformationLeft();
  glm::mat4	      getTransformationRight();
  glm::mat4 getPerspective();
  void	translate(double x, double y, double z);
  void changeStereo(int );
  void changeStereoo(int );
  void changeStereooo(int );
  int	getStereo();
  void	eventPlayerMove(void *data);
  void	eventRotateRight(void *data);
  void	eventRotateLeft(void *data);
  void	eventChangeTypeDeplacement(void *data);
  glm::vec3    getRotation();
  glm::vec3  getPosition();
  float rot;
  void	setPosition(float x, float y, float z);
  glm::mat4 getTransformationMenu();
  float degCam;
  float degCam2;
private:
  EventManager *_event;
  int stereo;
  gdl::BasicShader	*_shader;
  Occulus		*_occulus;
  glm::vec3		position;
  glm::vec3		rotation;
  ICallBack	*callPlayerMove;
  ICallBack	*callTypeDeplacement;
ICallBack	*callRotateLeft;
  ICallBack	*callRotateRight;
int		_typeDeplacement;
};

#endif
