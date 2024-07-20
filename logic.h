#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
    Team() {}
    //function that updates a team data
    void update_team_data(int goals_for, int goals_against); 
};

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
    League() {}
    //function to update position of teams in name league based on points 
    void update_league_positions(); 
    //function to initialize league's fixed properties, based on the input string
    void init_league(string input_string); 
    //function to initialize teams' fixed properties(name, id) in a league, based on the input string
    void init_teams_array(string input_string, Team T[]); 
};