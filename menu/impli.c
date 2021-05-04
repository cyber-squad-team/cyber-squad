#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<time.h>
#include<string.h>



void mainmenu(){
int continuer=1,x=-1;background back;selection selec;options opt;
opt=initialisation_parametre();
back=initialisation_background();
selec=initialisation_boutons();
SDL_Event event;affichage(x,selec,back,opt);


while (continuer)
{while(SDL_PollEvent(&event)){

switch (event.type)
{
case SDLK_ESCAPE:
    continuer=0;
    break;
    case SDL_QUIT:
    continuer=0;
    break;
  

case  SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_UP:
x=next(x,3,1);
affichage(x,selec,back,opt);
    break;

case SDLK_DOWN:
x=next(x,3,0);
affichage(x,selec,back,opt);
break;
case SDLK_RETURN:
if(x==0){menuplay(&opt,&continuer,back,selec);}
else if(x==1){menuoption(&opt,&continuer,back,selec);}
else {continuer=0;}
break;





}break;






}}}}

options initialisation_parametre(){
options a;
a.resolution=SDL_SetVideoMode(1920, 1080,32, SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_RESIZABLE);
a.effect=1;
a.music=1;
a.soundlv=4;
a.son=Mix_LoadWAV("BREF.wav");
a.musique=Mix_LoadMUS("sound/music2.mp3");
a.re=0;
a.nbdjoueur=1;
/*a.inpu[1].right=275;
a.inpu[1].left=276;
a.inpu[1].jump=273;
a.inpu[1].spedd=32;
a.inpu[2].right=100;
a.inpu[2].left=113;
a.inpu[2].jump=122;
a.inpu[2].spedd=102;*/
return a;}




int next(int x,int nbb,int updown){
if(updown==0){
(x)++;if((x)==nbb||((x)==-1)){(x)=0;}}
else{(x)--;
if(((x)==-2)||((x)==-1)){(x)=nbb-1;}}
return x ;}

void affichage(int x,selection selec,background back,options opt){
selec.posselectleft.x=1243;
selec.posselectright.x=557;
if(x==0){
selec.posselectleft.y=340;
selec.posselectright.y=340;}
else if(x==1)
{selec.posselectleft.y=561;
selec.posselectright.y=560;}
else if(x==2)
{selec.posselectleft.y=778;
selec.posselectright.y=778;}

SDL_BlitSurface(back.background[0],NULL,opt.resolution,&(back.posbackground));

if(x!=-1){SDL_BlitSurface(selec.selectionbigright,NULL,opt.resolution,&(selec.posselectright));
SDL_BlitSurface(selec.selectionbigleft,NULL,opt.resolution,&(selec.posselectleft));
}
SDL_Flip(opt.resolution);

}


background initialisation_background(){
background a;
a.background[0]=IMG_Load("photos/mainmenu/no selection.png");
a.background[1]=IMG_Load("photos/options/no selection.png");
a.background[2]=IMG_Load("photos/options/input/common/nono.png");
a.background[3]=IMG_Load("photos/play/no selection.png");
a.background[4]=IMG_Load("photos/options/resolution/no selection.png");
a.background[5]=IMG_Load("photos/play/new game/no_selection1.png");
a.posbackground.x=0;
a.posbackground.y=0;

return a;
}
selection initialisation_boutons(){
selection a;
a.selectionsmallright=IMG_Load("photos/selection element/small2.png");
a.selectionsmallleft=IMG_Load("photos/selection element/small.png");
a.selectionbigright=IMG_Load("photos/selection element/big.png");
a.selectionbigleft=IMG_Load("photos/selection element/big2.png");
a.nosound=IMG_Load("photos/options/no music.png");
a.noeffect=IMG_Load("photos/options/no music effect.png");
a.sound[0]=IMG_Load("photos/options/son animation/1son.png");
a.sound[1]=IMG_Load("photos/options/son animation/2son.png");
a.sound[2]=IMG_Load("photos/options/son animation/3son.png");
a.sound[3]=IMG_Load("photos/options/son animation/4son.png");
a.sound[4]=IMG_Load("photos/options/son animation/5son.png");
a.sound[5]=IMG_Load("photos/options/son animation/6son.png");
a.mark=IMG_Load("photos/options/resolution/mark.png");
a.possound[0].x=720;
a.possound[0].y=529;
a.possound[1].x=809;
a.possound[1].y=530;
a.possound[2].x=883;
a.possound[2].y=529;
a.possound[3].x=982;
a.possound[3].y=529;
a.possound[4].x=1068;
a.possound[4].y=529;
a.possound[5].x=1151;
a.possound[5].y=529;
a.posnoeffect.x=905;
a.posnoeffect.y=966;
a.posnosound.x=1680;
a.posnosound.y=966;
return a;
}