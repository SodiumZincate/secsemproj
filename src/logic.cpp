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

	cout << "team_id :: " << team_id << endl;
    cout << "team_user_id :: " << team_user_id << endl;
    cout << "team_league_id :: " << team_league_id << endl;
    cout << "team_name :: " << team_name<< endl;
	cout << "team_group :: " << team_group << endl;
    cout << "team_position :: " << team_position << endl;
    cout << "team_mp :: " << team_mp << endl;
    cout << "team_w :: " << team_w << endl;
    cout << "team_l :: " << team_l << endl;
    cout << "team_d :: " << team_d << endl;
    cout << "team_gf :: " << team_gf  << endl;
    cout << "team_ga :: " << team_ga  << endl;
    cout << "team_gd :: " << team_gd  << endl;
    cout << "team_points :: " << team_points  << endl;

	cout << list.size() << endl;
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

	cout << "league_id :: " << league_id << endl;
    cout << "league_user_id :: " << league_user_id << endl;
    cout << "league_name :: " << league_name << endl;
    cout << "league_group_stages :: " << league_group_stages<< endl;
	cout << "league_round_robin :: " << league_round_robin << endl;
    cout << "league_qualifiers :: " << league_qualifiers << endl;
    cout << "league_groups :: " << league_groups << endl;
    cout << "league_team_number :: " << league_team_number << endl;
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
    string ret;
    ret = to_string(league_id) + "\n" + to_string(league_user_id) + "\n" + league_name + "\n" + 
    to_string(league_group_stages) + "\n" + to_string(league_round_robin) + "\n" +
    to_string(league_qualifiers) + "\n" + to_string(league_groups) + "\n" + to_string(league_team_number);
	cout << "Return league: " << ret << endl;
    return ret;
}

string League::ret_teams()
{
    stringstream clientRes; // irrevelant

    string ret;
    int i;
    for (i = 0; i < league_team_number; i++)
    {
        ret = ret + to_string(T[i].team_id) + "\n" + to_string(T[i].team_user_id) + "\n" + 
        to_string(T[i].team_league_id) + "\n" + T[i].team_name + "\n" + T[i].team_group + "\n" +
        to_string(T[i].team_position) + "\n" + to_string(T[i].team_mp) + "\n" + to_string(T[i].team_w) + "\n" +
        to_string(T[i].team_l) + "\n" + to_string(T[i].team_d) + "\n" + to_string(T[i].team_gf) + "\n" +
        to_string(T[i].team_ga) + "\n" + to_string(T[i].team_gd) + "\n" + to_string(T[i].team_points) + "\n";
    }

    int errorDatabase = updateDatabase(ret, "team_update", clientRes);
    if(errorDatabase!=0){
        std::cout << "\nError initializing database" << std::endl;
    }
    cout << "Return Team: " << ret << endl;
    return ret;
    return ret;
}

string League::ret_group(Group G[])
{
    string ret;
    int i, j;
    for (i = 0; i < league_groups; i++)
    {
        ret = ret + to_string(G[i].group_name) + "\n";
        for (j = 0; j < sizeof(G[i].T); j++)
        {
            ret = ret + to_string(G[i].T[j].team_id) + "\n";
        }
    }
    return ret;
}