//
// ModelList.hpp for ModelList in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 06:17:48 2014 Remi telenczak
// Last update Tue May 13 07:00:26 2014 Remi telenczak
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
  gdl::Model	*getModel(std::string);
  gdl::Model	*createModel(std::string);
private:
  std::vector<std::pair<std::string, gdl::Model *> >	list;
};

#endif
