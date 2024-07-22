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

void Team::init_team(string input_string)
{
    string token;
    stringstream tokenStream(input_string);
    vector<string> list;
    while(getline(tokenStream, token, '\n'))
    {
        list.push_back(token);
    }
    team_id = stoi(list[0]);
    team_user_id = stoi(list[1]);
    team_league_id = stoi(list[2]);
    team_name = list[3];
    team_group = list[4];
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
    stringstream tokenStream(input_string);
    vector<string> list;
    while(getline(tokenStream, token, '\n'))
    {
        list.push_back(token);
    }   
    league_id = stoi(list[0]);
    league_user_id = stoi(list[1]);
    league_name = list[2];
    league_group_stages = stoi(list[3]);
    league_round_robin = stoi(list[4]);
    league_qualifiers = stoi(list[5]);
    league_groups = stoi(list[6]);
    league_team_number = stoi(list[7]);
}

void League::sort_teams_array()
{
    int i, j;
    for (i = 0; i < league_team_number - 1; i++) 
    {
        for (j = 0; j < league_team_number - i - 1; j++) 
        {
            if (strcmp((T[j].team_name.c_str()) , T[j + 1].team_name.c_str()) > 0)
            swap(T[j], T[j + 1]); 
        }
    }
}

void League::init_group(Team T[])
{
    char group[20];
    int i, j, k;
    for (i = 0; i < league_groups; i++)
    {
        group[i] = (char) (65 + i);
    }

    k = 0;
    for(int j = 0; j < league_groups; j++)
    {
        for (i = j; i < league_team_number; i += league_groups)
        {
            T[i].team_group = group[j];
        }
        k++;
    }
}