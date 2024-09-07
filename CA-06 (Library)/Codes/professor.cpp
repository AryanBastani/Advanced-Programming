#include<iostream>
#include<string>
#include<vector>
#include"professor.hpp"
using namespace std;

const int PROF_MAX=5;

Professor::Professor(string prof_name)
:Member(prof_name,PROF_MAX)
{

}