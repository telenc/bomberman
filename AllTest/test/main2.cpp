#include "OVR.h"
#include <iostream>
#include <unistd.h>
#include <GL/freeglut.h>
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


void idle(void)
{
  glutPostRedisplay();
}


void render(void)
{
  glutSwapBuffers();
}

void test(unsigned int i, int j, int k, int m)
{
  std::cout << i << std::endl;
  std::cout << j << std::endl;
  std::cout << k << std::endl;
  std::cout << m << std::endl;
  std::cout << "  " << std::endl;
}

void init()
{
  System::Init();
  pFusionResult = new SensorFusion();
  pManager = *DeviceManager::Create();
  pHMD = *pManager->EnumerateDevices<HMDDevice>().CreateDevice();
  System::Init(Log::ConfigureDefaultLog(LogMask_All));
  if (pHMD)
    {
      InfoLoaded = pHMD->GetDeviceInfo(&Info);
      pSensor = *pHMD->GetSensor();
    }
  elseo
    {
      pSensor = *pManager->EnumerateDevices<SensorDevice>().CreateDevice();
    }

  if (pSensor)
    {
      pFusionResult->AttachToSensor(pSensor);
    }
  int res;
  int c;
  glutInit(&c, NULL);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(1280, 800);
  glutInitWindowPosition(100, 0);
  res = glutCreateWindow("Nibbler - Telenc_r - Dedick_r - Martre_s");


  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glEnable(GL_SCISSOR_TEST);
  gluPerspective(75, 1, 1, 2000);
  //gluPerspective(70, (double)1, 1, 1000);
  glutIdleFunc(idle);
  glutDisplayFunc(render);


  GLfloat ambient[] = {0.15f,0.15f,0.15f,0.0f};
  GLfloat diffuse[] = {1.5f,1.5f,1.5f,1.5f};
  GLint light0_position [] = {0 * 2, 5, 0 * 2, 1};
  GLfloat specular_reflexion[] = {0.1,0.1,0.1,1};
  GLubyte shiny_obj = 100;

  glShadeModel(GL_SMOOTH);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular_reflexion);
  glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,shiny_obj);
  glLightfv(GL_LIGHT1,GL_AMBIENT,ambient);
  glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse);
  glLightiv(GL_LIGHT1,GL_POSITION,light0_position);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT1);
  glutJoystickFunc(test, 10);
}


void Clear()
{
  pSensor.Clear();
  pHMD.Clear();
  pManager.Clear();
  delete pFusionResult;
  System::Destroy();
}


void    createCube(double x, double y, double size = 1)
{
  float coul[4] = {0, 0, 0, 1};
  glColor3ub(255, 0, 0);
  glMaterialfv(GL_FRONT,GL_SPECULAR,coul);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, coul);
  glPushMatrix();
  glTranslatef(x, 0, y);
  glutSolidCube(size * 2);
  glPopMatrix();
  return;
}

void opengl(double x, double y, double z)
{
  glutMainLoopEvent();
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glClear(GL_DEPTH_BUFFER_BIT);


  //Vector3f eye = Quaternion.right(rift);

  glScissor(0, 0, 680, 800);
  glViewport(0, 0, 680, 800);


  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glClear(GL_DEPTH_BUFFER_BIT);
  glRotatef(-x, 1, 0, 0);
  glRotatef(-y, 0, 1, 0);
  glRotatef(-z, 0, 0, 1);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  gluLookAt(5, 5, 0, 0, 0, 0, 1, 1, 1);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  createCube(0, 0);
  createCube(-10, 0);
  createCube(0, 10);
  glClear(GL_DEPTH_BUFFER_BIT);

  glScissor(640, 0, 720, 700);
  glViewport(560, 0,720, 800);

  glTranslatef(0, -1, 0);

  createCube(0, 0);
  createCube(-10, 0);
  createCube(0, 10);
  //this->createPlan();




  glFlush ();
  glutSwapBuffers();
  glutPostRedisplay();
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

  int i = 0;
  while(pSensor)
    {
      Vector3f acc = pFusionResult->GetAcceleration();
      Quatf quaternion = pFusionResult->GetOrientation();

      float yaw, pitch, roll;
      quaternion.GetEulerAngles<Axis_Y, Axis_X, Axis_Z>(&yaw, &pitch, &roll);

      /*cout << "Yaw=" << RadToDegree(yaw) <<
	" Pitch=" << RadToDegree(pitch) <<
	" Roll=" << RadToDegree(roll) <<
	" X=" << acc.x / STD_GRAV <<
	" Y=" << acc.y / STD_GRAV <<
	" Z=" << acc.z / STD_GRAV << endl;
      //cin.get();
      */
      //usleep(5000);

      //if (i > 1000) exit(0);



      opengl(RadToDegree(pitch), RadToDegree(yaw), RadToDegree(roll));





      i++;
    }
}

int main()
{
  init();
  Output();
  Clear();
}
