#ifndef _GLOOBAL_FUNCS_HPP_
#define _GLOOBAL_FANCS_HPP_

#include<iostream>
#include<vector>
#include"rsdl.hpp"
#include"bullet.hpp"

void move_bull(std::vector<Bullet*>& bullets,Window* window,int movement_type,RGB color);

void draw_pics(Window* window,Point top_left,std::string img_address,int ship_size);

bool did_impat(Point top_left,Point t_top_left,int size,int t_size);

bool impat_conditions(int corner,int another_corner,int t_corner,int t_another_corner);

bool did_shoot(std::vector<Bullet*> bullets,Point ship_loc,int ship_size);

#endif