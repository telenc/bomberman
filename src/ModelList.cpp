/*
// ModelList.cpp for modellist in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 06:17:30 2014 Remi telenczak
<<<<<<< HEAD
// Last update Tue May 27 02:44:56 2014 Remi telenczak
=======
// Last update Mon May 26 17:18:42 2014 dedicker remi
>>>>>>> 86fd066f3cca2a094e91194976398fe97236bc1e
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
  mod = this->createModel("./assets/cubeWallFer.fbx");
  this->list.push_back(std::make_pair("cube6", mod));
  mod = this->createModel("./assets/cubeWall.fbx");
  this->list.push_back(std::make_pair("cubeDest3", mod));
  mod = this->createModel("./assets/cubeWall2.fbx");
  this->list.push_back(std::make_pair("cubeDest2", mod));
  mod = this->createModel("./assets/cubeWall3.fbx");
  this->list.push_back(std::make_pair("cubeDest1", mod));
  mod = this->createModel("./assets/bombe5.fbx");
  this->list.push_back(std::make_pair("defaultBomb", mod));
  mod = this->createModel("./assets/box.fbx");
  this->list.push_back(std::make_pair("skybox", mod));
  mod = this->createModel("./assets/fire_box.FBX");
  this->list.push_back(std::make_pair("fire", mod));
  mod = this->createModel("./assets/mytest.fbx");
  this->list.push_back(std::make_pair("box", mod));
  mod = this->createModel("./assets/box_menu.fbx");
  this->list.push_back(std::make_pair("box_menu", mod));
  mod = this->createModel("./assets/cubeWallWood.fbx");
  this->list.push_back(std::make_pair("sol", mod));
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
  std::cout << "Retunrn NULLL " << name<< std::endl;
  return (NULL);
}
