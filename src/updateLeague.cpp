#include "logic.h"

//this file is used to update league data and return the updated league data

void updateLeague(string input_string_1, string input_string_2)
{
    League L;
    //input_string_1 -> string that is received from database, contains league's fixed properties 
    //input_string_2 -> string that is received from database, contains teams' fixed properties 
    
    //initialize with string 1 (league's fixed properties)
    L.init_league(input_string_1);

    //initialize with string 2 (teams' fixed properties)
    int i;
    stringstream tokenStream;
    string token;
    tokenStream << input_string_2;

    for (i = 0; i < L.league_team_number; i++)
    {
        string team_string;
        team_string.clear();

        int j;
        for(j = 0; j < 14; j++)
        {
            getline(tokenStream, token, '\n');
            team_string += token + "\n";
        }
		cout << "Team: " << team_string << endl;

        //'i'th member of array of teams of league L is initialized using string input_string_2[i]
        L.T[i].init_team(team_string);
    }

    //sort according to points in a group
    L.update_group_positions();

    //return league
    L.ret_league();
}