#ifndef _ENEMY_HPP_
#define _ENEMY_HPP_

#include<iostream>
#include<vector>
#include"bullet.hpp"
#include"rsdl.hpp"
#include"gloobal_funcs.hpp"
#include"consts.hpp"

class Enemy
{
    public:
        Enemy(Point location,bool move_or_not) { top_left=location; is_movable=move_or_not; direction=RIGHT; time_count=0; };
        void draw(Window* window);
        void shoot(Window* window);
        void next_shoot(Window* window);
        void move_ship();
        void check_loc();
        Point get_loc() { return(top_left); };
        bool shoot_player(Point player_loc);

    private:
        Point top_left;
        std::vector<Bullet*> bullets;
        bool is_movable;
        int direction;
        int time_count;
};
#endif