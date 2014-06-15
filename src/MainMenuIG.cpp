//
// MainMenuIG.cpp for MainMenuIG in /home/mendez_t/local/cpp/cpp_bomberman/src
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 04:30:52 2014 thomas mendez
// Last update Sun Jun 15 04:58:57 2014 thomas mendez
//

#include	<iostream>
#include	"MainMenuIG.hpp"
#include	"Skybox.hpp"
#include	"CallBack.hpp"

MainMenuIG::MainMenuIG(ModelList *mod, EventManager *event) : _mod(mod), _event(event)
{
  _boxmenu = new MenuBoxIG(NULL, mod, event, NULL, 1);
  _boxmenu2 = new MenuBoxIG(NULL, mod, event, NULL, 2);
  _boxmenu3 = new MenuBoxIG(NULL, mod, event, NULL, 3);
  _callKeyA = new CallBack<MainMenuIG>(this, &MainMenuIG::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
  _A = 0;
}

MainMenuIG::~MainMenuIG()
{
  std::cout << "MainMenuIG Destroyed!" << std::endl;
  //delete _callKeyA;
  delete _boxmenu;
  delete _boxmenu2;
  delete _boxmenu3;
}

void	MainMenuIG::eventKeyA(void *data)
{
  (void)data;
}

int    MainMenuIG::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  glm::mat4 t(1);
  int		roty;
  (void)roty;
  roty = _boxmenu->getRotationy();

  t = glm::translate(t, glm::vec3(0, 0, 0));
  t = glm::scale(t, glm::vec3(100, 100, 100));
  _skin->draw(shader, clock);
  _boxmenu->draw(shader,clock);
  _boxmenu2->draw(shader,clock);
  _boxmenu3->draw(shader,clock);
  return 0;
}

void	MainMenuIG::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  _boxmenu->update(clock, input);
  _boxmenu2->update(clock, input);
  this->_rotationOculus = cameraOculus;
  /*  std::cout << this->_rotationOculus.x << std::endl;
  std::cout << this->_rotationOculus.y << std::endl;
  std::cout << this->_rotationOculus.z << std::endl;*/
  (void)clock;
  (void)input;
}

void	MainMenuIG::setSkybox(Skybox *skybox)
{
  this->_skin = skybox;
  skybox->setSkin(_mod->getModel("box_menu"));
}
