#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<time.h>
#include<string.h>



void menuresolution(options *opt,int *continu,int *continuu,background back,selection selec){
int continuer=1;int x=-1;affichageresolution(x,*opt,back,selec);
SDL_Event event;
while (continuer)
{
while (SDL_PollEvent(&event))
{switch (event.type)
{
case SDL_QUIT:
*continuu=0;
continuer=0;
*continu=0;
break;

case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_UP:
x=next(x,3,1);
affichageresolution(x,*opt,back,selec);
    break;

case SDLK_DOWN:
x=next(x,3,0);
affichageresolution(x,*opt,back,selec);

break;

case SDLK_RETURN :
if((x==0)&&(opt->re!=0)){opt->re=0;affichageresolution(x,*opt,back,selec);}
else if((x==1)&&(opt->re!=0)){opt->re=1;affichageresolution(x,*opt,back,selec);}
else if(x==2){continuer=0;x=-1;affichageoptions(x,*opt,back,selec);}
break;

}break;}

}}}
void affichageresolution(int x,options opt,background back,selection selec){
SDL_BlitSurface(back.background[4],NULL,opt.resolution,&(back.posbackground));
if(opt.re==0){selec.posmark.x=0;
              selec.posmark.y=0;
    SDL_BlitSurface(selec.mark,NULL,opt.resolution,&(selec.posmark));}
else{selec.posmark.x=0;
    selec.posmark.y=0;SDL_BlitSurface(selec.mark,NULL,opt.resolution,&(selec.posmark)); }



SDL_Flip(opt.resolution);


}