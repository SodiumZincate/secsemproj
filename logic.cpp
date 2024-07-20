#include "logic.h"

void Team::update_team_data(int goals_for, int goals_against)
{
    team_mp++;

    if (goals_for > goals_against)
    {
        team_w++;
        team_points += 3;
    }
    
    else if (goals_for < goals_against)
    {
        team_l++;
    }

    else
    {
        team_d++;
        team_points += 1;
    }

    team_gf += goals_for;
    team_ga += goals_against;
    team_gd += (goals_for - goals_against);
}

void League::update_league_positions()
{ 
    int i, j; 
    for (i = 0; i < league_team_number - 1; i++) 
    {
        for (j = 0; j < league_team_number - i - 1; j++) 
        {
            if (T[j].team_points > T[j + 1].team_points) 
            swap(T[j], T[j + 1]); 
        }
    }
}

void League::init_league(string input_string)
{
    string token;
    int i = 0;
    stringstream tokenStream(input_string);
    vector<string> list;
    while(getline(tokenStream, token, '\n'))
    {
        list.push_back(token);
    }   
    league_name = list[0];
    league_id = stoi(list[1]);
    league_group_stages = stoi(list[2]);
    league_round_robin = stoi(list[3]);
    league_qualifiers = stoi(list[4]);
    league_groups = stoi(list[5]);
    league_team_number = stoi(list[6]);
}

void League::init_teams_array(string input_string, Team T[])
{
    string input_names_a[MAX_TEAMS];
    string input_ids_a[MAX_TEAMS];

    string token;
    int i = 0;
    stringstream tokenStream(input_string);
    while(getline(tokenStream, token, '\n'))
    {
        if ((token.c_str())[0] >= 48 && (token.c_str())[0] <= 57)
            input_ids_a[i] = stoi(token);
        else
        {
            input_names_a[i] = token;
            i++;
        }
    }        

    for (i = 0; i < league_team_number; i++)
    {
        T[i].team_name = input_names_a[i];
        T[i].team_id = stoi(input_ids_a[i]);
    }

    int j;
    for (i = 0; i < league_team_number - 1; i++) 
    {
        for (j = 0; j < league_team_number - i - 1; j++) 
        {
            if (strcmp((T[j].team_name.c_str()) , T[j + 1].team_name.c_str()) > 0)
            swap(T[j], T[j + 1]); 
        }
    }
}