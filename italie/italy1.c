#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "italy1.h"

int italy1(void)
{

SDL_Surface *screen=NULL; SDL_Surface *italy1=NULL; SDL_Surface *repo1=NULL; SDL_Surface *repo2=NULL; SDL_Surface *repo3=NULL; 
SDL_Rect pos_enigme,pos1,pos2,pos3;

SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(900,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
if(!screen)
{printf("unabe to set 600x400 video: %s\n",SDL_GetError());}
italy1 = IMG_Load("question 1.png");
if(!italy1)
{printf("unable to load enigme1: %s\n" ,SDL_GetError());}

repo1= IMG_Load("Q1 vrai.png");
if(!repo1)
{printf("unable to load : %s\n" ,SDL_GetError());}

repo2= IMG_Load("Q1 faux.png");
if(!repo2)
{printf("unable to load: %s\n" ,SDL_GetError());}

repo3= IMG_Load("Q1 faux2.png");
if(!repo3)
{printf("unable to load: %s\n" ,SDL_GetError());}


pos_enigme.x=0; 
pos_enigme.y=0; 

pos1.x=130; pos1.y=180;
pos2.x=130; pos2.y=70;
pos3.x=130 ; pos3.y=300;

SDL_BlitSurface(italy1,NULL,screen,&pos_enigme);
SDL_BlitSurface(repo1,NULL,screen,&pos1);
SDL_BlitSurface(repo2,NULL,screen,&pos2);
SDL_BlitSurface(repo3,NULL,screen,&pos3);
SDL_Flip(screen);
SDL_Event event;
int done=1;

while(done)
{ 
SDL_BlitSurface(italy1,NULL,screen,&pos_enigme);
SDL_BlitSurface(repo1,NULL,screen,&pos1);
SDL_BlitSurface(repo2,NULL,screen,&pos2);
SDL_BlitSurface(repo3,NULL,screen,&pos3);


  SDL_WaitEvent(&event);
  switch(event.type)
{
  case SDL_KEYDOWN :
  switch(event.key.keysym.sym)
   {
     case SDLK_ESCAPE :
     done=0;
     break;
     case SDLK_b : 
     return 1;
     break; 
    default:
    return 0; 
    }
   break;
   case SDL_MOUSEBUTTONUP :
   switch(event.button.button)
  {
   case SDL_BUTTON_LEFT :
    if (event.button.x>pos1.x && event.button.x<pos1.x+pos1.w &&event.button.y>pos1.y &&event.button.y<pos1.y+pos1.h)
{
 return 1;
}

else 
{
 return 0;
}
break;
}
break;
}
}

SDL_FreeSurface(italy1);
SDL_FreeSurface(repo1);
SDL_FreeSurface(repo2);
SDL_FreeSurface(repo3);
return 0;
}
