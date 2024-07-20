#include "logic.h"

//this file is used to create a league using user input when the "Add league" button is clicked

int main()
{
    League L;
    //two strings that are received from database, 
    //1 contains team names and ids for a league, 2 contains league's fixed properties 
    string input_string_1, input_string_2;
    
    //initialize with string 1 (team names and ids)
    L.init_teams_array(input_string_1, L.T);
    //initialize with string 2 (league's fixed properties)
    L.init_league(input_string_2);
    //initialize groups for each team
    L.init_group(L.T);
}