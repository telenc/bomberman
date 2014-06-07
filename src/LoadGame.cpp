//
// LoadGame.cpp for LoadGame in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Mon May 12 13:48:39 2014 Steven Martreux
// Last update Sat Jun  7 18:42:37 2014 Steven Martreux
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
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("bonuspo", &LoadGame::CreateBonusPo));
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("bonusbomb", &LoadGame::CreateBonusBomb));
  this->getMapSize();
  this->getPlayer();
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

AObjectPhysic	*LoadGame::CreateBonusPo(TiXmlElement *line)
{
  PoBonus	*obj;

  obj = new PoBonus(_mapGame, _model, _event, _clock);
  obj->setId(atoi(line->Attribute("id")));
  obj->set_x(atof(line->Attribute("x")));
  obj->set_y(atof(line->Attribute("y")));
  obj->set_z(atof(line->Attribute("z")));
  obj->setDied(atoi(line->Attribute("died")));
  return (AObjectPhysic *)obj;
}

AObjectPhysic	*LoadGame::CreateBonusBomb(TiXmlElement *line)
{
  BombBonus	*obj;

  obj = new BombBonus(_mapGame, _model, _event, _clock);
  obj->setId(atoi(line->Attribute("id")));
  obj->set_x(atof(line->Attribute("x")));
  obj->set_y(atof(line->Attribute("y")));
  obj->set_z(atof(line->Attribute("z")));
  obj->setDied(atoi(line->Attribute("died")));
  return (AObjectPhysic *)obj;
}

APlayer		*LoadGame::GetPlayerBomb(int id_player)
{
  std::vector<APlayer *> play;
  std::vector<APlayer *>::iterator it;

  play = _mapGame->getPlayers();
  it = play.begin();
  while (it != play.end())
    {
      if ((*it)->getId() == id_player)
	return (*it);
      it++;
    }
  //THROW
  std::cout << "NOT FIND id_player" << std::endl;
  return NULL;
}

AObjectPhysic	*LoadGame::CreateDefaultBomb(TiXmlElement *line)
{
  DefaultBomb	*bomb;
  int		id_player;
  APlayer      	*player;

  id_player = atoi(line->Attribute("id_player"));
  player = this->GetPlayerBomb(id_player);
  bomb = new DefaultBomb(_mapGame, _model, _event, player, _clock);
  bomb->setId(atoi(line->Attribute("id")));
  bomb->set_x(atof(line->Attribute("x")));
  bomb->set_y(atof(line->Attribute("y")));
  bomb->set_z(atof(line->Attribute("z")));
  bomb->setPo(atoi(line->Attribute("po")));
  bomb->setDamage(atoi(line->Attribute("damage")));
  bomb->setTime(atoi(line->Attribute("time")));
  bomb->setPlayerColl(atoi(line->Attribute("playercoll")));
  bomb->setDied(atoi(line->Attribute("died")));
  return (AObjectPhysic *)bomb;
}

AObjectPhysic	*LoadGame::CreateDefaultWall(TiXmlElement *line)
{
  DefaultWall	*wall;

  wall = new DefaultWall(_mapGame, _model, _event, _clock);
  wall->setId(atoi(line->Attribute("id")));
  wall->set_x(atof(line->Attribute("x")));
  wall->set_y(atof(line->Attribute("y")));
  wall->set_z(atof(line->Attribute("z")));
  return (AObjectPhysic *)wall;
}

AObjectPhysic	*LoadGame::CreateDestrucWall(TiXmlElement *line)
{
  DestrucWall	*wall;

  wall = new DestrucWall(_mapGame, _model, _event, _clock);
  wall->setId(atoi(line->Attribute("id")));
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

void	 LoadGame::getPlayer()
{
  Player	*player;
  int		x;
  int		y;
  int		z;

  _player = _bomberman->FirstChildElement("Player");
  if (_player)
    {
      x = atoi(_player->Attribute("x"));
      y = atoi(_player->Attribute("y"));
      z = atoi(_player->Attribute("z"));
      player = new Player(x, y , z, _mapGame, _model, _event, _clock);
      player->setId(atoi(_player->Attribute("id")));
      player->setPo(atoi(_player->Attribute("po")));
      player->setLife(atoi(_player->Attribute("life")));
      player->set_rotx(atoi(_player->Attribute("rot_x")));
      player->set_roty(atoi(_player->Attribute("rot_y")));
      player->set_rotz(atoi(_player->Attribute("rot_z")));
      player->setNbrBomb(atoi(_player->Attribute("nbrMaxBomb")));
      player->setNbrMaxBomb(atoi(_player->Attribute("nbrCurrentBomb")));
      _mapGame->setMap((AObjectPhysic *)player);
    }
  else
    std::cerr << "Balise Player not found" << std::endl;
}

LoadGame::~LoadGame()
{
  std::map<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *) >::iterator it;

  for (it=_mapObject.begin(); it != _mapObject.end(); ++it)
    _mapObject.erase(it);
}
