//
// LoadGame.cpp for LoadGame in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Mon May 12 13:48:39 2014 Steven Martreux
// Last update Fri May 30 15:13:31 2014 Steven Martreux
//

#include	<tinyxml.h>
#include	"LoadGame.hpp"

LoadGame::LoadGame(const std::string & file, EventManager *event, ModelList *model, gdl::Clock *clock) : _file(file), _event(event), _model(model), _clock(clock)
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
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("defaultwall", &LoadGame::CreateDefaultWall));
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("destrucwall", &LoadGame::CreateDestrucWall));
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("defaultbomb", &LoadGame::CreateDefaultBomb));
  this->getMapSize();
  this->getObjMap();
}

Map	*LoadGame::getMap() const
{
  return _mapGame;
}

bool	LoadGame::getLoad() const
{
  return _loadOkay;
}

AObjectPhysic	*LoadGame::CreateDefaultBomb(TiXmlElement *line)
{
  (void)line;
  return NULL;
}

AObjectPhysic	*LoadGame::CreateDefaultWall(TiXmlElement *line)
{
  DefaultWall	*wall;

  wall = new DefaultWall(_mapGame, _model, _event, _clock);
  wall->set_x(atof(line->Attribute("x")));
  wall->set_y(atof(line->Attribute("y")));
  wall->set_z(atof(line->Attribute("z")));
  return (AObjectPhysic *)wall;
}

AObjectPhysic	*LoadGame::CreateDestrucWall(TiXmlElement *line)
{
  DestrucWall	*wall;

  wall = new DestrucWall(_mapGame, _model, _event, _clock);
  wall->set_x(atof(line->Attribute("x")));
  wall->set_y(atof(line->Attribute("y")));
  wall->set_z(atof(line->Attribute("z")));
  wall->setLife(atoi(line->Attribute("life")));
  return (AObjectPhysic *)wall;
}

void	LoadGame::getObjMap()
{
  std::map<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *) >::iterator i;

  _map = _bomberman->FirstChildElement("Map");
  if (!_map)
    std::cerr << "Balise <MAP> inexistant" << std::endl;
  while (_map)
    {
      i = _mapObject.find(_map->Attribute("object"));
      if (i != _mapObject.end())
 	_mapGame->setMap((this->*_mapObject[_map->Attribute("object")])(_map));
      _map = _map->NextSiblingElement("Map");
    }
}

void	LoadGame::getMapSize()
{
  int	width;
  int	height;

  _map_size = _bomberman->FirstChildElement("Map_Size");
  if (_map_size)
    {
      if (!_map_size->Attribute("width") || !_map_size->Attribute("height"))
	std::cerr << "Attribute width or height not find" << std::endl;
      //TRHOW
      width = atoi(_map_size->Attribute("width"));
      height = atoi(_map_size->Attribute("height"));
      this->_mapGame = new Map(width, height);
    }
  else
    std::cerr << "Balise Map_Size not find" << std::endl;
  //TRHOW
}

LoadGame::~LoadGame()
{
  std::map<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *) >::iterator it;

  for (it=_mapObject.begin(); it != _mapObject.end(); ++it)
    _mapObject.erase(it);
}
