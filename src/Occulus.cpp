//
// Occulus.cpp for Occulus in /home/remi/cpp_bomberman/src
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 05:18:23 2014 Remi telenczak
// Last update Fri May 23 03:14:58 2014 Remi telenczak
//

#include	"Occulus.hpp"

Occulus::Occulus()
{

}

void	Occulus::init()
{
  OVR::System::Init();
  pFusionResult = new OVR::SensorFusion();
  pManager = *OVR::DeviceManager::Create();
  pHMD = *pManager->EnumerateDevices<OVR::HMDDevice>().CreateDevice();
  OVR::System::Init(OVR::Log::ConfigureDefaultLog(OVR::LogMask_All));
  if (pHMD)
    {
      InfoLoaded = pHMD->GetDeviceInfo(&Info);
      pSensor = *pHMD->GetSensor();
      Sconfig.SetHMDInfo(Info);
    }
  else
    {
      pSensor = *pManager->EnumerateDevices<OVR::SensorDevice>().CreateDevice();
    }
  if (pSensor)
    pFusionResult->AttachToSensor(pSensor);
  else
    std::cout << "Sensor not found" << std::endl;
}

void	Occulus::displayInfo()
{
  std::cout << "----- Oculus Console -----" << std::endl;

  if (pHMD)
    {
      std::cout << " [x] HMD Found" << std::endl;
    }
  else
    {
      std::cout << " [ ] HMD Not Found" << std::endl;
    }

  if (pSensor)
    {
      std::cout << " [x] Sensor Found" << std::endl;
    }
  else
    {
      std::cout << " [ ] Sensor Not Found" << std::endl;
    }

  std::cout << "--------------------------" << std::endl;

  if (InfoLoaded)
    {
      std::cout << " DisplayDeviceName: " << Info.DisplayDeviceName << std::endl;
      std::cout << " ProductName: " << Info.ProductName << std::endl;
      std::cout << " Manufacturer: " << Info.Manufacturer << std::endl;
      std::cout << " Version: " << Info.Version << std::endl;
      std::cout << " HResolution: " << Info.HResolution<< std::endl;
      std::cout << " VResolution: " << Info.VResolution<< std::endl;
      std::cout << " HScreenSize: " << Info.HScreenSize<< std::endl;
      std::cout << " VScreenSize: " << Info.VScreenSize<< std::endl;
      std::cout << " VScreenCenter: " << Info.VScreenCenter<< std::endl;
      std::cout << " EyeToScreenDistance: " << Info.EyeToScreenDistance << std::endl;
      std::cout << " LensSeparationDistance: " << Info.LensSeparationDistance << std::endl;
      std::cout << " InterpupillaryDistance: " << Info.InterpupillaryDistance << std::endl;
      std::cout << " DistortionK[0]: " << Info.DistortionK[0] << std::endl;
      std::cout << " DistortionK[1]: " << Info.DistortionK[1] << std::endl;
      std::cout << " DistortionK[2]: " << Info.DistortionK[2] << std::endl;
      std::cout << "--------------------------" << std::endl;
    }
}

glm::vec3	Occulus::getOrientationRad()
{
  OVR::Quatf quaternion;
  float yaw, pitch, roll;
  glm::vec3	result;

  quaternion = pFusionResult->GetOrientation();
  quaternion.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(&yaw, &pitch, &roll);
  result.x = pitch;
  result.y = yaw;
  result.z = roll;
  return (result);
}

glm::vec3	Occulus::getOrientation()
{
  glm::vec3	result;


  result = this->getOrientationRad();

  result.x = OVR::RadToDegree(result.x);
  result.y = OVR::RadToDegree(result.y);
  result.z = OVR::RadToDegree(result.z);
  return (result);
}

glm::mat4 Occulus::getPerspective()
{
  glm::mat4 projec;

  projec = glm::perspective(Sconfig.GetYFOVDegrees()/1.5f, (float)Info.HResolution / 2.0f / (float)Info.VResolution, 2.0f, 500.f);
  return projec;
}
