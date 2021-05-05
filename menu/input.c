#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<time.h>
#include<string.h>
void maininput(options opt,int *continuerr,int *continuerrr,background back,selection selec){
int continuer=1,x=-1;input in;in=initialisationimagesinput();
SDL_Event event;selectioninput(x,opt,in,back,selec);int oldvaluex=10;
while (continuer)
{while(SDL_PollEvent(&event)){

switch (event.type)
{
case SDLK_ESCAPE:
    continuer=0;
    break;
    case SDL_QUIT:
continuer=0;
*continuerrr=0;
*continuerr=0;
    break;
 
            case SDL_MOUSEMOTION:
    
  oldvaluex=x;
  x=mouseinput(event.motion.x,event.motion.y);
if((x!=-1)&&(x!=oldvaluex)) {selectioninput(x,opt,in,back,selec);}
break;

            case SDL_MOUSEBUTTONDOWN:
            if(x==0){}
else if(x==1){}
else if(x==2){}
else if(x==3){}
else if(x==4){}
else if(x==5){}
else if(x==6) {continuer=0;x=-1;affichageoptions(x,opt,back,selec);}
            break;
       
  


case  SDL_KEYDOWN:

switch (event.key.keysym.sym)
{
case SDLK_UP:
x=next(x,7,1);
selectioninput(x,opt,in,back,selec);
break;

case SDLK_DOWN:
x=next(x,7,0);
selectioninput(x,opt,in,back,selec);
break;

case SDLK_RETURN:
if(x==0){}
else if(x==1){}
else if(x==2){}
else if(x==3){}
else if(x==4){}
else if(x==5){}
else if(x==6) {continuer=0;x=-1;affichageoptions(x,opt,back,selec);}
break;

}break;
}}}

}
input initialisationimagesinput(){
input a;
a.d=IMG_Load("photos/options/input/2player/d.png");
a.z=IMG_Load("photos/options/input/2player/z.png");
a.q=IMG_Load("photos/options/input/2player/q.png");
a.s=IMG_Load("photos/options/input/2player/s.png");
a.back=IMG_Load("photos/options/input/2player/back.png");
a.right=IMG_Load("photos/options/input/2player/right.png");
a.left=IMG_Load("photos/options/input/2player/left.png");
a.jump=IMG_Load("photos/options/input/2player/forword.png");
a.secondplayer=IMG_Load("photos/options/input/2player/second player.png");
a.posd.x=0;
a.posd.y=0;
a.posjump.y=0;
a.poss.y=0;
a.posq.y=0;
a.poss.y=0;
a.posback.y=0;
a.posright.y=0;
a.posleft.y=0;
a.posjump.y=0;
a.possecondplayer.x=0;
a.possecondplayer.y=0;
return a;}


void affichageinput(input a,options opt){
SDL_BlitSurface(a.d,NULL,opt.resolution,&(a.posd));
SDL_BlitSurface(a.z,NULL,opt.resolution,&(a.posz));
SDL_BlitSurface(a.q,NULL,opt.resolution,&(a.posq));
SDL_BlitSurface(a.s,NULL,opt.resolution,&(a.poss));
SDL_BlitSurface(a.back,NULL,opt.resolution,&(a.posback));
SDL_BlitSurface(a.right,NULL,opt.resolution,&(a.posright));
SDL_BlitSurface(a.left,NULL,opt.resolution,&(a.posleft));
SDL_BlitSurface(a.jump,NULL,opt.resolution,&(a.posjump));
SDL_BlitSurface(a.secondplayer,NULL,opt.resolution,&(a.possecondplayer));

}





void selectioninput(int x,options opt,input in,background back,selection selec){
    Mix_PlayChannel(-1, opt.son, 0);
SDL_BlitSurface(back.background[2],NULL,opt.resolution,&(back.posbackground));
selec.posselectleft.x=1351;int y=1;
selec.posselectright.x=575;
SDL_Surface *imager,*imagel;
imagel=selec.selectionsmallleft;
imager=selec.selectionsmallright;
if(x==0){
y=0;
selec.posselectleft.y=600;
selec.posselectleft.x=580;
selec.posselectright.y=600;
selec.posselectright.x=-40;
}else if(x==1){
selec.posselectleft.y=267;

}else if(x==2){
selec.posselectleft.y=423;


}else if(x==3){
selec.posselectleft.y=590;


}else if(x==4){
selec.posselectleft.y=750;


}else if(x==5){
selec.posselectleft.y=919;


}else  if(x==6){
y=0;
selec.posselectleft.y=965;
selec.posselectleft.x=243;
selec.posselectright.y=965;
selec.posselectright.x=8;}
affichageinput(in,opt);  
if (x!=-1){
SDL_BlitSurface(imagel,NULL,opt.resolution,&(selec.posselectleft));
if (y!=1)
SDL_BlitSurface(imager,NULL,opt.resolution,&(selec.posselectright));
}
SDL_Flip(opt.resolution);

}

int mouseinput(int x,int y){

if((552<=y)&&(y<=774)&&(57<=x)&&(x<=583)){return 0;}

else if((1217<=x)&&(x<=1352)){
if     ((252<=y)&&(y<=393)){return 1;}
else if((410<=y)&&(y<=550)){return 2;}
else if((578<=y)&&(y<=717)){return 3;}
else if((735<=y)&&(y<=873)){return 4;}
else if((903<=y)&&(y<=1042)){return 5;}}

else if((111<=x)&&(x<=244)&&(941<=y)&&(y<=1042)){return 6;}




return -1;}


