#include"gloobal_funcs.hpp"

void move_bull(vector<Bullet*>& bullets,Window* window,int movement_type,RGB color)
{
    for(int bullet_id=0;bullet_id<bullets.size();bullet_id++)
    {
        bullets[bullet_id]->move_up_down(movement_type);
        if(bullets[bullet_id]->is_out())
        {
            bullets.erase(bullets.begin()+bullet_id);
            bullet_id--;
            continue;
        }
        draw_pics(window,bullets[bullet_id]->get_loc(),BULLET_IMG,BULLET_SIZE);
    }
}

void draw_pics(Window* window,Point top_left,string img_address,int ship_size)
{
    Point bottom_right=Point(top_left.x+ship_size,top_left.y+ship_size);
    Rectangle ship=Rectangle(top_left,bottom_right);
    window->draw_img(img_address,ship);   
}

bool impat_conditions(int corner,int another_corner,int t_corner,int t_another_corner)
{
    return((corner>t_corner&&corner<t_another_corner)||
    (another_corner>t_corner&&another_corner<t_another_corner));
}

bool did_impat(Point top_left,Point t_top_left,int size,int t_size)
{
    int left=top_left.x , t_left=t_top_left.x;
    int right=top_left.x+size , t_right=t_top_left.x+t_size;
    int top=top_left.y , t_top=t_top_left.y;
    int bottom=top_left.y+size , t_bottom=t_top_left.y+t_size;

    if(impat_conditions(left,right,t_left,t_right))
        return(impat_conditions(top,bottom,t_top,t_bottom));

    return(false);
}

bool did_shoot(vector<Bullet*> bullets,Point ship_loc,int ship_size)
{
    for(int bulet_id=0;bulet_id<bullets.size();bulet_id++)
    {
        if(did_impat(bullets[bulet_id]->get_loc(),ship_loc,BULLET_SIZE,ship_size))
            return(true);
    }

    return(false);
}