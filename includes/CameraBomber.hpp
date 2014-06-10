//
// CameraBomber.hpp for Carmerabomber in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 14 07:57:29 2014 Remi telenczak
// Last update Tue Jun 10 12:30:39 2014 Remi telenczak
//

#ifndef		_CAMERA_BOMBER
# define	_CAMERA_BOMBER

# include	"Clock.hh"
# include	<glm/glm.hpp>
# include	<BasicShader.hh>
# include	"Occulus.hpp"
# include	"EventManager.hpp"

class CameraBomber
{
public:
  CameraBomber(gdl::BasicShader *shader, EventManager *event, gdl::Clock *);
  glm::mat4	      getTransformation();
  glm::mat4	      getTransformationLeft();
  glm::mat4	      getTransformationRight();
  glm::mat4 getPerspective();
  void	translate(double x, double y, double z);
  void	eventCallPause(void *);
  void changeStereo(int );
  void changeStereoo(int );
  void changeStereooo(int );
  int	getStereo();
  void	eventPlayerMove(void *data);
  void	eventRotateRight(void *data);
  void	eventCallNewMap(void *data);
  void	eventRotateLeft(void *data);
  void	eventChangeTypeDeplacement(void *data);
  glm::vec3    getRotation();
  glm::vec3  getPosition();
  float rot;
  void	setPosition(float x, float y, float z);
  glm::mat4 getTransformationMenu();
  float degCam;
  float degCam2;
  void	eventKeyUp(void *data);
  void	eventKeyDown(void *data);
  void	eventKeyRight(void *data);
  void	eventKeyLeft(void *data);

private:
  EventManager *_event;
  int stereo;
  ICallBack	*callPause;
  ICallBack	*callNewMap;
  gdl::Clock	*_clock;
  bool _pause;
  gdl::BasicShader	*_shader;
  Occulus		*_occulus;
  glm::vec3		position;
  glm::vec3		positionPause;
  glm::vec3		rotation;
  glm::vec2		sizeMap;
  ICallBack	*callPlayerMove;
  ICallBack	*callTypeDeplacement;
  ICallBack	*callRotateLeft;
  ICallBack	*callRotateRight;
  int		_typeDeplacement;
  ICallBack	*callKeyUp;
  ICallBack	*callKeyDown;
  ICallBack	*callKeyLeft;
  ICallBack	*callKeyRight;

};

#endif
