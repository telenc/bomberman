//
// Occulus.hpp for Occulus in /home/remi/cpp_bomberman/src
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 05:18:37 2014 Remi telenczak
// Last update Sun Jun 15 19:41:11 2014 Steven Martreux
//

#ifndef		_OCCULUS_BOMBER
# define	_OCCULUS_BOMBER

# include	<glm/glm.hpp>
# include	<glm/gtc/matrix_transform.hpp>
# include	"OVR.h"
# include	<iostream>
# include	<unistd.h>

class Occulus
{
public:
  Occulus();
  void		init();
  void		displayInfo();
  glm::vec3	getOrientationRad();
  glm::vec3	getOrientation();
  glm::mat4	getPerspective();
private:
  OVR::Ptr<OVR::DeviceManager> pManager;
  OVR::Ptr<OVR::HMDDevice> pHMD;
  OVR::Ptr<OVR::SensorDevice> pSensor;
  OVR::SensorFusion *pFusionResult;
  OVR::HMDInfo	Info;
  OVR::Util::Render::StereoConfig Sconfig;
  bool		InfoLoaded;
};

#endif
