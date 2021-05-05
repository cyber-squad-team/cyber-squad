#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<time.h>
#include<string.h>




void main(int argc,char *argv[]){
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *ecran;
ecran=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
mainmenu(ecran);
SDL_Quit();
}