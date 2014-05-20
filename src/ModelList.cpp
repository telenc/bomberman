/*
// ModelList.cpp for modellist in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 06:17:30 2014 Remi telenczak
** Last update Tue May 20 15:43:51 2014 mattieu bernard-guêle
*/

#include	"ModelList.hpp"

ModelList::ModelList()
{
  gdl::Model	*mod;

  mod = this->createModel("./assets/marvin.fbx");
  this->list.push_back(std::make_pair("marvin", mod));
  mod = this->createModel("./assets/cubeWall.fbx");
  this->list.push_back(std::make_pair("cube1", mod));
  mod = this->createModel("./assets/bombe5.fbx");
  this->list.push_back(std::make_pair("cube2", mod));
  mod = this->createModel("./assets/cubeWall3.fbx");
  this->list.push_back(std::make_pair("cube3", mod));
  mod = this->createModel("./assets/cubeWallGreenS.fbx");
  this->list.push_back(std::make_pair("cube4", mod));
  mod = this->createModel("./assets/cubeWallGreenM.fbx");
  this->list.push_back(std::make_pair("cube5", mod));
  mod = this->createModel("./assets/bombe5.fbx");
  this->list.push_back(std::make_pair("cube6", mod));
  mod = this->createModel("./assets/cubeFloor.fbx");
  this->list.push_back(std::make_pair("cube7", mod));
  mod = this->createModel("./assets/bombetest2.fbx");
  this->list.push_back(std::make_pair("bomb", mod));
  mod = this->createModel("./assets/bombe3.fbx");
  mod->setCurrentAnim(0);
  this->list.push_back(std::make_pair("bomb2", mod));
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
  return (NULL);
}
