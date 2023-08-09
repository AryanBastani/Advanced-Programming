#include<iostream>
#include"bullet.hpp"
using namespace std;

void Bullet::move_up_down(int movement_type)
{
    if(movement_type==UP)
        top_left.y-=BULLET_MOVE;
    else if(movement_type==DOWN)
        top_left.y+=BULLET_MOVE;
}

bool Bullet::is_out()
{
    return((top_left.y+BULLET_SIZE<0)||(top_left.y-BULLET_SIZE>728));
}

void Bullet::draw_pics(Window* window)
{
    Rectangle ship=Rectangle(top_left,Point(top_left.x+HOSTAGE_SIZE,top_left.y+HOSTAGE_SIZE));
    window->draw_img(HOSTAGE_IMG,ship);   
}



