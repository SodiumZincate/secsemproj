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
    team_ground = list[14];

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
    cout << "team_ground :: " << team_ground  << endl;

	cout << list.size() << endl;
}

void League::update_group_positions()
{ 
	int teams_in_group = ceil(static_cast<float>(league_team_number) / league_groups);
    Team Ta[MAX_TEAMS];
    int i, j, k;
    // Function to update group positions based on points

	for (int i = 0; i < league_groups; ++i) {
		std::vector<Team> group_teams;

		// Collect teams belonging to the current group
		for (int j = 0; j < league_team_number; ++j) {
			if (T[j].team_group == static_cast<char>(i + 65)) {
				group_teams.push_back(T[j]);
			}
		}

		// Sort the collected teams based on their points
		std::sort(group_teams.begin(), group_teams.end(), [](const Team& a, const Team& b) {
			return a.team_points > b.team_points; // Descending order
		});

		// Update positions of the sorted teams in the original array
		for (int k = 0; k < group_teams.size(); ++k) {
			for (int j = 0; j < league_team_number; ++j) {
				if (T[j].team_id == group_teams[k].team_id) {
					T[j].team_position = k + 1; // Positions start from 1
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
    league_round_robin = stoi(list[3]);
    league_qualifiers = stoi(list[4]);
    league_groups = stoi(list[5]);
    league_team_number = stoi(list[6]);
    League_start_date = list[7];
    league_no_of_match_times = stoi(list[8]);
    stringstream temp_match_times;
	temp_match_times << list[9];

	cout << "league_id :: " << league_id << endl;
    cout << "league_user_id :: " << league_user_id << endl;
    cout << "league_name :: " << league_name << endl;
	cout << "league_round_robin :: " << league_round_robin << endl;
    cout << "league_qualifiers :: " << league_qualifiers << endl;
    cout << "league_groups :: " << league_groups << endl;
    cout << "league_team_number :: " << league_team_number << endl;
    cout << "league_start_date :: " << League_start_date << endl;
    cout << "league_no_of_match_times :: " << league_no_of_match_times << endl;
	
	int i = 0;
	while(getline(temp_match_times, token, '\t')){
		league_match_times[i] = token;
		cout << "league_match_times"<<"["<<i<<"] :: " << league_match_times[i] << endl;
		i++;
	}
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

void League::update_league_data()
{
    // string ret;
    // ret = to_string(league_id) + "\n" + to_string(league_user_id) + "\n" + league_name + "\n" +  "\n" + to_string(league_round_robin) + "\n" +
    // to_string(league_qualifiers) + "\n" + to_string(league_groups) + "\n" + to_string(league_team_number);
}

void League::updateDatabaseTeam()
{
    stringstream clientRes; // irrevelant

    int i;
    for (i = 0; i < league_team_number; i++)
    {
		string ret;
        ret += to_string(T[i].team_id) + "\n" + to_string(T[i].team_user_id) + "\n" + 
        to_string(T[i].team_league_id) + "\n" + T[i].team_name + "\n" + T[i].team_group + "\n" +
        to_string(T[i].team_position) + "\n" + to_string(T[i].team_mp) + "\n" + to_string(T[i].team_w) + "\n" +
        to_string(T[i].team_l) + "\n" + to_string(T[i].team_d) + "\n" + to_string(T[i].team_gf) + "\n" +
        to_string(T[i].team_ga) + "\n" + to_string(T[i].team_gd) + "\n" + to_string(T[i].team_points) + "\n"
		+ T[i].team_ground;

		cout << "Updated team data: " << ret << endl;
		
		int errorDatabase = updateDatabase(ret, "update_team", clientRes);
		if(errorDatabase!=0){
			std::cout << "\nError initializing database" << std::endl;
		}
		else{
			std::cout << "Team updated successfully" << std::endl;
		}
    }
}