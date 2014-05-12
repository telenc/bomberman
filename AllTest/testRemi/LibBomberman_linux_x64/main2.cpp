#include <Model.hh>
#include <fbxsdk.h>
#include "OVR.h"
#include <iostream>
#include <vector>
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
gdl::Model	*test;

void idle(void)
{
  glutPostRedisplay();
}




struct MyVertex
{
  float pos[3];
};

FbxManager* g_pFbxSdkManager = NULL;

int LoadFBX(std::vector<MyVertex> *pOutVertexVector)
{
  if(g_pFbxSdkManager == NULL)
    {
      g_pFbxSdkManager = FbxManager::Create();

      FbxIOSettings* pIOsettings = FbxIOSettings::Create(g_pFbxSdkManager, IOSROOT );
      g_pFbxSdkManager->SetIOSettings(pIOsettings);
    }

  FbxImporter* pImporter = FbxImporter::Create(g_pFbxSdkManager,"");
  FbxScene* pFbxScene = FbxScene::Create(g_pFbxSdkManager,"");

  bool bSuccess = pImporter->Initialize("assets/marvin.fbx", -1, g_pFbxSdkManager->GetIOSettings() );
  if(!bSuccess) return 0;

  bSuccess = pImporter->Import(pFbxScene);
  if(!bSuccess) return 0;

  pImporter->Destroy();

  FbxNode* pFbxRootNode = pFbxScene->GetRootNode();

  if(pFbxRootNode)
    {
      for(int i = 0; i < pFbxRootNode->GetChildCount(); i++)
	{
	  FbxNode* pFbxChildNode = pFbxRootNode->GetChild(i);

	  if(pFbxChildNode->GetNodeAttribute() == NULL)
            continue;

	  FbxNodeAttribute::EType AttributeType = pFbxChildNode->GetNodeAttribute()->GetAttributeType();

	  if(AttributeType != FbxNodeAttribute::eMesh)
            continue;

	  FbxMesh* pMesh = (FbxMesh*) pFbxChildNode->GetNodeAttribute();

	  FbxVector4* pVertices = pMesh->GetControlPoints();

	  for (int j = 0; j < pMesh->GetPolygonCount(); j++)
	    {
	      int iNumVertices = pMesh->GetPolygonSize(j);
	      std::cout << iNumVertices << std::endl;
	      if (iNumVertices != 3)
		continue;
	      //assert( iNumVertices == 3 );

	      for (int k = 0; k < iNumVertices; k++)
		{
		  int iControlPointIndex = pMesh->GetPolygonVertex(j, k);

		  MyVertex vertex;
		  vertex.pos[0] = (float)pVertices[iControlPointIndex].mData[0];
		  vertex.pos[1] = (float)pVertices[iControlPointIndex].mData[1];
		  vertex.pos[2] = (float)pVertices[iControlPointIndex].mData[2];
		  pOutVertexVector->push_back( vertex );
		}
	    }

	}

    }
  return 1;
}


void render(void)
{
  glutSwapBuffers();
}


void init()
{
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
  //glutJoystickFunc(test, 10);

  //test = new gdl::Model();
  //test->load("./assets/marvin.fbx");

  //test->setCurrentAnim(0);
}


void Clear()
{

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

void displayy(std::vector<MyVertex> vert)
{

}

void opengl(double x, double y, double z, std::vector<MyVertex> vert)
{
  glutMainLoopEvent();
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glClearColor(0, 0, 200, 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glClear(GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0, 200, 0);

  //Vector3f eye = Quaternion.right(rift);

  glScissor(0, 0, 680, 800);
  glViewport(0, 0, 680, 800);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glClear(GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0, 200, 0);
  glRotatef(-x, 1, 0, 0);
  glRotatef(-y, 0, 1, 0);
  glRotatef(-z, 0, 0, 1);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glClearColor(0, 0, 200, 0);
  gluLookAt(-100, 105, 0, 0, 0, 0, 1, 1, 1);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glClearColor(0, 0, 200, 0);
//createCube(0, 0);
//createCube(-10, 0);
// createCube(0, 10);


  displayy(vert);


  glClear(GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0, 200, 0);
  glScissor(640, 0, 720, 700);
  glViewport(560, 0,720, 800);

  glTranslatef(0, -1, 0);

  //createCube(0, 0);
  //createCube(-10, 0);
  //createCube(0, 10);
  //this->createPlan();




  glFlush ();
  glutSwapBuffers();
  glutPostRedisplay();
}


void Output()
{
  int i = 0;
  std::vector<MyVertex> vert;

  std::cout << LoadFBX(&vert) << std::endl;
  while(1)
    {

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



      opengl(0, 0, 0, vert);





      i++;
    }
}

int main()
{
  init();
  Output();
  Clear();
}
