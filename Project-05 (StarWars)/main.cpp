#include"game.hpp"
#include<fstream>

int main(int argc, char *argv[])
{
   Game game;
   game.read_map(argv);
   game.run();
}