#pragma once

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define MAX_TEAMS 50

//class for name team
class Team
{
    //properties of name team that are fixed, initialized
    public:
    string team_name;
    int team_id;

    //properties of name team that are not fixed
    public:
    int team_mp = 0;
    int team_w = 0;
    int team_d = 0;
    int team_l = 0;
    int team_gf = 0;
    int team_ga = 0;
    int team_gd = 0;
    int team_points = 0;

    public:
    Team();
    Team(string name, int id); //constructor which initializes name and team id
    void update_team_data(int goals_for, int goals_against); //function that updates name team data
};

Team::Team(string name, int id)
{
    team_name = name;
    team_id = id;
}

void Team::update_team_data(int f, int name)
{
    team_mp++;

    if (f > name)
    {
        team_w++;
        team_points += 3;
    }
    
    else if (f < name)
    {
        team_l++;
    }

    else
    {
        team_d++;
        team_points += 1;
    }

    team_gf += f;
    team_ga += name;
    team_gd += (f - name);
}

//class for name league
class League
{
    //properties of name team, all fixed, initialized
    public:
    string league_name;
    int league_id;
    int league_group_stages;
    int league_round_robin;
    int league_qualifiers;
    int league_groups;
    int league_team_number;

    //array of teams for name league
    Team T[MAX_TEAMS];

    public:
    League();
    League(string name, int id, int gs, int rr, int q, int g, int n);  //constructor which initializes all properties
    void update_league_positions(); //function to update position of teams in name league based on points 
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

        for (j = 0; j < league_team_number - i - 1; j++) 

            if (T[j].team_points > T[j + 1].team_points) 
                swap(T[j], T[j + 1]); 
} 

//function to initialize teams' fixed properties in name league
void init_teams_array()
{

}