#include"player.hpp"
using namespace std;

char Player::handle_keys(char pressed_key,char last_key=INIZIAL_KEY)
{
    if(pressed_key=='w')
        top_left.y-=PLAYER_MOVE;
    if(pressed_key=='s')
        top_left.y+=PLAYER_MOVE;
    if(pressed_key=='a')
        top_left.x-=PLAYER_MOVE;
    if(pressed_key=='d')
        top_left.x+=PLAYER_MOVE;
    if(pressed_key==' ')
    {
        bullets.push_back(new Bullet(Point(top_left.x+
        (PLAYER_SIZE/2)-(BULLET_SIZE/2),top_left.y-BULLET_SIZE)));
        return(last_key);
    }
    return(pressed_key);
}

void Player::location_check()
{
    if(top_left.x<0)
        top_left.x=0;
    if((top_left.x+PLAYER_SIZE)>1024)
        top_left.x=(1024-PLAYER_SIZE);
    if(top_left.y<0)
        top_left.y=0;
    if(top_left.y>(728-PLAYER_SIZE))
        top_left.y=(728-PLAYER_SIZE);
}

void Player::draw(Window* window)
{
    location_check();
    draw_pics(window,top_left,PLAYER_IMG,PLAYER_SIZE);
}

bool Player::impat(Point location)
{
    return(false);
}

void Player::handle_shoot(Window* window)
{
    move_bull(bullets,window,UP,RGB(255,255,0));
}

bool Player::shoot_ship(Point ship_loc)
{
    return(did_shoot(bullets,ship_loc,HOSTAGE_SIZE));
}

