#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<time.h>
#include<string.h>
#include<SDL/SDL_mixer.h>
typedef struct{
SDL_Surface *selectionsmallright,*selectionbigright,*selectionbigleft,*selectionsmallleft;
 SDL_Rect posselectright,posselectleft,posnosound,posnoeffect,possound[6],posmark;
 SDL_Surface *nosound,*noeffect,*sound[6],*mark;


}selection;
typedef struct{
SDL_Surface *background[6];
SDL_Rect posbackground;


}background;



typedef struct{
//int left,right,spedd,jump,attack;
 SDL_Surface *d,*z,*q,*s,*back,*right,*left,*jump,*secondplayer;
SDL_Rect posd,posz,posq,poss,posback,posright,posleft,posjump,possecondplayer;
}input;

typedef struct{
input inpu[2];
int soundlv;
int oldsoundlv;
int music;
int effect;
int re;
int nbdjoueur;
SDL_Surface *resolution;
Mix_Chunk *son;
 Mix_Music *musique;
}options;



//menue principale fontion
void mainmenu();
int mouseposimpli(int x,int y);
selection initialisation_boutons();
int next(int x,int nbb,int updown);
void affichage(int x,selection selec,background back,options opt);
options initialisation_parametre();
background initialisation_background();

/*option*/
void menuoption(options *opt,int *continu,background back,selection selec);
void affichageoptions(int x,options opt,background back,selection selec);
int mouseposoption(int x,int y);
/*option*/
;




/*input*/
int mouseinput(int x,int y);
void maininput(options opt,int *continuerr,int *continuerrr,background back,selection selec);
input initialisationimagesinput();
void affichageinput(input a,options opt);
void selectioninput(int x,options opt,input in,background back,selection selec);
/*input*/
/*resolution*/
void menuresolution(options *opt,int *continu,int *continuu,background back,selection selec);
void affichageresolution(int x,options opt,background back,selection selec);
int mouseposresolution(int x,int y);
/*resolution*/
/*play*/
void menuplay(options *opt,int *continuu,background back,selection selec); 
void affichageplay(int x,options opt,background back,selection selec);
int mouseposplay(int x,int y);
/*play*/
/*loadgame */
void menuloadgame(options *opt,int *continu,int *continuu,background back,selection selec);
int mouseposload(int x,int y);
void affichageloadgame(int x,options opt,background back,selection selec);
/*loadgame */