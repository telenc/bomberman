/*
** ModelList.cpp for make in /home/bernar_x/Tech2/Projets/cpp_bomberman
** 
** Made by mattieu bernard-guêle
** Login <bernar_x@epitech.net>
** 
** Started on  Thu May 22 14:52:19 2014 mattieu bernard-guêle
** Last update Thu May 22 14:52:20 2014 mattieu bernard-guêle
*/

#include	"ModelList.hpp"

ModelList::ModelList()
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
  mod = this->createModel("./assets/test2/box.fbx");
  mod = this->createModel("./assets/test2/groundv2.FBX");
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
  return (NULL);
}
