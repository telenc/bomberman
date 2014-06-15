//
// SettingsMenuIG.cpp for SettingsMenuIG in /home/mendez_t/local/cpp/cpp_bomberman/src
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 04:33:28 2014 thomas mendez
// Last update Sun Jun 15 04:34:05 2014 thomas mendez
//

#include	<iostream>
#include	"SettingsMenuIG.hpp"
#include	"Skybox.hpp"
#include	"CallBack.hpp"
#include	"SettingBox.hpp"

SettingsMenuIG::SettingsMenuIG(ModelList *mod, EventManager *event) : _mod(mod), _event(event)
{
  _boxmenu = new SettingBoxIG(NULL, mod, event, NULL, 1);
  _callKeyA = new CallBack<SettingsMenuIG>(this, &SettingsMenuIG::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
  std::cout << "SettingsMenuIG create" << std::endl;
}

SettingsMenuIG::~SettingsMenuIG()
{
  std::cout << "SettingsMenuIG Destroyed!" << std::endl;
  delete _callKeyA;
  delete _boxmenu;
}

void	SettingsMenuIG::eventKeyA(void *data)
{
  std::cout << "A Press" << std::endl;
  (void)data;
}

int    SettingsMenuIG::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  std::cout << "SettingsMenuIG draw 1" << std::endl;
  glm::mat4 t(1);
  int		roty;
  (void)roty;

  //  roty = _boxmenu->getRotationy();
  t = glm::translate(t, glm::vec3(0, 0, 0));
  t = glm::scale(t, glm::vec3(100, 100, 100));
  _skin->draw(shader, clock);
  //  _menuwall->draw(shader, clock);
  _boxmenu->draw(shader,clock);
  //  _boxmenu2->draw(shader,clock);
  //_boxmenu3->draw(shader,clock);
  //_menu->draw(shader, clock);
  std::cout << "SettingsMenuIG draw 2" << std::endl;
  return 1;
}

void	SettingsMenuIG::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  std::cout << "SettingsMenuIG update 1" << std::endl;
  _boxmenu->update(clock, input);
  this->_rotationOculus = cameraOculus;
  /*  std::cout << this->_rotationOculus.x << std::endl;
      std::cout << this->_rotationOculus.y << std::endl;
      std::cout << this->_rotationOculus.z << std::endl;*/
  (void)clock;
  (void)input;
  std::cout << "SettingsMenuIG update 2" << std::endl;
}

void	SettingsMenuIG::setSkybox(Skybox *skybox)
{
  this->_skin = skybox;
  skybox->setSkin(_mod->getModel("box_menu"));
}
