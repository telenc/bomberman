//
// ModelList.hpp for ModelList in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 06:17:48 2014 Remi telenczak
// Last update Mon Jun  2 04:51:03 2014 Remi telenczak
//

#ifndef		_MODEL_LIST
# define	_MODEL_LIST

# include	<Model.hh>
# include	<iostream>
# include	<vector>

class ModelList
{
public:
  ModelList();
  void		loadModel();
  gdl::Model	*getModel(const std::string);
  gdl::Model	*createModel(const std::string);
private:
  std::vector<std::pair<std::string, std::string> >	listChemin;
  std::vector<std::pair<std::string, gdl::Model *> >	list;
};

#endif
