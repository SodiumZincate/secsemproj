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
    public:

    //properties of a team that are fixed, initialized using user input
    string team_name;
    int team_id;
    int team_user_id;
    int team_league_id;

    //properties of a team that are fixed, initialized by program
    char team_group;

    //properties of a team that are not fixed
    int team_mp = 0;
    int team_w = 0;
    int team_d = 0;
    int team_l = 0;
    int team_gf = 0;
    int team_ga = 0;
    int team_gd = 0;
    int team_points = 0;
    int team_position = 0;

    //methods
    Team() {}
    //function to initialize a team's fixed properties in a league, based on the input string from database
    void init_team(string input_string);
    //function that updates a team data
    void update_team_data(int goals_for, int goals_against);
};

//class for a league
class League
{
    public:

    //properties of a league, all fixed, initialized
    int league_id;
    int league_user_id;
    string league_name;
    int league_group_stages;
    int league_round_robin;
    int league_qualifiers;
    int league_groups;
    int league_team_number;

    //array of teams for a league
    Team T[MAX_TEAMS];

    League() {}
    //function to update position of teams in a group of a league based on points 
    void update_group_positions();
    //function to initialize league's fixed properties, based on the input string from database
    void init_league(string input_string);
    //function that sorts team array of a league alphabetically
    void sort_teams_array();
    //function to return properties of a league
    string ret_league();
    //function to return teams of a league
    string ret_teams();
};

void clickLeague(string input_string_1, string input_string_2);
