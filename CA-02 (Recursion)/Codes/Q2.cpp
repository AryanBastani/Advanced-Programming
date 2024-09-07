#include<iostream>
#include<string>
#include<vector>
using namespace std;

const string TRUE_RESULT_MASSAGE="Interleaving";
const string FALSE_RESULT_MASSAGE="Not Interleaving";



vector<char> string_to_vector(string string)
{
    vector<char> result;

    copy(string.begin(), string.end(), back_inserter(result));

    return(result);
}



int check_combination(vector<char>& part_of_letters,vector<char>& letters_combination,
int wanted_char_num=0,int char_comb_num=0)
{
   for(char_comb_num;char_comb_num<letters_combination.size();char_comb_num++)
        {
            if(letters_combination[char_comb_num]==part_of_letters[wanted_char_num])
            {
                letters_combination.erase((letters_combination.begin()+char_comb_num));

                if(wanted_char_num==(part_of_letters.size()-1))
                {
                    return(0);
                }

                return(check_combination(part_of_letters,letters_combination,wanted_char_num+1,char_comb_num));
            }
        }

    return(1);
}


int combination_check(string first_letters,string second_letters,string letters_combination)
{
    vector<char> first_chars=string_to_vector(first_letters);
    vector<char> second_chars=string_to_vector(second_letters);
    vector<char> chars_combination=string_to_vector(letters_combination);

    if(check_combination(first_chars,chars_combination)==0)
    {
        if(check_combination(second_chars,chars_combination)==0)
        {
            if(chars_combination.size()==0)
            {
                return(0);
            }
        }
    }
    return(1);
}

void result_printer(int did_letters_combination_correctly)
{
    if(did_letters_combination_correctly==0)
    {
        cout<<TRUE_RESULT_MASSAGE<<endl;
    }
    else
    {
        cout<<FALSE_RESULT_MASSAGE<<endl;
    }
}



int main()
{
    string first_letters , second_letters , letters_combination;
    int did_letters_combination_correctly;


    cin>>first_letters;
    cin>>second_letters;
    cin>>letters_combination;


    did_letters_combination_correctly=combination_check(first_letters,second_letters,letters_combination);


    result_printer(did_letters_combination_correctly);
}