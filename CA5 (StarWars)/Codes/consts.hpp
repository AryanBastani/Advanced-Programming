#ifndef _CONSTS_HPP_
#define _CONSTS_HPP_
#include<iostream>
using namespace std;

const int ROWS=728;
const int COLUMN=1024;

const int UP=0;
const int DOWN=1;
const int LEFT=2;
const int RIGHT=3;

const int HOSTAGE_SIZE=120;
const int PLAYER_SIZE=150;
const int ENEMY_SIZE=120;
const int BULLET_SIZE=30;

const int BULLET_MOVE=10;
const int PLAYER_MOVE=10;
const int ENEMY_MOVE=4;

const string HOSTAGE="h";
const string SIMPLE_ENEMY="e";
const string MOVABLE_ENEMY="m";

const int DELAY_AMOUNT=20;
const int ALIVE=-1;
const char INIZIAL_KEY='h';
const char DONT_KEEP='1';

const std::string WINDOW_IMG="bb.jpg";
const std::string ENEMY_IMG="player5-ppreview.png";
const std::string PLAYER_IMG="asd.png";
const std::string HOSTAGE_IMG="SeekPng.com_spaceship-png_215100-removebg-preview.png";
const std::string BULLET_IMG="123-removebg-preview.png";
const std::string WINNER_IMG="win.jpeg";
const std::string GAME_OVER_IMG="game_over.webp";

#endif
