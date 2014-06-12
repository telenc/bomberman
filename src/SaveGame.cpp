//
// SaveGame.cpp for SaveGame in /home/martre_s/workspace/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Fri May 30 16:39:48 2014 Steven Martreux
// Last update Tue Jun 10 16:34:07 2014 Steven Martreux
//

#include	"SaveGame.hpp"
#include	"Map.hpp"
#include	"APlayer.hpp"

SaveGame::SaveGame(Map *map, const std::string & filename) : _map(map), _fileName(filename)
{
  _mapObject.insert(std::pair<TypeObjectPrecis, void(SaveGame::*)(AObjectPhysic *)>(DEFAULTWALL, &SaveGame::SaveDefaultWall));
  _mapObject.insert(std::pair<TypeObjectPrecis, void(SaveGame::*)(AObjectPhysic *)>(DESTRUCTWALL, &SaveGame::SaveDestructWall));
  _mapObject.insert(std::pair<TypeObjectPrecis, void(SaveGame::*)(AObjectPhysic *)>(DEFAULTBOMB, &SaveGame::SaveDefaultBomb));
  _mapObject.insert(std::pair<TypeObjectPrecis, void(SaveGame::*)(AObjectPhysic *)>(BOMBBONUS, &SaveGame::SaveBonusBomb));
  _mapObject.insert(std::pair<TypeObjectPrecis, void(SaveGame::*)(AObjectPhysic *)>(POBONUS, &SaveGame::SaveBonusPo));
  _mapObject.insert(std::pair<TypeObjectPrecis, void(SaveGame::*)(AObjectPhysic *)>(FIREPRECIS, &SaveGame::SaveDefaultFire));
  _bomberman = new TiXmlElement("Bomberman");
  _file.LinkEndChild(_bomberman);
  this->SaveMapSize();
  this->SavePlayer();
  this->setObjMap();
  _file.SaveFile(_fileName.c_str());
}

std::string	SaveGame::ConstCharByFloat(float x) const
{
  std::stringstream tmp;

  tmp.clear();
  tmp << x;
  return tmp.str();
}

std::string	SaveGame::ConstCharByInt(int x) const
{
  std::stringstream tmp;

  tmp.clear();
  tmp << x;
  return tmp.str();
}

std::string	SaveGame::ConstCharByDouble(double x) const
{
  std::stringstream tmp;

  tmp.clear();
  tmp << x;
  return tmp.str();
}

void		SaveGame::SaveDefaultBomb(AObjectPhysic *Aobj)
{
  DefaultBomb	*obj;
  APlayer	*player;

  obj = (DefaultBomb *)Aobj;
  _obj = new TiXmlElement("Map");
  _obj->SetAttribute("object", "defaultbomb");
  _obj->SetAttribute("id", ConstCharByInt(obj->getId()).c_str());
  _obj->SetAttribute("x", ConstCharByFloat(obj->get_x()).c_str());
  _obj->SetAttribute("y", ConstCharByFloat(obj->get_y()).c_str());
  _obj->SetAttribute("z", ConstCharByFloat(obj->get_z()).c_str());
  _obj->SetAttribute("po", ConstCharByInt(obj->getPo()).c_str());
  _obj->SetAttribute("damage", ConstCharByInt(obj->getDamage()).c_str());
  _obj->SetAttribute("time", ConstCharByInt(obj->getTime()).c_str());
  _obj->SetAttribute("playercoll", ConstCharByInt(obj->getPlayerColl()).c_str());
  _obj->SetAttribute("died", ConstCharByInt(obj->getDied()).c_str());
  player = obj->getPlayer();
  _obj->SetAttribute("id_player", ConstCharByInt(player->getId()).c_str());
  _bomberman->LinkEndChild(_obj);
}

void		SaveGame::SaveDefaultFire(AObjectPhysic *Aobj)
{
  DefaultFire	*fire;

  fire = (DefaultFire *)Aobj;
  _obj = new TiXmlElement("Map");
  _obj->SetAttribute("object", "fire");
  _obj->SetAttribute("id", ConstCharByInt(fire->getId()).c_str());
  _obj->SetAttribute("x", ConstCharByFloat(fire->get_x()).c_str());
  _obj->SetAttribute("y", ConstCharByFloat(fire->get_y()).c_str());
  _obj->SetAttribute("z", ConstCharByFloat(fire->get_z()).c_str());
  _obj->SetAttribute("time", ConstCharByInt(fire->getTime()).c_str());
  _obj->SetAttribute("damage", ConstCharByInt(fire->getDamage()).c_str());
  _obj->SetAttribute("idbomb", ConstCharByInt(fire->getBombId()).c_str());
  this->SavePlayerInFire((AFire *)fire);
}

void		SaveGame::SavePlayerInFire(AFire *fire)
{
  std::vector<APlayer *> *playerTouched;
  std::vector<APlayer *>::iterator it;
  std::string	idPlayer;
  int		id;

  playerTouched = fire->getPlayerTouched();
  it = playerTouched->begin();
  while (it != playerTouched->end())
    {
      id = (*it)->getId();
      if (it + 1 != playerTouched->end())
	idPlayer = idPlayer + ConstCharByInt(id) + ",";
      else
	idPlayer = idPlayer + ConstCharByInt(id);
      it++;
    }
  _obj->SetAttribute("ID_PLAYER", idPlayer.c_str());
  _bomberman->LinkEndChild(_obj);
}

void		SaveGame::SavePlayer()
{
  Player	*obj;

  obj = _map->getPlayer();
  _obj = new TiXmlElement("Player");
  _obj->SetAttribute("object", "player");
  _obj->SetAttribute("id", ConstCharByInt(obj->getId()).c_str());
  _obj->SetAttribute("x", ConstCharByFloat(obj->get_x()).c_str());
  _obj->SetAttribute("y", ConstCharByFloat(obj->get_y()).c_str());
  _obj->SetAttribute("z", ConstCharByFloat(obj->get_z()).c_str());
  _obj->SetAttribute("po", ConstCharByInt(obj->getPo()).c_str());
  _obj->SetAttribute("life", ConstCharByInt(obj->getLife()).c_str());
  _obj->SetAttribute("nbrMaxBomb", ConstCharByInt(obj->getNbrMaxBomb()).c_str());
  _obj->SetAttribute("nbrCurrentBomb", ConstCharByInt(obj->getNbrBomb()).c_str());
  _obj->SetAttribute("rot_x", ConstCharByDouble(obj->get_rotx()).c_str());
  _obj->SetAttribute("rot_y", ConstCharByDouble(obj->get_roty()).c_str());
  _obj->SetAttribute("rot_z", ConstCharByDouble(obj->get_rotz()).c_str());
  _bomberman->LinkEndChild(_obj);
}

void		SaveGame::SaveBonusBomb(AObjectPhysic *Aobj)
{
  BombBonus	*obj;

  obj = (BombBonus *)Aobj;
  _obj = new TiXmlElement("Map");
  _obj->SetAttribute("object", "bonusbomb");
  _obj->SetAttribute("id", ConstCharByInt(obj->getId()).c_str());
  _obj->SetAttribute("x", ConstCharByFloat(obj->get_x()).c_str());
  _obj->SetAttribute("y", ConstCharByFloat(obj->get_y()).c_str());
  _obj->SetAttribute("z", ConstCharByFloat(obj->get_z()).c_str());
  _obj->SetAttribute("died", ConstCharByInt(obj->getDied()).c_str());
  _bomberman->LinkEndChild(_obj);
}

void		SaveGame::SaveBonusPo(AObjectPhysic *Aobj)
{
  PoBonus	*obj;

  obj = (PoBonus *)Aobj;
  _obj = new TiXmlElement("Map");
  _obj->SetAttribute("object", "bonuspo");
  _obj->SetAttribute("id", ConstCharByInt(obj->getId()).c_str());
  _obj->SetAttribute("x", ConstCharByFloat(obj->get_x()).c_str());
  _obj->SetAttribute("y", ConstCharByFloat(obj->get_y()).c_str());
  _obj->SetAttribute("z", ConstCharByFloat(obj->get_z()).c_str());
  _obj->SetAttribute("died", ConstCharByInt(obj->getDied()).c_str());
  _bomberman->LinkEndChild(_obj);
}

void		SaveGame::SaveDefaultWall(AObjectPhysic *Aobj)
{
  DefaultWall	*obj;

  obj = (DefaultWall *)Aobj;
  _obj = new TiXmlElement("Map");
  _obj->SetAttribute("object", "defaultwall");
  _obj->SetAttribute("id", ConstCharByInt(obj->getId()).c_str());
  _obj->SetAttribute("x", ConstCharByFloat(obj->get_x()).c_str());
  _obj->SetAttribute("y", ConstCharByFloat(obj->get_y()).c_str());
  _obj->SetAttribute("z", ConstCharByFloat(obj->get_z()).c_str());
  _bomberman->LinkEndChild(_obj);
}

void		SaveGame::SaveDestructWall(AObjectPhysic *Aobj)
{
  DestrucWall	*obj;

  obj = (DestrucWall *)Aobj;
  _obj = new TiXmlElement("Map");
  _obj->SetAttribute("object", "destrucwall");
  _obj->SetAttribute("id", ConstCharByInt(obj->getId()).c_str());
  _obj->SetAttribute("x", ConstCharByFloat(obj->get_x()).c_str());
  _obj->SetAttribute("y", ConstCharByFloat(obj->get_y()).c_str());
  _obj->SetAttribute("z", ConstCharByFloat(obj->get_z()).c_str());
  _obj->SetAttribute("life", ConstCharByInt(obj->getLife()).c_str());
  _bomberman->LinkEndChild(_obj);
}

void		SaveGame::setObjMap()
{
  std::list<AObjectPhysic *> tmp;
  std::list<AObjectPhysic *>::iterator it;
  std::map<TypeObjectPrecis, void(SaveGame::*)(AObjectPhysic *) >::iterator i;

  tmp = _map->getObject();
  it = tmp.begin();
  while (it != tmp.end())
    {
      i = _mapObject.find((*it)->getTypePrecis());
      if (i != _mapObject.end())
	{
	  (this->*_mapObject[(*it)->getTypePrecis()])((*it));
	}
      it++;
    }
}

void	SaveGame::SaveMapSize()
{
  std::stringstream widht;
  std::stringstream height;

  widht << _map->getWidth();
  height << _map->getHeight();
  _mapSize = new TiXmlElement("Map_Size");
  _mapSize->SetAttribute("width", widht.str().c_str());
  _mapSize->SetAttribute("height", height.str().c_str());
  _bomberman->LinkEndChild(_mapSize);
}

SaveGame::~SaveGame()
{
  std::map<TypeObjectPrecis, void(SaveGame::*)(AObjectPhysic*) >::iterator it;

  for (it = _mapObject.begin(); it != _mapObject.end(); ++it)
    _mapObject.erase(it);
}
