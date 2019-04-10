prog:fonction.o main.o
	gcc fonction.o main.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -o -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
fonction.o:fonction.c
	gcc -c fonction.c –o -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
