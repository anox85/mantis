prog:main.o p.o
	gcc main.o p.o -o prog -g -lSDL -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer
p.o:p.c
	gcc -c p.c –g -lSDL -lSDL_image -lSDL_mixer
