#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include	<unistd.h>
#include <iostream>
void ok();

int main(int argc,char **argv)
{
  int i;
  SDL_Joystick *joystick = NULL;

  SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_VIDEO);
  printf("Il y a %d joysticks détectés\n", SDL_NumJoysticks());
  for(i=0;i<SDL_NumJoysticks();i++) printf("----> %d = %s\n",i,SDL_JoystickName(i));
  SDL_JoystickEventState(SDL_ENABLE);
  joystick = SDL_JoystickOpen(0);
  printf("\n");
  printf("----> %d boutons\n", SDL_JoystickNumButtons(joystick));
  printf("----> %d axes\n", SDL_JoystickNumAxes(joystick));
  ok();
  SDL_JoystickClose(joystick);
  SDL_Quit();
  return EXIT_SUCCESS;
}

void ok()
{
  int	i;
  SDL_Event event;
  int	continuer = 0;

  while(continuer == 0)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
        {
	case SDL_JOYAXISMOTION:
	  if (event.jaxis.which == 0)
	    {
	      if (event.jaxis.axis == 5 && event.jaxis.value < -2000)
		{

		  /*		  if( ( event.jaxis.value > -8000 ) && ( event.jaxis.value < 8000 ) )
		    {
		      printf("X = 0\n");
		    }
		    else*/
		    printf("left %d  \n", event.jaxis.value);
		}
	      //	      if (event.jaxis.axis == 0)
	      //		    printf("left %d  \n", event.jaxis.value);
	      if (event.jaxis.axis == 0 && event.jaxis.value > 2000)
		{

		  /*		  if( ( event.jaxis.value > -8000 ) && ( event.jaxis.value < 8000 ) )
		    {
		      printf("X = 0\n");
		    }
		    else*/
		    printf("droite %d \n  ", event.jaxis.value);
		}
	      if (event.jaxis.axis == 1 && event.jaxis.value < -2000)
		{

		  /*		  if( ( event.jaxis.value > -8000 ) && ( event.jaxis.value < 8000 ) )
		    {
		      printf("X = 0\n");
		    }
		    else*/
		  //printf("bas %d  \n", event.jaxis.value);
		}
	      if (event.jaxis.axis == 1 && event.jaxis.value > 2000)
		{

		  /*		  if( ( event.jaxis.value > -8000 ) && ( event.jaxis.value < 8000 ) )
		    {
		      printf("X = 0\n");
		    }
		    else*/
		  // printf("haut %d \n  ", event.jaxis.value);
		}
	      else if (event.jaxis.axis == 1)
		{
		  /*if( ( event.jaxis.value > -8000 ) && ( event.jaxis.value < 8000 ) )
		    {
		      printf("Y = 0\n");
		    }
		    else*/
		  //  printf("Y = %d ", event.jaxis.value);
		}
	      //	      printf("\n");
	      //sleep(1);
	      break;
	    }
	case SDL_JOYBUTTONDOWN:
	  if (event.jbutton.button == 0)
	    {
	      printf("QUITTER\n");
	      continuer = 1;
	    }
	  break;
	}
    }
}
