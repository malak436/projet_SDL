#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_ttf.h>

int main ()
{
SDL_Surface *ecran;
SDL_Init(SDL_INIT_EVERYTHING);
ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

int tabl[30];
enigme tableau[8];
int j;
int r=1;

init_enigmes(tabl,tableau);


j=generer_enigmes(tabl);
r=saisir(ecran,tableau,j);
if(r==0)
printf("right\n");
else 
printf("wrong\n");


return 0;
}







