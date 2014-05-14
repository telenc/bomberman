//
// Occulus.hpp for Occulus in /home/remi/cpp_bomberman/src
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 05:18:37 2014 Remi telenczak
// Last update Wed May 14 15:18:48 2014 Steven Martreux
//

#ifndef		_OCCULUS_BOMBER
# define	_OCCULUS_BOMBER

# include	<glm/glm.hpp>
# include	<glm/gtc/matrix_transform.hpp>
# include	"OVR.h"
# include	<iostream>
# include	<unistd.h>

//using namespace OVR;

class Occulus
{
public:
  Occulus();
  void		init();
  void		displayInfo();
  glm::vec3	getOrientationRad();
  glm::vec3	getOrientation();
private:
  OVR::Ptr<OVR::DeviceManager> pManager;
  OVR::Ptr<OVR::HMDDevice> pHMD;
  OVR:: Ptr<OVR::SensorDevice> pSensor;
  OVR::SensorFusion *pFusionResult;
  OVR::HMDInfo Info;
  bool InfoLoaded;
};

#endif
