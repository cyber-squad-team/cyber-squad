#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<time.h>
#include<string.h>



void menuoption(options *opt,int *continu,background back,selection selec){
int continuer=1;int x=-1;
affichageoptions(x,*opt,back,selec);
Mix_PlayMusic(opt->music,-1);
SDL_Event event;
while (continuer)
{
while (SDL_PollEvent(&event))
{switch (event.type)
{
case SDL_QUIT:
    continuer=0;
    *continu=0;
    break;

case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_UP:
x=next(x,7,1);
affichageoptions(x,*opt,back,selec);
    break;

case SDLK_DOWN:
x=next(x,7,0);
affichageoptions(x,*opt,back,selec);
break;

case SDLK_RETURN :
if(x==0){menuresolution(opt, continu, &continuer, back,selec);}
else if((x==1)&&(opt->soundlv!=6)){opt->soundlv++;affichageoptions(x,*opt,back,selec);  Mix_Volume(1,150-25*(6-opt->soundlv));}
else if((x==2)&&(opt->soundlv!=0)){opt->soundlv--;affichageoptions(x,*opt,back,selec);Mix_Volume(1,150-25*(6-opt->soundlv));}
else if(x==3){maininput(*opt,continu,&continuer,back,selec);}
else if(x==4){
    opt->music=!opt->music; 
    if(opt->music==0){opt->oldsoundlv=opt->soundlv;opt->soundlv=0;}else{opt->soundlv=opt->oldsoundlv;}
    affichageoptions(x,*opt,back,selec);Mix_Volume(1,0);
    }
else if(x==5){opt->effect=!opt->effect; 
  if(opt->effect==0)
{/*Mix_VolumeChunk(opt->son,0);*/}else{/*Mix_VolumeChunk(opt->son,MIX_MAX_VOLUME/2);*/} 
affichageoptions(x,*opt,back,selec);}
else if(x==6){continuer=0;x=-1;affichage(x,selec,back,*opt);}
break;

}break;}








}}}





void affichageoptions(int x,options opt,background back,selection selec){
selec.posselectleft.x=1242;int y=5;
selec.posselectright.x=555;
SDL_Surface *imageright,*imageleft;
imageright=selec.selectionsmallright;
imageleft=selec.selectionsmallleft;
if(x==0){
selec.posselectleft.y=317;
selec.posselectright.y=317;
imageright=selec.selectionbigright;
imageleft=selec.selectionbigleft;
}
else if (x==1){
selec.posselectleft.x=1365;
selec.posselectleft.y=563;
y=1;

}
else if(x==2){
y=0;
selec.posselectright.x=483;
selec.posselectright.y=569;
}
else if(x==3){
selec.posselectleft.y=733;
selec.posselectright.y=733; 
imageright=selec.selectionbigright;
imageleft=selec.selectionbigleft;
}
else if(x==4){
selec.posselectleft.x=1822;
selec.posselectright.x=1583;
selec.posselectleft.y=966;
selec.posselectright.y=966;
}
else if(x==5){
selec.posselectleft.x=1029;
selec.posselectright.x=790;
selec.posselectleft.y=966;
selec.posselectright.y=966;
}
else if(x==6){
selec.posselectleft.x=243;
selec.posselectright.x=10;
selec.posselectleft.y=966;
selec.posselectright.y=966;}

SDL_BlitSurface(back.background[1],NULL,opt.resolution,&(back.posbackground));
if(x!=-1){
if(y!=1)SDL_BlitSurface(imageright,NULL,opt.resolution,&(selec.posselectright));
if(y!=0)SDL_BlitSurface(imageleft,NULL,opt.resolution,&(selec.posselectleft));
}
if(opt.music==0){SDL_BlitSurface(selec.nosound,NULL,opt.resolution,&(selec.posnosound));}
if(opt.effect==0){SDL_BlitSurface(selec.noeffect,NULL,opt.resolution,&(selec.posnoeffect));}
for(int i=0;i<opt.soundlv;++i){
SDL_BlitSurface(selec.sound[i],NULL,opt.resolution,&(selec.possound[i]));}


SDL_Flip(opt.resolution);
}