#ifndef _BULLET_HPP_
#define _BULLET_HPP_

#include<iostream>
#include<vector>
#include"rsdl.hpp"
#include"consts.hpp"

class Bullet
{
    public:
        Bullet(Point center_of_loc) { top_left=center_of_loc; };
        void move_up_down(int movement_type);
        bool is_out();
        void draw(Window* window,RGB color);
        Point get_loc() { return(top_left); };
        void draw_pics(Window* window);

    private:
        Point top_left;
};

#endif