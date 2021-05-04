o:impli.o main.o option.o input.o resolution.o
	gcc impli.o main.o option.o input.o resolution.o -o o -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
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