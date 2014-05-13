#pragma once

#include "OVR.h"
#include <iostream>
#include <unistd.h>


#include <Game.hh>
#include <unistd.h>
#include <SdlContext.hh>
#include "AObject.hpp"
#include <cstdlib>
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <OpenGL.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Cube.hpp"
/*
On cree sa class GameEngine qui herite de game
*/

using namespace OVR;

class GameEngine : public gdl::Game
{
public:
  GameEngine()
  {
  };

   void initOcc()
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
    else
      {
	pSensor = *pManager->EnumerateDevices<SensorDevice>().CreateDevice();
      }

    if (pSensor)
      {
	pFusionResult->AttachToSensor(pSensor);
      }

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
  bool initialize()
  {
    this->initOcc();
    if (!_context.start(1110, 800, "My bomberman!")) // on cree une fenetre
      return false;
    // On active le test de profondeur d'OpenGL pour que les pixels que l'oeil ne voit pas ne
    glEnable(GL_DEPTH_TEST);
    // On cree un shader, petit programme permettant de dessiner nos objets a l'ecran
    if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER) // le fragment shader se
	|| !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER) // le vertex
	|| !_shader.build()) // il faut ensuite compiler son shader
      return false;
    // On place ensuite la camera (sa projection ainsi que sa transformation)
    glm::mat4 projection;
    glm::mat4 transformation;
    // La projection de la camera correspond a la maniere dont les objets vont etre dessine a
    projection = glm::perspective(60.0f, 1280.0f / 800.0f, 0.5f, 200.0f);
    // La transformation de la camera correspond a son orientation et sa position
    // La camera sera ici situee a la position 0, 20, -100 et regardera vers la position 0, 0, 0
    transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    // On doit toujours binder le shader avant d'appeler les methodes setUniform
    _shader.bind();
    _shader.setUniform("view", transformation);
    _shader.setUniform("projection", projection);
    // On va ensuite creer un cube que l'on va ajouter a la liste d'objets
    AObject *cube = new Cube();
    if (cube->initialize() == false)
      return (false);
    _objects.push_back(cube);
    test = new gdl::Model();
    if (_texture.load("./assets/marvin.fbm/Main_texture_diffuse2.tga") == false)

      {

	std::cerr << "Cannot load the cube texture" << std::endl;

	return (false);

      }
    test->load("./assets/marvin.fbx");
    test->setCurrentAnim(0);
    return true;
  }
  bool update()
  {
    // Si la touche ECHAP est appuyee ou si l'utilisateur ferme la fenetre, on quitte le
    if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
      return false;
    // Mise a jour des inputs et de l'horloge de jeu
    _context.updateClock(_clock);
    _context.updateInputs(_input);
    // Mise a jour des differents objets
    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->update(_clock, _input);
    //usleep(110000);
    return true;
  };
  void draw()
  {
    glm::mat4 transformation;
    //transformation = glm::lookAt(glm::vec3(0, 5, -30), glm::vec3(0, 5, 0), glm::vec3(0, 1, 0));



    if (pSensor)
      {
	Quatf quaternion = pFusionResult->GetOrientation();
	float yaw, pitch, roll;
	quaternion.GetEulerAngles<Axis_Y, Axis_X, Axis_Z>(&yaw, &pitch, &roll);


	//transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(-1 * RadToDegree(pitch), -1 * RadToDegree(yaw), -1 *RadToDegree(roll)), glm::vec3(0, 1, 0));

	transformation = glm::rotate(transformation, -1 *  RadToDegree(pitch), glm::vec3(1, 0, 0));
	transformation = glm::rotate(transformation, -1 * RadToDegree(yaw), glm::vec3(0, 1, 0));
	transformation = glm::rotate(transformation, -1 * RadToDegree(roll), glm::vec3(0, 0, 1));
	transformation = glm::translate(transformation, glm::vec3(0, -5, 1.5));

      }
    _shader.setUniform("view", transformation);

    glm::mat4 tr(1);
    glm::vec3 _rotation(90, 180, 90);
    tr = glm::rotate(tr, _rotation.y, glm::vec3(0, 1, 0));
    tr = glm::scale(tr, glm::vec3(0.01, 0.01, 0.01));
    glScissor(0, 0, 680, 800);
    glViewport(0, 0, 680, 800);
    glClearColor(255, 0, 0, 0);
    //
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _shader.bind();

    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->draw(_shader, _clock);

    test->draw(_shader, tr, 30000);

    _shader.setUniform("view", transformation);
    //
    glScissor(640, 0, 720, 700);
    glViewport(560, 0,720, 800);
    _shader.setUniform("view", transformation);
    //glTranslatef(0, -1, 0);
    glClearColor(255, 0, 0, 0);
    //


    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->draw(_shader, _clock);

    //_texture.bind();
    test->draw(_shader, tr, 0);

    _context.flush();
  }
  ~GameEngine()
  {
    // N'oublions pas de supprimer les objets une fois le programme termine!
    for (size_t i = 0; i < _objects.size(); ++i)
      delete _objects[i];
  }
private:
  gdl::Texture _texture;
  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  gdl::BasicShader _shader;
  std::vector<AObject*> _objects;
  gdl::Model	*test;
  Ptr<DeviceManager> pManager;
  Ptr<HMDDevice> pHMD;
  Ptr<SensorDevice> pSensor;
  SensorFusion *pFusionResult;
  HMDInfo Info;
  bool InfoLoaded;
};
