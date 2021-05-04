#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<time.h>
#include<string.h>



void menuloadgame(options *opt,int *continu,int *continuu,background back,selection selec){
int continuer=1;int x=-1;affichageloadgame(x,*opt,back,selec);
SDL_Event event;
while (continuer)
{
while (SDL_PollEvent(&event))
{switch (event.type)
{
case SDL_QUIT:
*continuu=0;
*continu=0;
continuer=0;

break;

case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_UP:
x=next(x,4,1);
affichageloadgame(x,*opt,back,selec);
    break;

case SDLK_DOWN:
x=next(x,4,0);
affichageloadgame(x,*opt,back,selec);

break;

case SDLK_RETURN :
if(x==0){}
else if(x==1){ opt->nbdjoueur=1;affichageloadgame(x,*opt,back,selec);}
else if(x==2){ opt->nbdjoueur=2;affichageloadgame(x,*opt,back,selec);}
else if(x==3){continuer=0;x=-1;affichageplay(x,*opt,back,selec);}
break;

}break;}

}}}
void affichageloadgame(int x,options opt,background back,selection selec){
SDL_BlitSurface(back.background[5],NULL,opt.resolution,&(back.posbackground));
selec.posselectleft.x=1370;int y=1;
selec.posselectright.x=558;
SDL_Surface *imager,*imagel;
imagel=selec.selectionsmallleft;
imager=selec.selectionsmallright;
if(x==0){
selec.posselectleft.y=418;y=0;
}else if(x==1){
selec.posselectleft.y=572;y=0;
}
else if(x==2){
selec.posselectleft.x=1233;
selec.posselectright.x=650;
selec.posselectleft.y=820;
selec.posselectright.y=820;
imagel=selec.selectionbigleft;
imager=selec.selectionbigright;
}
else if(x==3){
selec.posselectleft.x=243;
selec.posselectright.x=10;
selec.posselectleft.y=966;
selec.posselectright.y=966;}
if(x!=-1){
SDL_BlitSurface(imagel,NULL,opt.resolution,&(selec.posselectleft));
if(y!=0){SDL_BlitSurface(imager,NULL,opt.resolution,&(selec.posselectright));}}
if(opt.nbdjoueur==1){selec.posmark.x=1380;
              selec.posmark.y=500;}
else{selec.posmark.x=1380;
    selec.posmark.y=660;}
    SDL_BlitSurface(selec.mark,NULL,opt.resolution,&(selec.posmark));
SDL_Flip(opt.resolution);


}