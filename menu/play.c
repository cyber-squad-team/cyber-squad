#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<time.h>
#include<string.h>



void menuplay(options *opt,int *continuu,background back,selection selec){
int continuer=1;int x=-1;affichageplay(x,*opt,back,selec);
SDL_Event event;
while (continuer)
{
while (SDL_PollEvent(&event))
{switch (event.type)
{
case SDL_QUIT:
*continuu=0;
continuer=0;

break;

case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_UP:
x=next(x,3,1);
affichageplay(x,*opt,back,selec);
    break;

case SDLK_DOWN:
x=next(x,3,0);
affichageplay(x,*opt,back,selec);

break;

case SDLK_RETURN :
if(x==0){menuloadgame(opt,&continuer,continuu, back,selec);}
else if(x==1){}
else if(x==2){continuer=0;x=-1;affichage(x,selec,back,*opt);}
break;

}break;}

}}}
void affichageplay(int x,options opt,background back,selection selec){
SDL_BlitSurface(back.background[3],NULL,opt.resolution,&(back.posbackground));
selec.posselectleft.x=1239;
selec.posselectright.x=558;
SDL_Surface *imager,*imagel;
imagel=selec.selectionbigleft;
imager=selec.selectionbigright;
if(x==0){
selec.posselectleft.y=460;
selec.posselectright.y=460;
}else if(x==1){
selec.posselectleft.y=677;
selec.posselectright.y=677;
}else if(x==2){
selec.posselectleft.x=243;
selec.posselectright.x=10;
selec.posselectleft.y=966;
selec.posselectright.y=966;
imagel=selec.selectionsmallleft;
imager=selec.selectionsmallright;
}
if(x!=-1){
SDL_BlitSurface(imagel,NULL,opt.resolution,&(selec.posselectleft));
SDL_BlitSurface(imager,NULL,opt.resolution,&(selec.posselectright));}
SDL_Flip(opt.resolution);




SDL_Flip(opt.resolution);


}