#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<time.h>
#include<string.h>


void menuresolution(options *opt,int *continu,int *continuu,background back,selection selec){
int continuer=1;int x=-1;affichageresolution(x,*opt,back,selec);
SDL_Event event;int oldvaluex=5;
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
    case SDL_MOUSEMOTION:
    
  oldvaluex=x;
  x=mouseposresolution(event.motion.x,event.motion.y);
if((x!=-1)&&(x!=oldvaluex)) {affichageresolution(x,*opt,back,selec);}
break;
case SDL_MOUSEBUTTONDOWN:
if((x==0)&&(opt->re!=0)){opt->re=0;affichageresolution(x,*opt,back,selec);}
else if((x==1)&&(opt->re!=1)){opt->re=1;affichageresolution(x,*opt,back,selec);}
else if(x==2){continuer=0;x=-1;affichageoptions(x,*opt,back,selec);}
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
else if((x==1)&&(opt->re!=1)){opt->re=1;affichageresolution(x,*opt,back,selec);}
else if(x==2){continuer=0;x=-1;affichageoptions(x,*opt,back,selec);}
break;

}break;}

}}}

void affichageresolution(int x,options opt,background back,selection selec){
    Mix_PlayChannel(-1, opt.son, 0);
SDL_BlitSurface(back.background[4],NULL,opt.resolution,&(back.posbackground));
int y=1;
if(opt.re==0){selec.posmark.x=1410;
              selec.posmark.y=500;}
else{selec.posmark.x=1410;
    selec.posmark.y=660;}
SDL_BlitSurface(selec.mark,NULL,opt.resolution,&(selec.posmark));
selec.posselectleft.x=1539;

SDL_Surface *imager,*imagel;
imagel=selec.selectionsmallleft;
imager=selec.selectionsmallright;
if(x==0){
selec.posselectleft.y=486;
}else if(x==1){
selec.posselectleft.y=640;
}else if(x==2){
selec.posselectleft.x=243;
selec.posselectright.x=10;
selec.posselectleft.y=966;
selec.posselectright.y=966;
imagel=selec.selectionsmallleft;
imager=selec.selectionsmallright;y=0;
}
if(x!=-1){
SDL_BlitSurface(imagel,NULL,opt.resolution,&(selec.posselectleft));
if(y==0)SDL_BlitSurface(imager,NULL,opt.resolution,&(selec.posselectright));}



SDL_Flip(opt.resolution);


}

int mouseposresolution(int x,int y){
if((1400<=x)&&(x<=1533)){
if((463<=y)&&(y<=605)){return 0;}
else if((631<=y)&&(y<=771)){return 1;}}
else if((111<=x)&&(x<=244)&&(941<=y)&&(y<=1042)){return 2;}



return -1;}