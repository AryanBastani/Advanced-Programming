#include<iostream>
#include"ModelSim.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    ModelSim modelSim = ModelSim(argv[1]);
    modelSim.run();
}