#include"enemy.hpp"
using namespace std;

void Enemy::next_shoot(Window* window)
{
    if(time_count==55)
        shoot(window);
}

void Enemy::check_loc()
{
    if(top_left.x<+0)
        direction=RIGHT;
    else if(top_left.x>(1024-ENEMY_SIZE))
        direction=LEFT;
}

void Enemy::move_ship()
{
    check_loc();
    if(direction==LEFT)
        top_left.x-=ENEMY_MOVE;
    else if(direction==RIGHT)
        top_left.x+=ENEMY_MOVE;
}


void Enemy::draw(Window* window)
{
    draw_pics(window,top_left,ENEMY_IMG,ENEMY_SIZE);
    if(is_movable)
    move_ship();
    move_bull(bullets,window,DOWN,RGB(255,0,255));
    time_count++;
    next_shoot(window);
}

void Enemy::shoot(Window* window)
{
    time_count=0;
    bullets.push_back(new Bullet(Point(top_left.x+(ENEMY_SIZE/2)-(BULLET_SIZE/2),top_left.y+(ENEMY_SIZE-BULLET_SIZE))));
}

bool Enemy::shoot_player(Point player_loc)
{
    return(did_shoot(bullets,player_loc,PLAYER_SIZE));
}


