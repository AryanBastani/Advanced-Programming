#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include<iostream>
#include<vector>
#include"bullet.hpp"
#include"rsdl.hpp"
#include"gloobal_funcs.hpp"
#include"consts.hpp"

class Player
{
    public:
    Player(Point point){ top_left=point; };
    char handle_keys(char prassed_key,char last_key);
    void draw(Window* window);
    void handle_shoot(Window*window);
    bool impat(Point location);
    void location_check();
    Point get_loc() { return(top_left); };
    bool shoot_ship(Point ship_loc);

    private:
        Point top_left;
        std::vector<Bullet*> bullets; 
};
#endif