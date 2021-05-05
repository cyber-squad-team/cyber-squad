#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<time.h>
#include<string.h>



void menuloadgame(options *opt,int *continu,int *continuu,background back,selection selec){
int continuer=1;int x=-1;affichageloadgame(x,*opt,back,selec);
SDL_Event event;int oldvaluex=5;
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
    case SDL_MOUSEMOTION:
    
  oldvaluex=x;
  x=mouseposload(event.motion.x,event.motion.y);
if((x!=-1)&&(x!=oldvaluex)) {affichageloadgame(x,*opt,back,selec);}
break;
case SDL_MOUSEBUTTONDOWN:{
if(x==0){opt->nbdjoueur=1;affichageloadgame(x,*opt,back,selec);}
else if(x==1){opt->nbdjoueur=2;affichageloadgame(x,*opt,back,selec); }
else if(x==2){ }
else if(x==3){continuer=0;x=-1;affichageplay(x,*opt,back,selec);}
break;



}
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
if(x==0){opt->nbdjoueur=1;affichageloadgame(x,*opt,back,selec);}
else if(x==1){opt->nbdjoueur=2;affichageloadgame(x,*opt,back,selec); }
else if(x==2){ }
else if(x==3){continuer=0;x=-1;affichageplay(x,*opt,back,selec);}
break;

}break;}

}}}
int mouseposload(int x,int y){
if((1229<=x)&&(x<=1369)){
if((396<=y)&&(y<=446)){return 0;}
else if((555<=y)&&(y<=690)){return 1;}}
if((801<=y)&&(y<=995)&&(651<=x)&&(x<=1216)){return 2;}
if((111<=x)&&(x<=244)&&(941<=y)&&(y<=1042)){return 3;}

return -1;}
void affichageloadgame(int x,options opt,background back,selection selec){
    Mix_PlayChannel(-1, opt.son, 0);
SDL_BlitSurface(back.background[5],NULL,opt.resolution,&(back.posbackground));
selec.posselectleft.x=1350;int y=1;
selec.posselectright.x=558;
SDL_Surface *imager,*imagel;
imagel=selec.selectionsmallleft;
imager=selec.selectionsmallright;
if(x==0){
selec.posselectleft.y=350;y=0;
}else if(x==1){
selec.posselectleft.y=504;y=0;
}
else if(x==2){
selec.posselectleft.x=1220;
selec.posselectright.x=520;
selec.posselectleft.y=700;
selec.posselectright.y=700;
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
if(y!=0){SDL_BlitSurface(imager,NULL,opt.resolution,&(selec.posselectright));}
}
if(opt.nbdjoueur==1){selec.posmark.x=1219;
                     selec.posmark.y=367;}
else{selec.posmark.x=1225;
    selec.posmark.y=520;}
    SDL_BlitSurface(selec.mark,NULL,opt.resolution,&(selec.posmark));
SDL_Flip(opt.resolution);
}