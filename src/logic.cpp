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
    team_group = (list[4].c_str())[0];
    team_position = stoi(list[5]);
    team_mp = stoi(list[6]);
    team_w = stoi(list[7]);
    team_l = stoi(list[8]);
    team_d = stoi(list[9]);
    team_gf = stoi(list[10]);
    team_ga = stoi(list[11]);
    team_gd = stoi(list[12]);
    team_points = stoi(list[13]);
}

void League::update_group_positions()
{ 
    int teams_in_group = ceil(league_groups / league_team_number);
    int &t = teams_in_group;
    Team Ta[MAX_TEAMS];
    int i, j, k;
    for (i = 0; i < league_groups; i++)
    {
        for (j = 0; j < league_team_number; j++)
        {
            if (T[j].team_group == (char) (i + 65))
            {
                Ta[i] = T[j];
            }
        }

        for (k = 0; k < t - 1; k++) 
        {
            for (j = 0; j < t - i - 1; j++) 
            {
                if (Ta[j].team_points > Ta[j + 1].team_points) 
                swap(Ta[j], Ta[j + 1]); 
            }
        }

        for (k = 0; k < t; k++)
        {
            for (j = 0; j < league_team_number; j++)
            {
                if (Ta[k].team_id == T[j].team_id)
                {
                    T[j].team_position = k;
                }
            }
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

string League::ret_league()
{
    string token;
    stringstream tokenStream(input_string);
    vector<string> list;
    while(getline(tokenStream, token, '\n'))
    {
        list.push_back(token);
    }   
     =  = stoi(list[0]) = league_id
     = stoi(list[1]) = league_user_id
     = list[2] = league_name
     = stoi(list[3]) = league_group_stages
     = stoi(list[4]) = league_round_robin
     = stoi(list[5]) = league_qualifiers
     = stoi(list[6]) = league_groups
     = stoi(list[7]) = league_team_number
}