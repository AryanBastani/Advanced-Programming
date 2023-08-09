// in the name of GOD
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const string INITIAL_WEAPON="knife";
const int INITIAL_HEALTH=100;
const int INITIAL_MONEY=1000;
const int MAX_MONEY=10000;
const int WIN_PRIZE=2700;
const int LOST_PRIZE=2400;

const int KNIFE_DAMAGE=35;
const int KNIFE_KILL_PRIZE=500;
const int HEAVY_PRICE=3000;
const int HEAVY_DAMAGE=45;
const int HEAVY_KILL_PRIZE=100;
const int PISTOL_PRICE=400;
const int PISTOL_DAMAGE=20;
const int PISTOL_KILL_PRIZE=200;

const string START_MASS="fight!";
const string DONE_MASS="ok";
const string HASNT_START_MASS="The game hasn't started yet";
const string UNAVAILABLE_MASS="user not available";
const string SAME_TEAM_MASS="you can't shoot this player";
const string DEAD_ATTACKER_MASS="attacker is dead";
const string DEAD_ATTACKED_MASS="attacked is dead";
const string NOT_EXIST_WEAPON_MASS="attacker doesn't have this gun";
const string SHOOT_MASS="nice shot";
const string DUPLICATE_WEAPON_MASS="you already have this weapon";
const string WRONG_GUN_NAME_MASS="weapon not available";
const string INSUFFICIENT_MONEY_MASS="insufficient money";
const string SUCCESSFUL_BUY_MASS="weapon bought successfully";
const string LATE_BUY_MASS="you can't buy weapons anymore";


class Weapon
{
    public:
        Weapon(string weapon_name,int weapon_damage,int weapon_kill_prize);
        string get_name() { return(name); };
        int get_damage() { return(damage); };
        int get_kill_prize() {return(kill_prize); };
    private:
        string name;
        int damage;
        int kill_prize;
};

class Player
{
    public:
        Player(string user_name);
        void afk();
        void atk();
        void increase_kills() { num_of_kills++; };
        void increase_deaths() { num_of_deaths++; };
        void decrease_health(int damage_amount);
        void increase_money(int prize_amount);
        void buy_weapon(string gun_name);
        void buy_gun(string name,int price,int damage,int kill_prize);
        void take_guns();
        void rehealth() { health=INITIAL_HEALTH; };

        int get_money() { return(money); };
        int get_health() { return(health); };
        string get_name() { return(name); };
        bool get_afk() { return(is_afk); };
        vector<Weapon> get_weapons() { return(weapons); };
        int get_kills() { return(num_of_kills); };
        int get_deaths() { return(num_of_deaths); };
    private:
        string name;
        vector<Weapon> weapons{Weapon(INITIAL_WEAPON,KNIFE_DAMAGE,KNIFE_KILL_PRIZE)};
        int money=INITIAL_MONEY;
        int health=INITIAL_HEALTH;
        int num_of_kills=0;   
        int num_of_deaths=0;
        bool is_afk=false;
};

class Teams
{
    public:
    void add_user(Player player,string team_name);
    void go_afk();
    void go_atk();
    void shoot(string attacker,string attacked,string weapon);
    int find_attacked(string attacker_team,string attacked_name);
    void buy(string buyer,string gun);
    void score_board();
    void end_round();

    vector<Player> get_terror(){ return(terrorist); };
    vector<Player> get_ct(){ return(counter_terrorist); };
    private:
    vector<Player> terrorist;
    vector<Player> counter_terrorist;
};

Weapon::Weapon(string weapon_name,int weapon_damage,int weapon_kill_prize)
{
    name=weapon_name;
    damage=weapon_damage;
    kill_prize=weapon_kill_prize;
}

Player::Player(string user_name)
{
    name=user_name;
}

void Player::take_guns()
{
    while(weapons.size()!=1)
    {
        weapons.pop_back();
    }
}

void Player::increase_money(int prize_amount)
{
    money+=prize_amount;
    if(money>MAX_MONEY)
    {
        money=MAX_MONEY;
    }
}

void Player::decrease_health(int damage_amount)
{
    health-=damage_amount;
    if(health<0)
    {
        health=0;
    }
}

int user_finder(vector<Player> players,string user_name)
{
    for(int player_id=0;player_id<players.size();player_id++)
    {
        if(players[player_id].get_name()==user_name)
        {
            return(player_id);
        }
    }
    return(-1);
}

void Teams::go_afk()
{
    string user_name;
    cin>>user_name;
    int user_id=user_finder(terrorist,user_name);

    if(user_id==-1)
    {
        user_id=user_finder(counter_terrorist,user_name);
        counter_terrorist[user_id].afk();
        return;
    }
    terrorist[user_id].afk();
}

bool is_dead(Player player)
{
    if(player.get_health()==0)
    {
        return(true);
    }

    return(false);
}

bool alphabetical(Player& player1,Player& player2)
{
	return(player1.get_name()<player2.get_name());
}

bool death_sort(Player& player1,Player& player2)
{
    if(player1.get_deaths()==player2.get_deaths())
    {
        return(alphabetical(player1,player2));
    }
    return(player1.get_deaths()<player2.get_deaths());
}

bool score_sort(Player& player1,Player& player2)
{
    if(player1.get_kills()==player2.get_kills())
    {
        return(death_sort(player1,player2));
    }
    return(player1.get_kills()>player2.get_kills());
}

void print_board(vector<Player> players)
{
    for(int player_id=0;player_id<players.size();player_id++)
    {
        cout<<players[player_id].get_name()<<' '<<players[player_id].get_kills()<<
        ' '<<players[player_id].get_deaths()<<'\n';
    }
}

void Teams::score_board()
{
    sort(counter_terrorist.begin(),counter_terrorist.end(),score_sort);
    sort(terrorist.begin(),terrorist.end(),score_sort);
    cout<<"counter-terrorist players:\n";
    print_board(counter_terrorist);
    cout<<"terrorist players:\n";
    print_board(terrorist);
}

bool players_check(string attacker_team,string attacked_team,int attacked_id,vector<Player> players)
{
    if((attacked_id==-1)||(players[attacked_id].get_afk()))
    {
        cout<<UNAVAILABLE_MASS<<'\n';
    }
    else if(attacked_team==attacker_team)
    {
        cout<<SAME_TEAM_MASS<<'\n';
    }
    else if(is_dead(players[attacked_id]))
    {
        cout<<DEAD_ATTACKED_MASS<<'\n';
    }
    else
    {
    return(true);
    }

    return(false);
}

int Teams::find_attacked(string attacker_team,string attacked_name)
{
    int attacked_id=user_finder(terrorist,attacked_name);
    if(attacked_id==-1)
    {
        attacked_id=user_finder(counter_terrorist,attacked_name);
        if(players_check(attacker_team,"counter_terrorist",attacked_id,counter_terrorist)==false)
        {
            return(-1);
        }
    }
    else
    {
        if(players_check(attacker_team,"terrorist",attacked_id,terrorist)==false)
        {
            return(-1);
        }
    }
    return(attacked_id);
}

bool attacker_checks(Player attacker)
{
    if(attacker.get_afk())
    {
        cout<<UNAVAILABLE_MASS<<'\n';
    }
    else if(is_dead(attacker))
    {
        cout<<DEAD_ATTACKER_MASS<<'\n';
    }
    else
    {
        return(true);
    }

    return(false);
}

int weapon_search(vector<Weapon> weapons,string weapon_name)
{
    for(int weapon_id=0;weapon_id<weapons.size();weapon_id++)
    {
        if(weapons[weapon_id].get_name()==weapon_name)
        {
            return(weapon_id);
        }
    }
    return(-1);
}

void Player::buy_gun(string name,int price,int damage,int kill_prize)
{
    if(money<price)
    {
        cout<<INSUFFICIENT_MONEY_MASS<<'\n';
        return;
    }

    money-=price;
    weapons.push_back(Weapon(name,damage,kill_prize));
    cout<<SUCCESSFUL_BUY_MASS<<'\n';
}

void Player::buy_weapon(string gun_name)
{
    if(weapon_search(weapons,gun_name)!=-1)
    {
        cout<<DUPLICATE_WEAPON_MASS<<'\n';
        return;
    }

    if(gun_name=="pistol")
    {
        buy_gun("pistol",PISTOL_PRICE,PISTOL_DAMAGE,PISTOL_KILL_PRIZE);
    }
    else if(gun_name=="heavy")
    {
        buy_gun("heavy",HEAVY_PRICE,HEAVY_DAMAGE,HEAVY_KILL_PRIZE);
    }
    else
    {
        cout<<WRONG_GUN_NAME_MASS<<'\n';
    }
}

Player killer(Player player,Weapon weapon)
{
        player.increase_money(weapon.get_kill_prize());
        player.increase_kills();
        return(player);
}

Player is_killed(Player player)
{
    player.increase_deaths();
    player.take_guns();
    return(player);
}

void shoot_effects(Player& attacker,vector<Player>& attacked_team,int attacked_id,string weapon)
{
    if((attacked_id==-1)||(!attacker_checks(attacker)))
    {
        return;
    }

    vector<Weapon> the_weapons=attacker.get_weapons();
    int weapon_id=weapon_search(the_weapons,weapon);
    if(weapon_id==-1)
    {
        cout<<NOT_EXIST_WEAPON_MASS<<'\n';
        return;
    }

    attacked_team[attacked_id].decrease_health(the_weapons[weapon_id].get_damage());
    if(is_dead(attacked_team[attacked_id]))
    {
        attacker=killer(attacker,the_weapons[weapon_id]);
        attacked_team[attacked_id]=is_killed(attacked_team[attacked_id]);
    }
    cout<<SHOOT_MASS<<'\n';
}

void Teams::shoot(string attacker,string attacked,string weapon)
{
    int attacked_id;
    int attacker_id=user_finder(terrorist,attacker);
    if(attacker_id!=-1)
    {
        attacked_id=find_attacked("terrorist",attacked);
        shoot_effects(terrorist[attacker_id],counter_terrorist,attacked_id,weapon);
    }
    else if((attacker_id=user_finder(counter_terrorist,attacker))!=-1)
    {
        attacked_id=find_attacked("counter_terrorist",attacked);
        shoot_effects(counter_terrorist[attacker_id],terrorist,attacked_id,weapon);
    }
    else
    {
        cout<<UNAVAILABLE_MASS<<'\n';
    }
}

void Teams::add_user(Player player,string team_name)
{   
    if(team_name=="terrorist")
    {
        terrorist.push_back(player);
    }
    else if(team_name=="counter-terrorist")
    {
        counter_terrorist.push_back(player);
    }
}

void Teams::go_atk()
{
    string user_name;
    cin>>user_name;
    int user_id=user_finder(terrorist,user_name);

    if(user_id==-1)
    {
        user_id=user_finder(counter_terrorist,user_name);
        counter_terrorist[user_id].atk();
        return;
    }
    terrorist[user_id].atk();
}

void Player::afk()
{
    is_afk=true;
    cout<<DONE_MASS<<'\n';
}

void Player::atk()
{
    is_afk=false;
    cout<<DONE_MASS<<'\n';
}

Player find_user(Teams teams,string user_name)
{
    vector<Player> players=teams.get_terror();
    int user_id=user_finder(players,user_name);

    if(user_id==-1)
    {
        players=teams.get_ct();
        user_id=user_finder(players,user_name);
    }
    if(user_id==-1)
    {
        return(Player("no player found!"));
    }
    return(players[user_id]);
}

Teams new_user(bool has_started,Teams teams)
{
    string user_name,team_name;

    if(!has_started)
    {
        cin>>user_name>>team_name;
        if(find_user(teams,user_name).get_name()=="no player found!")
        {
            teams.add_user(Player(user_name),team_name);
            cout<<DONE_MASS<<'\n';
        }
    }
    return(teams);
} 

Teams shoot_works(Teams teams,bool has_started)
{
    if(!has_started)
    {
        cout<<HASNT_START_MASS<<'\n';
        return(teams);
    }
    string attacker,attacked,weapon;
    cin>>attacker>>attacked>>weapon;
    teams.shoot(attacker,attacked,weapon);

    return(teams);
}

void Teams::buy(string buyer,string gun)
{
    int buyer_id=user_finder(terrorist,buyer);
    if((buyer_id!=-1)&&((terrorist[buyer_id].get_afk())==false))
    {
        terrorist[buyer_id].buy_weapon(gun);
        return;
    }

    buyer_id=user_finder(counter_terrorist,buyer);
    if((buyer_id!=-1)&&((counter_terrorist[buyer_id].get_afk())==false))
    {
        counter_terrorist[buyer_id].buy_weapon(gun);
        return;
    }

    cout<<UNAVAILABLE_MASS<<'\n';
}

Teams buy_works(Teams teams,bool has_started)
{
    if(has_started)
    {
        cout<<LATE_BUY_MASS<<'\n';
        return(teams);
    }

    string buyer,gun;
    cin>>buyer>>gun;
    teams.buy(buyer,gun);
    return(teams);
}

vector<Player> restart_health(vector<Player> players)
{
    for(int player_id=0;player_id<players.size();player_id++)
    {
        players[player_id].rehealth();
    }
    return(players);
}

vector<Player> win(string winner_name,vector<Player> winners)
{
    winners=restart_health(winners);

    for(int player_id=0;player_id<winners.size();player_id++)
    {
            winners[player_id].increase_money(WIN_PRIZE);
    }
    cout<<winner_name<<" won\n";
    return(winners);
}

vector<Player> lost(vector<Player> losers)
{
    losers=restart_health(losers);

    for(int player_id=0;player_id<losers.size();player_id++)
    {
        losers[player_id].increase_money(LOST_PRIZE);
    }
    return(losers);
}

int round_works(int& command_count,bool& has_started,bool& has_round_start)
{
    int max_command;
    cin>>max_command;
    command_count=0;
    has_started=false;
    has_round_start=true;
    return(max_command);
}

void Teams::end_round()
{
    int player_id=0;
    for(player_id;player_id<counter_terrorist.size();player_id++)
    {
        if(!is_dead(counter_terrorist[player_id]))
        {
            if(!(counter_terrorist[player_id].get_afk()))
            {
                break;
            }
        }
    }
    if(player_id==counter_terrorist.size())
    {
        terrorist=win("terrorist",terrorist);
        counter_terrorist=lost(counter_terrorist);
        return;
    }

    counter_terrorist=win("counter-terrorist",counter_terrorist);
    terrorist=lost(terrorist);
}

Teams round_over(Teams teams,bool& has_round_start,int command_count,int max_command)
{
    if(has_round_start)
    {
        if(command_count==max_command)
        {
            teams.end_round();
            has_round_start=false;
        }
    }
    return(teams);
}

bool start()
{
    bool has_started=true;
    cout<<START_MASS<<'\n';
    return(has_started);
}

void play_game()
{
    string input_command;
    string user_name;
    Teams teams;
    int max_command,command_count;
    bool has_started=false;
    bool has_round_start=false;

    while(cin>>input_command)
    {   
        if(input_command=="add-user")
        {
            teams=new_user(has_started,teams);
        }
        else if(input_command=="get-money")
        {
            cin>>user_name;
            cout<<find_user(teams,user_name).get_money()<<'\n';
        }
        else if(input_command=="get-health")
        {
            cin>>user_name;
            cout<<find_user(teams,user_name).get_health()<<'\n';
        }
        else if(input_command=="start")
        {
            has_started=start();
        }
        else if(input_command=="go-afk")
        {
            teams.go_afk();
        }
        else if(input_command=="go-atk")
        {
            teams.go_atk();
        }
        else if(input_command=="shoot")
        {
            teams=shoot_works(teams,has_started);
        }
        else if(input_command=="buy")
        {
           teams=buy_works(teams,has_started); 
        }
        else if(input_command=="score-board")
        {
            teams.score_board();
        }
        else if(input_command=="round")
        {
            max_command=round_works(command_count,has_started,has_round_start);
            continue;
        }
        else
        {
            continue;
        }

        command_count++;
        teams=round_over(teams,has_round_start,command_count,max_command);
    }
}

int main()
{
    play_game();
}