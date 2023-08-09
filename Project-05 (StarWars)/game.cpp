#include"game.hpp"
using namespace std;

void Game::shoot_enemy()
{
    for(int enemy_id=0;enemy_id<enemies.size();enemy_id++)
    {
        if(player->shoot_ship(enemies[enemy_id]->get_loc()))
        {
            enemies.erase(enemies.begin()+enemy_id);
            enemy_id--;
        }
    }
}

void Game::read_object(string object_type,ifstream& map)
{
    Point object_loc;
    map>>object_loc.x>>object_loc.y;
    if(object_type==SIMPLE_ENEMY)
        (map_info.rounds_info[map_info.rounds_info.size()-1].e_loc).push_back(object_loc);
    else if(object_type==MOVABLE_ENEMY)
        (map_info.rounds_info[map_info.rounds_info.size()-1].m_loc).push_back(object_loc);
    else
        (map_info.rounds_info[map_info.rounds_info.size()-1].hostages_loc).push_back(object_loc);
}

void Game::read_map(char *argv[])
{
    Round_info round;
    ifstream map;
    map.open(argv[1]);
    map>>map_info.num_of_rows>>map_info.num_of_columns;
    string cmd;
    while(map>>cmd)
    {
        if(cmd=="round")
            map_info.rounds_info.push_back(round);
        else
            read_object(cmd,map);
    }
}

bool Game::win_conditions()
{
    shoot_enemy();
    if(enemies.size()==0)
        return(true);
    
    return(false);
}

bool Game::player_dead()
{
    for(int enemy_id=0;enemy_id<enemies.size();enemy_id++)
    {
        Enemy* enemy=enemies[enemy_id];
        if((did_impat(enemy->get_loc(),player->get_loc(),ENEMY_SIZE,PLAYER_SIZE))||
        (enemy->shoot_player(player->get_loc())))
            return(true);
    }
    return(false);
}

bool Game::hostage_dead()
{
    for(int hostage_id=0;hostage_id<hostages.size();hostage_id++)
    {
        Hostage* hostage=hostages[hostage_id];
        if(did_impat(hostage->get_loc(),player->get_loc(),HOSTAGE_SIZE,PLAYER_SIZE)||
        (player->shoot_ship(hostage->get_loc())))
            return(true);
    }
    return(false);
}

bool Game::over_conditions()
{
    return(player_dead()||hostage_dead());
}

void Game::win_over(bool player_win)
{
    win=player_win;
    round_ends=true;
    is_game_running=player_win;
}

void Game::game_handle()
{
    if(over_conditions())
    {
        win_over(false);
    }
    else if(win_conditions())
    {
        win_over(true);
    }    
}

Point Game::convert_point(Point loc,int size)
{
    Point new_loc;
    if(loc.x!=0)
        new_loc.x=(((loc.x+1)*COLUMN)/map_info.num_of_columns)-(size/2);
    if(loc.y!=0)
        new_loc.y=(((loc.y+1)*ROWS)/map_info.num_of_rows)-(size/2);
    return(new_loc);
}

void Game::new_objects(vector<Point> objects,string object_type)
{
    for(int object_id=0;object_id<objects.size();object_id++)
    {   
        if(object_type==HOSTAGE)
            hostages.push_back(new Hostage(convert_point(objects[object_id],HOSTAGE_SIZE)));
        else if(object_type==SIMPLE_ENEMY)
            enemies.push_back(new Enemy(convert_point(objects[object_id],ENEMY_SIZE),false));
        else
            enemies.push_back(new Enemy(convert_point(objects[object_id],ENEMY_SIZE),true));
    }
}

void Game::update_round(int round_id)
{
    srand(time(0));
    hostages.clear();
    new_objects(map_info.rounds_info[round_id].hostages_loc,HOSTAGE);
    new_objects(map_info.rounds_info[round_id].e_loc,SIMPLE_ENEMY);
    new_objects(map_info.rounds_info[round_id].m_loc,MOVABLE_ENEMY);
    player=new Player(Point((rand()%874)+1,ROWS-PLAYER_SIZE));
}

void Game::play_round(int round_id)
{
    update_round(round_id);
    round_ends=false;
    while(!round_ends)
    {
        get_events();
        draw_screen();
        game_handle();
    } 
}

void Game::end_game()
{
        window->clear();   
        if(win)
            window->draw_img(WINNER_IMG);
        else
            window->draw_img(GAME_OVER_IMG);
        window->update_screen();
        delay(1000);
}

void Game::run()
{
    window->play_music("FanfareAndPrologue.mp3");
    for(int round_id=0;round_id<map_info.rounds_info.size();round_id++)
    {
        play_round(round_id);
        if(!is_game_running)
            break;
    }
    if(!press_quit)
       end_game();
}

char Game::handle_events(char last_key)
{
    char pervious_key=INIZIAL_KEY;
    Event event = window->poll_for_event();
    switch(event.get_type()) 
    {
        case Event::QUIT:
            press_quit = true;
            is_game_running=false;
            round_ends=true;
            break;
        case Event::KEY_PRESS:
            last_key=player->handle_keys(event.get_pressed_key(),last_key);
            break;
        case Event::KEY_RELEASE:
            if(last_key==event.get_pressed_key())
                last_key=DONT_KEEP;
            break;
    } 
    if(last_key==' ')
        return(DONT_KEEP);

    return(last_key);
}

void Game::get_events()
{   
    char last_key=INIZIAL_KEY;
    while(last_key!=DONT_KEEP&&is_game_running)
    {
        last_key=handle_events(last_key);
        draw_screen();
        game_handle();
        player->handle_keys(last_key,last_key);
    }
}

void Game::draw_enemies()
{
    for(int enemy_id=0;enemy_id<enemies.size();enemy_id++)
        enemies[enemy_id]->draw(window);
}

void Game::draw_hostages()
{
    for(int hostage_id=0;hostage_id<hostages.size();hostage_id++)
        hostages[hostage_id]->draw(window);
}

void Game::draw_objects()
{
    player->draw(window);
    player->handle_shoot(window);
    draw_enemies();
    draw_hostages();
}

void Game::draw_screen()
{
    delay(DELAY_AMOUNT);
    window->clear();
    window->draw_img(WINDOW_IMG);
    draw_objects();
    window->update_screen();
}
