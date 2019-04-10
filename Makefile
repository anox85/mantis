prog:main.o enemie.o
	gcc main.o enemie.o -o prog -g -lSDL -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer
enemie.o:enemie.c
	gcc -c enemie.c –g -lSDL -lSDL_image -lSDL_mixer
