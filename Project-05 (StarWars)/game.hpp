#include<iostream>
#include<vector>
#include<fstream>
#include"hostage.hpp"
#include"player.hpp"
#include"enemy.hpp"
#include"gloobal_funcs.hpp"
#include"consts.hpp"

struct Round_info
{
    std::vector<Point> e_loc;
    std::vector<Point> m_loc;
    std::vector<Point> hostages_loc;
};

struct Map_info
{
    int num_of_rows;
    int num_of_columns;
    std::vector<Round_info> rounds_info;
};

class Game
{
    public:
        void run();
        void get_events();
        void draw_screen();
        char handle_events(char last_key);
        void draw_enemies();
        void draw_objects();
        void draw_hostages();
        bool player_dead();
        void game_handle();
        bool over_conditions();
        bool hostage_dead();
        void shoot_enemy();
        bool win_conditions();
        void read_object(std::string object_type,std::ifstream& map);
        void read_map(char *argv[]);
        void update_round(int round_id);
        void new_objects(std::vector<Point> objects,std::string object_type);
        Point convert_point(Point loc,int size);
        void win_over(bool player_win);
        void play_round(int round_id);
        void end_game();
        

    private:
        Window* window=new Window(COLUMN,ROWS);
        bool is_game_running=true;
        Player* player;
        std::vector<Enemy*> enemies;
        std::vector<Hostage*> hostages;  
        Map_info map_info; 
        bool round_ends;
        bool win;
        bool press_quit=false;
};

