#include "logic.h"

//this file is used to return match object

Match displayMatch(League L)
{
	string clientReq = to_string(L.league_id);
	std::stringstream clientResMatchNumber;
	std::string token;
	int errorDatabase = updateDatabase(clientReq, "query_match", clientResMatchNumber);
	if(errorDatabase != 0){
		std::cout << "\nError initializing match database" << std::endl;
		exit(1);
	}
	else{
		getline(clientResMatchNumber, token, '\n');
	}

	int no_of_match = stoi(token);
	Match M[no_of_match];

	clientReq.clear();
	clientReq = to_string(L.league_user_id) + "\n" + to_string(L.league_id);
	std::stringstream clientResMatch;

	int errorDatabase = updateDatabase(clientReq, "query_match", clientResMatch);
	if(errorDatabase != 0){
		std::cout << "\nError initializing match database" << std::endl;
		exit(1);
	}
	else{
		int i;
		bool isRunning = true;
		for(i = 0; i < no_of_match; i++);
		{
			string match_string;
			match_string.clear();

			int j;
			for(j = 0; j < 9; j++)
			{
				getline(clientResMatch, token, '\n');
				match_string += token + "\n";
				
			}

			stringstream tokenStream(match_string);
			vector<string> list;
			while(getline(tokenStream, token, '\n'))
			{
				list.push_back(token);
			}

			M[i].match_id=stoi(list[0]);
		    M[i].match_user_id = stoi(list[1]);
		    M[i].match_league_lid = stoi(list[2]);
			int tid_1 = stoi(list[3]);
			int tid_2 = stoi(list[4]);
			M[i].T1_score = stoi(list[5]);
			M[i].T2_score = stoi(list[6]);
			M[i].match_date = L.League_start_date;
			M[i].match_date = list[7];
			M[i].match_time = list[8];
			M[i].match_occur = stoi(list[9]);

			for(int j = 0; j<L.league_team_number; j++){
				if(L.T[j].team_id == tid_1){
					M[i].T1 = L.T[j];
				}
				if(L.T[j].team_id == tid_2){
					M[i].T2 = L.T[j];
				}
			}
		}
	}
}