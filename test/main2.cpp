#include "OVR.h"
#include <iostream>
#include <unistd.h>
//#include <conio.h>

using namespace OVR;
using namespace std;
#define STD_GRAV 1//9.81 // standard gravity (m/s^2 for 1G)

Ptr<DeviceManager> pManager;
Ptr<HMDDevice> pHMD;
Ptr<SensorDevice> pSensor;
SensorFusion *pFusionResult;
HMDInfo Info;
bool InfoLoaded;

void init()
{
  System::Init();
  pFusionResult = new SensorFusion();
  pManager = *DeviceManager::Create();
  pHMD = *pManager->EnumerateDevices<HMDDevice>().CreateDevice();

  if (pHMD)
    {
      InfoLoaded = pHMD->GetDeviceInfo(&Info);
      pSensor = *pHMD->GetSensor();
    }
  else
    {
      pSensor = *pManager->EnumerateDevices<SensorDevice>().CreateDevice();
    }

  if (pSensor)
    {
      pFusionResult->AttachToSensor(pSensor);
    }
}

void Clear()
{
  pSensor.Clear();
  pHMD.Clear();
  pManager.Clear();
  delete pFusionResult;
  System::Destroy();
}

void Output()
{
  cout << "----- Oculus Console -----" << endl;

  if (pHMD)
    {
      cout << " [x] HMD Found" << endl;
    }
  else
    {
      cout << " [ ] HMD Not Found" << endl;
    }

  if (pSensor)
    {
      cout << " [x] Sensor Found" << endl;
    }
  else
    {
      cout << " [ ] Sensor Not Found" << endl;
    }

  cout << "--------------------------" << endl;

  if (InfoLoaded)
    {
      cout << " DisplayDeviceName: " << Info.DisplayDeviceName << endl;
      cout << " ProductName: " << Info.ProductName << endl;
      cout << " Manufacturer: " << Info.Manufacturer << endl;
      cout << " Version: " << Info.Version << endl;
      cout << " HResolution: " << Info.HResolution<< endl;
      cout << " VResolution: " << Info.VResolution<< endl;
      cout << " HScreenSize: " << Info.HScreenSize<< endl;
      cout << " VScreenSize: " << Info.VScreenSize<< endl;
      cout << " VScreenCenter: " << Info.VScreenCenter<< endl;
      cout << " EyeToScreenDistance: " << Info.EyeToScreenDistance << endl;
      cout << " LensSeparationDistance: " << Info.LensSeparationDistance << endl;
      cout << " InterpupillaryDistance: " << Info.InterpupillaryDistance << endl;
      cout << " DistortionK[0]: " << Info.DistortionK[0] << endl;
      cout << " DistortionK[1]: " << Info.DistortionK[1] << endl;
      cout << " DistortionK[2]: " << Info.DistortionK[2] << endl;
      cout << "--------------------------" << endl;
    }

  cout << endl << " Press ENTER to continue" << endl;

  cin.get();
  int i = 0;
  while(pSensor)
    {
      Vector3f acc = pFusionResult->GetAcceleration();
      Quatf quaternion = pFusionResult->GetOrientation();

      float yaw, pitch, roll;
      quaternion.GetEulerAngles<Axis_Y, Axis_X, Axis_Z>(&yaw, &pitch, &roll);

      cout << "Yaw=" << RadToDegree(yaw) << 
	" Pitch=" << RadToDegree(pitch) << 
	" Roll=" << RadToDegree(roll) <<
	" X=" << acc.x / STD_GRAV << 
	" Y=" << acc.y / STD_GRAV << 
	" Z=" << acc.z / STD_GRAV << endl;
      //cin.get();
  
      usleep(5000);

      //if (i > 1000) exit(0);
      i++;
    }
}

int main()
{
  init();
  Output();
  Clear();
}
