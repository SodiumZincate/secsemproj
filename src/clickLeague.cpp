#include "logic.h"

//this file is used to create a league using database input when the "Add league" button is clicked

void clickLeague(string input_string_1 )
{
    League L;
    //string that is received from database, contains league's fixed properties 
    ;
    //array of string that is received from database, containing teams' fixed properties for a league
    string input_string_2[MAX_TEAMS];

	cout << input_string_1 << endl;
    
    //initialize with string 1 (league's fixed properties)
    L.init_league(input_string_1);
    //initialize with string 2 (teams' fixed properties)
    int i;
    for (i = 0; i < L.league_team_number; i++)
    {
        //'i'th member of array of teams of league L is initialized using string input_string_2[i]
        L.T[i].init_team(input_string_2[i]);
    }

    //alphabetically arrange teams in the team array of a league
    L.sort_teams_array();
}