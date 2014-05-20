//
// LoadGame.cpp for LoadGame in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Mon May 12 13:48:39 2014 Steven Martreux
// Last update Tue May 20 09:07:44 2014 Remi telenczak
//

#include	<tinyxml.h>
#include	"LoadGame.hpp"

LoadGame::LoadGame(const std::string & file) : _file(file)
{
  TiXmlDocument	XmlDoc(file.c_str());
  _loadOkay = XmlDoc.LoadFile();
  if (!_loadOkay)
    std::cerr << "Load of " << file << " : Error" << std::endl;
  //THROW A FAIRE
  _bomberman = XmlDoc.FirstChildElement("Bomberman");
  if (!_bomberman)
    std::cerr << "Balise <Bomberman> inexistant" << std::endl;
  //TRHOW A FAIRE
}

bool	LoadGame::getLoad() const
{
  return _loadOkay;
}

void	LoadGame::getObjMap()
{
  _map = _bomberman->FirstChildElement("Map");
  if (!_map)
    std::cerr << "Balise <MAP> inexistant" << std::endl;
  //TRHOW
  while (_map)
    {
      //ENVOYER DEDICKER CE QUIL A BESOIN NE SAIT PAS POUR LINSTANT
      _map = _map->NextSiblingElement("Map");
    }
}

void	LoadGame::getMapSize()
{
  int	width;
  int	height;

  (void)width;
  (void)height;
  _map_size = _bomberman->FirstChildElement("Map_Size");
  if (_map_size)
    {
      if (!_map_size->Attribute("width") || !_map_size->Attribute("height"))
	std::cerr << "Attribute width or height not find" << std::endl;
      //TRHOW
      //ENVOYER DEDICK width & heigh
      //width = atoi(map_size->Attribute("width");
      //height = atoi(map_size->Attribute("height");
      // check or not < 20?
    }
  else
    std::cerr << "Balise Map_Size not find" << std::endl;
  //TRHOW
}

LoadGame::~LoadGame()
{

}
