#pragma once
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
class GameEngine : public gdl::Game
{
public:
  GameEngine()
  {
  };
  bool initialize()
  {
    if (!_context.start(1280, 800, "My bomberman!")) // on cree une fenetre
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
    projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
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
    usleep(110000);
    return true;
  };
  void draw()
  {
    glm::mat4 tr(1);
    tr = glm::scale(tr, glm::vec3(0.01, 0.01, 0.01));
    glScissor(0, 0, 680, 800);
    glViewport(0, 0, 680, 800);
    glClearColor(255, 0, 0, 0);
    //
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _shader.bind();

    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->draw(_shader, _clock);

    test->draw(_shader, tr, GL_QUADS);


    //
    glScissor(640, 0, 720, 700);
    glViewport(560, 0,720, 800);

    glTranslatef(0, -1, 0);
    glClearColor(255, 0, 0, 0);
    //



    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->draw(_shader, _clock);

    _texture.bind();
    test->draw(_shader, tr, GL_QUADS);

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
};
