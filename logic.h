#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define MAX_TEAMS 50

//class for a team
class Team
{
    //properties of a team that are fixed, initialized
    public:
    string team_name;
    int team_id;

    //properties of a team that are not fixed
    public:
    int team_mp = 0;
    int team_w = 0;
    int team_d = 0;
    int team_l = 0;
    int team_gf = 0;
    int team_ga = 0;
    int team_gd = 0;
    int team_points = 0;

    //methods
    public:
    Team();
    Team(string name, int id); //constructor which initializes team name and team id
    void update_team_data(int goals_for, int goals_against); //function that updates a team data
};

Team::Team(string name, int id)
{
    team_name = name;
    team_id = id;
}

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

//class for a league
class League
{
    //properties of a league, all fixed, initialized
    public:
    string league_name;
    int league_id;
    int league_group_stages;
    int league_round_robin;
    int league_qualifiers;
    int league_groups;
    int league_team_number;

    //array of teams for a league
    Team T[MAX_TEAMS];

    public:
    League();
    League(string name, int id, int gs, int rr, int q, int g, int n);  //constructor which initializes all properties
    void update_league_positions(); //function to update position of teams in name league based on points 
    void init_teams_array(string input_string, Team T[]); //function to initialize teams' fixed properties(name, id) in a league, based on the input string
};

League::League(string name, int id, int gs, int rr, int q, int g, int n)
{
    league_name = name;
    league_id = id;
    league_group_stages = gs;
    league_round_robin = rr;
    league_qualifiers = q;
    league_groups = g;
    league_team_number = n;
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