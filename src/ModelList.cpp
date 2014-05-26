/*
// ModelList.cpp for modellist in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 06:17:30 2014 Remi telenczak
// Last update Mon May 26 04:55:01 2014 Remi telenczak
// Last update Tue May 20 15:43:51 2014 mattieu bernard-guêle
*/

#include	"ModelList.hpp"

ModelList::ModelList()
{

}

void		ModelList::loadModel()
{
  gdl::Model	*mod;

  mod = this->createModel("./assets/marvin.fbx");
  this->list.push_back(std::make_pair("marvin", mod));
  mod = this->createModel("./assets/cubeWallWood.fbx");
  this->list.push_back(std::make_pair("cube6", mod));
  mod = this->createModel("./assets/cubeWall.fbx");
  this->list.push_back(std::make_pair("cube7", mod));
  mod = this->createModel("./assets/bombe5.fbx");
  this->list.push_back(std::make_pair("defaultBomb", mod));
  mod = this->createModel("./assets/box.fbx");
  this->list.push_back(std::make_pair("skybox", mod));
  mod = this->createModel("./assets/fire_box.FBX");
  this->list.push_back(std::make_pair("fire", mod));
  mod = this->createModel("./assets/mytest.fbx");
  this->list.push_back(std::make_pair("box", mod));
}

gdl::Model	*ModelList::createModel(const std::string path)
{
  gdl::Model	*result;

  result = new gdl::Model();
  std::cout << path << std::endl;
  if (result->load(path.c_str()))
    result->setCurrentAnim(0);
  else
    std::cout << "Erre" << path << std::endl;
  std::cout << "Model : " << path << " chargé" << std::endl;
  return (result);
}

gdl::Model	*ModelList::getModel(const std::string name)
{
  std::vector<std::pair<std::string, gdl::Model *> >::iterator it;

  it = this->list.begin();
  while (it != this->list.end())
    {
      if (it->first == name)
	return (it->second);
      it++;
    }
  std::cout << "Retunrn NULLL" << std::endl;
  return (NULL);
}
