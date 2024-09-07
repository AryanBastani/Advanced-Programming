CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all:starwars.out


starwars.out: main.o rsdl.o game.o player.o enemy.o hostage.o bullet.o gloobal_funcs.o
	$(CC) main.o rsdl.o game.o player.o enemy.o hostage.o bullet.o gloobal_funcs.o  $(CCFLAGS) -o starwars.out

main.o: rsdl.hpp game.hpp player.hpp hostage.hpp enemy.hpp bullet.hpp gloobal_funcs.hpp consts.hpp main.cpp
	$(CC) -c main.cpp -o main.o

game.o: rsdl.hpp player.hpp hostage.hpp enemy.hpp bullet.hpp gloobal_funcs.hpp consts.hpp game.cpp
	$(CC) -c game.cpp -o game.o

player.o: rsdl.hpp bullet.hpp gloobal_funcs.hpp consts.hpp player.cpp
	$(CC) -c player.cpp -o player.o

enemy.o: rsdl.hpp bullet.hpp gloobal_funcs.hpp consts.hpp enemy.cpp
	$(CC) -c enemy.cpp -o enemy.o

hostage.o: rsdl.hpp gloobal_funcs.hpp consts.hpp hostage.cpp
	$(CC) -c hostage.cpp -o hostage.o

bullet.o: rsdl.hpp gloobal_funcs.hpp consts.hpp bullet.cpp
	$(CC) -c bullet.cpp -o bullet.o

gloobal_funcs.o: rsdl.hpp bullet.hpp gloobal_funcs.cpp
	$(CC) -c gloobal_funcs.cpp -o gloobal_funcs.o

rsdl.o: rsdl.hpp rsdl.cpp
	$(CC) -c rsdl.cpp -o rsdl.o


.PHONY: clean
clean:
	rm -r *.o
