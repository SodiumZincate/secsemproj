#include "logic.h"

int main()
{
    League L; 
    string input_string_1, input_string_2; 
    //two strings that are inputted from "Add League" page, 
    //1 contains team names and ids for a league, 2 contains league's fixed properties 
    
    L.init_league(input_string_1); //initialize with string 1
    L.init_teams_array(input_string_2, L.T); //initialize with string 2
}