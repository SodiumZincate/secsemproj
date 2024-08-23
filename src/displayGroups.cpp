#include "logic.h"

//this file is used to return group object 

vector<Group> displayGroups(string input_string_1, string input_string_2)
{
    League L;
    //input_string_1 -> string that is received from database, contains league's fixed properties 
    //input_string_2 -> string that is received from database, contains teams' fixed properties 

    //initialize with string 1 (league's fixed properties)
    L.init_league(input_string_1);

    //initialize with string 2 (teams' fixed properties)
    int i, j, k;
    stringstream tokenStream;
    string token;
    tokenStream << input_string_2;

    for (i = 0; i < L.league_team_number; i++)
    {
        string team_string;
        team_string.clear();

        int j;
        for(j = 0; j < 15; j++)
        {
            getline(tokenStream, token, '\n');
            team_string += token + "\n";
        }

        //'i'th member of array of teams of league L is initialized using string input_string_2[i]
        L.T[i].init_team(team_string);
    }

    vector<Group> groupList;
    Group Ga;
    for (i = 0; i < L.league_groups; i++)
    {
        Ga.group_name = (char) (i + 65);
        groupList.push_back(Ga);
    }

    for (i = 0; i < L.league_groups; i++)
    {
        k = 0;
        for (j = 0; j < L.league_team_number; j++)
        {
            if (L.T[j].team_group == groupList[i].group_name)
            {
                groupList[i].T[k] = L.T[j];
                k++;
            }
        }
    }
    return groupList;
}