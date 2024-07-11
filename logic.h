#pragma once

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define MAX_TEAMS 50

//class for a team
class Team
{
    //properties of a team that are fixed, initialized
    public:
    string name;
    int team_id;

    //properties of a team that are not fixed
    public:
    int mp = 0;
    int w = 0;
    int d = 0;
    int l = 0;
    int gf = 0;
    int ga = 0;
    int gd = 0;
    int points = 0;

    public:
    Team();
    Team(string a, int b); //constructor which initializes name and team id
    void update_team_data(int f, int a); //function that updates a team data
};

Team::Team(string a, int b)
{
    name = a;
    team_id = b;
}

void Team::update_team_data(int f, int a)
{
    mp++;

    if (f > a)
    {
        w++;
        points += 3;
    }
    
    else if (f < a)
    {
        l++;
    }

    else
    {
        d++;
        points += 1;
    }

    gf += f;
    ga += a;
    gd += (f - a);
}

//class for a league
class League
{
    //properties of a team, all fixed, initialized
    public:
    string name;
    int league_id;
    int group_stages;
    int round_robin;
    int qualifiers;
    int groups;
    int team_number;

    //array of teams for a league
    Team T[MAX_TEAMS];

    public:
    League();
    League(string a, int b, int c, int d, int e, int f, int g);  //constructor which initializes all properties
    void update_league_positions(); //function to update position of teams in a league based on points 
};

League::League(string a, int b, int c, int d, int e, int f, int g)
{
    name = a;
    league_id = b;
    group_stages = c;
    round_robin = d;
    qualifiers = e;
    groups = f;
    team_number = g;
}

void League::update_league_positions()
{ 
    int i, j; 
    for (i = 0; i < team_number - 1; i++) 

        for (j = 0; j < team_number - i - 1; j++) 

            if (T[j].points > T[j + 1].points) 
                swap(T[j], T[j + 1]); 
} 

//function to initialize teams' fixed properties in a league
void init_teams_array(Team T[], int s)
{
    int i, j;
    for (i = 0; i < s; i++)
    {
        T[i].name = "";
        T[i].team_id = i+1; 
    }
}
