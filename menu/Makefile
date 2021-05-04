o:impli.o main.o option.o input.o resolution.o play.o loadgame.o
	gcc impli.o main.o option.o input.o resolution.o play.o loadgame.o -o o -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
	./o
main.o:main.c
	gcc -c main.c
impli.o:impli.c
	gcc -c impli.c
option.o:option.c
	gcc -c option.c
input.o:input.c
	gcc -c input.c
resolution.o:resolution.c
	gcc -c resolution.c
play.o:play.c
	gcc -c play.c
loadgame.o:loadgame.c
	gcc -c loadgame.c