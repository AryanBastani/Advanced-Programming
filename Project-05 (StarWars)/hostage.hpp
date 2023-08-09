#ifndef _HOSTAGE_HPP_
#define _HOSTAGE_HPP_

#include<iostream>
#include"rsdl.hpp"
#include"bullet.hpp"
#include"gloobal_funcs.hpp"
#include"consts.hpp"

class Hostage
{
    public:
        Hostage(Point location) { bottom_left=location; };
        void draw(Window* window);
        Point get_loc() { return(bottom_left); };
    private:
        Point bottom_left;
};
#endif