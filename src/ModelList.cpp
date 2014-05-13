//
// ModelList.cpp for modellist in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 06:17:30 2014 Remi telenczak
// Last update Tue May 13 07:27:29 2014 Remi telenczak
//

#include	"ModelList.hpp"

ModelList::ModelList()
{
  //gdl::Model	*mod;

  //mod = this->createModel("./assets/marvin.fbx");
  //this->list.push_back(std::make_pair("marvin", mod));
}

gdl::Model	*ModelList::createModel(const std::string path)
{
  gdl::Model	*result;

  //result = new gdl::Model();
  //result->load(path.c_str());
  //result->setCurrentAnim(0);
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
