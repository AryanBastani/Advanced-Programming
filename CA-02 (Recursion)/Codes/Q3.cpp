#include<iostream>
#include<string>
#include<vector>
using namespace std;

const vector<int> ROW_DELTA={0,0,-1,1};
const vector<int> COL_DELTA={1,-1,0,0};

const string UNSUCCESSFUL_MASSAGE="No path found";



typedef struct location
{
    int row;
    int col;
}Location;


vector<vector<char>> get_input()
{
    int element_num=0;
    vector<vector<char>> board;
    string input_line;

    while(cin>>input_line)
    {
        vector<char> input_line_chars;
        copy(input_line.begin(), input_line.end(), back_inserter(input_line_chars));
        board.push_back(input_line_chars);
    }

    return(board);
}


bool out_of_board_check(vector<vector<char>> board, Location location)
{
    if(((location.row<board.size())&&(location.row>=0))&&
    ((location.col<board[0].size())&&(location.col>=0)))
    {
        if(board[location.row][location.col]!='#')
        return(true);
    }

    return(false);
}


Location new_location_calculator(Location current_location,int move_id)
{       
    Location new_location;

    new_location.row=(current_location.row+ROW_DELTA[move_id]);
    new_location.col=(current_location.col+COL_DELTA[move_id]);

    return(new_location);
}


Location location_backtrack(Location location,int move_id)
{
    Location backtracked_location;

    backtracked_location.row=(location.row -ROW_DELTA[move_id]);
    backtracked_location.col=(location.col -COL_DELTA[move_id]);

    return(backtracked_location);
}


int stone_move(int move_id)
{
    if(move_id<2)
    {
        return(2);
    }
    return(0);
}


int do_cols_end(Location location,vector<vector<char>> board)
{
    if(location.col==(board.size()-1))
    {
        return(0);
    }
    if(location.col==0)
    {
        return(1);
    }
    return(-1);
}


int do_rows_end(Location location,vector<vector<char>> board)
{
    if(location.row==((board[0].size())-1))
    {
        return(1);
    }
    if(location.row==0)
    {
        return(0);
    }
    return(-1);
}


int check_corners(int move_id ,Location new_location,vector<vector<char>> board)
{
    int does_move_correct;
   if(((move_id==0)&&(do_cols_end(new_location,board)==0))||
    ((move_id==1)&&(do_cols_end(new_location,board)==1)))
    {
        does_move_correct=1;
        if(do_rows_end(new_location,board)!=-1)
        {
            does_move_correct=0;
        }
    }
    else if((move_id==2)&&(do_rows_end(new_location,board)==0)||
    (move_id==3)&&(do_rows_end(new_location,board)==1))
    {
        does_move_correct=1;

        if(do_cols_end(new_location,board)!=-1)
        {
            does_move_correct=0;
        }
    }
    return(does_move_correct);
}


void possible_ways(vector<int>& num_of_moves,vector<vector<char>>& board,Location current_location,
int first_move_id=0,int last_move_id=3,int moves=0)
{
    int does_move_correct=0;

    for(int move_id=first_move_id;first_move_id<=last_move_id;move_id++)
    {   
        Location new_location=current_location;
        if(out_of_board_check(board,new_location_calculator(current_location,move_id)))
        {
            while(true)
            {
                new_location=new_location_calculator(new_location,move_id);
        
                if(board[new_location.row][new_location.col]=='#')
                {
                    new_location=location_backtrack(new_location,move_id);

                    first_move_id=stone_move(move_id);
                    last_move_id=(first_move_id+1);
        
                    break;
                }

                else if(board[new_location.row][new_location.col]=='*')
                {
                    moves++;
                    num_of_moves.push_back(moves);
                    return;
                }

                else if((((move_id==0)&&(do_cols_end(new_location,board)==0))||
                ((move_id==1)&&(do_cols_end(new_location,board)==1)))||
                ((move_id==2)&&(do_rows_end(new_location,board)==0)||
                (move_id==3)&&(do_rows_end(new_location,board)==1)))
                {
                    does_move_correct =check_corners(move_id,new_location,board);
                    first_move_id=0;
                    last_move_id=3;
                    break;
                }

                moves++;
            }

            if((does_move_correct==0)&&(board[new_location.row][new_location.col]=='.'))
            {
                board[new_location.row][new_location.col]='1';

                possible_ways(num_of_moves,board,new_location,first_move_id,last_move_id,moves);
            }
        }
    }
}


void print_shortest_moves(vector<int> ways)
{
    if(ways.size()!=0)
    {
        int smallest=ways[0];
        for(int way_num=0;way_num<ways.size();way_num++)
        {
            if(ways[way_num]<smallest)
            {
                smallest=ways[way_num];
            }
        }
        cout<<smallest<<'\n';
    }
    else
    {
        cout<<UNSUCCESSFUL_MASSAGE<<'\n';
    }
}



int main()
{   vector<int> num_of_moves;
    vector<vector<char>> board;

    board=get_input();

    Location first_location;
    first_location.col=0;
    first_location.row=0;


    possible_ways(num_of_moves,board,first_location);


    print_shortest_moves(num_of_moves);
}