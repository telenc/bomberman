//
// ModelList.cpp for modellist in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 06:17:30 2014 Remi telenczak
// Last update Thu May 15 15:53:42 2014 Steven Martreux
//

#include	"ModelList.hpp"

ModelList::ModelList()
{
  gdl::Model	*mod;

  mod = this->createModel("./assets/marvin.fbx");
  this->list.push_back(std::make_pair("marvin", mod));
  mod = this->createModel("./assets/wall.fbx");
  this->list.push_back(std::make_pair("wall", mod));
  mod = this->createModel("./assets/wall2.fbx");
  this->list.push_back(std::make_pair("wall2", mod));
  mod = this->createModel("./assets/cube2.fbx");
  this->list.push_back(std::make_pair("cube2", mod));
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
