//
// test.cpp for test in /home/choqua_m/projets/video
// 
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
// 
// Started on  Wed Jun 11 15:32:07 2014 Mathieu Choquart
// Last update Sat Jun 14 22:51:00 2014 Mathieu Choquart
//

#include		<stdio.h>
#include		<stdlib.h>
#include		<iostream>
#include		<vlc/vlc.h>
 
void			intro_game()
{
  libvlc_instance_t	*instance;
  libvlc_media_player_t	*player;
  libvlc_media_t	*media;
  
  instance = libvlc_new (0, NULL);
  media = libvlc_media_new_path (instance, "intro.avi");
  player = libvlc_media_player_new_from_media (media);
  libvlc_media_release (media);
  libvlc_media_player_play (player);
  sleep(33);
  libvlc_media_player_stop (player);
  libvlc_media_player_release (player);
  libvlc_release (instance);
}
