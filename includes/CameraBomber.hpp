//
// CameraBomber.hpp for Carmerabomber in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 14 07:57:29 2014 Remi telenczak
// Last update Tue May 20 07:36:40 2014 Remi telenczak
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
  int	getStereo();
  void	eventKeyUp(void *data);
  void	eventKeyDown(void *data);
  void	eventKeyRight(void *data);
  void	eventKeyLeft(void *data);
  void	eventRotateRight(void *data);
  void	eventRotateLeft(void *data);
  glm::vec3    getRotation();
  glm::vec3  getPosition();
private:
  EventManager *_event;
  int stereo;
  gdl::BasicShader	*_shader;
  Occulus		*_occulus;
  glm::vec3		position;
  glm::vec3		rotation;
  float rot;
  ICallBack	*callPosPlayer;
  ICallBack	*callKeyUp;
  ICallBack	*callKeyDown;
  ICallBack	*callKeyLeft;
  ICallBack	*callKeyRight;
  ICallBack	*callRotateLeft;
  ICallBack	*callRotateRight;
};

#endif
