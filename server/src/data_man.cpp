#include "data_man.h"

// Callback function is called for each row
// data = database, argc = no. of columns in a row,
// argv = array of strings where each string is the value of a column in the row
// azcolName = array of strings where each string is the name of the column
static int callback(void* data, int argc, char **argv, char** azcolName){
	int i;
	for(i=0; i<argc; i++){
		QR1.result.push_back(argv[i]);
	}
	return 0;
}

static int maxIDCallback(void* data, int argc, char** argv, char** azColName) {
    if (argc > 0 && argv[0]) {
        QR1.result.push_back(argv[0]);
    }
    return 0;
}

void queryTeam(sqlite3 *db){
	char *errMsg;
	string sqlQuery = "SELECT * FROM TEAM";
	if(sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg) != SQLITE_OK){
		cerr << "SQL Error: " << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
}

void queryLeague(sqlite3 *db){
	char *errMsg;
	string sqlQuery = "SELECT * FROM LEAGUE";
	if(sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg) != SQLITE_OK){
		cerr << "SQL Error: " << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
}

void insertDatabaseMatch(string cli_req, string file){
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	std::vector<string> string_list;
	std::string token;
	istringstream tokenStream(cli_req);
	while(getline(tokenStream, token, '\n')){
		string_list.push_back(token);
	}

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	string uid = string_list[0];
	string lid = string_list[1];
	string tid1 = string_list[2];
	string tid2 = string_list[3];
	string team1_goal = string_list[4];
	string team2_goal = string_list[5];
	string match_date = string_list[6];
	string match_time = string_list[7];
	string played = string_list[8];

	stringstream ss;
	ss << "INSERT INTO MATCH(UID,LID,TID1,TID2,TEAM1GOAL,TEAM2GOAL,MATCHDATE,MATCHTIME,PLAYED) VALUES"
	<< "("
	<< "'" << uid << "',"
	<< "'" << lid << "',"
	<< "'" << tid1 << "',"
	<< "'" << tid2 << "',"
	<< "'" << team1_goal << "',"
	<< "'" << team2_goal << "',"
	<< "'" << match_date << "',"
	<< "'" << match_time << "',"
	<< "'" << played << "'"
	<< ")";

	string sqlInsert = ss.str();
	exit = sqlite3_exec(db, sqlInsert.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error inserting data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Data inserted successfully" << std::endl;
	}

	sqlite3_close(db);
}

void insertDatabaseTeam(string cli_req, string file){
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	std::vector<string> string_list;
	std::string token;
	istringstream tokenStream(cli_req);
	while(getline(tokenStream, token, '\n')){
		string_list.push_back(token);
	}

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	string uid = string_list[0];
	string lid = string_list[1];
	string team_name = string_list[2];
	string group = string_list[3];
	string position = string_list[4];
	string mp = string_list[5];
	string win = string_list[6];
	string loss = string_list[7];
	string draw = string_list[8];
	string gf = string_list[9];
	string ga = string_list[10];
	string gd = string_list[11];
	string point = string_list[12];
	string ground = string_list[13];

	stringstream ss;
	ss << "INSERT INTO TEAM(UID,LID,TNAME,TGROUP,POSITION,MP,WIN,LOSS,DRAW,GF,GA,GD,POINTS,GROUND) VALUES"
	<< "("
	<< "'" << uid << "',"
	<< "'" << lid << "',"
	<< "'" << team_name << "',"
	<< "'" << group << "',"
	<< "'" << position << "',"
	<< "'" << mp << "',"
	<< "'" << win << "',"
	<< "'" << loss << "',"
	<< "'" << draw << "',"
	<< "'" << gf << "',"
	<< "'" << ga << "',"
	<< "'" << gd << "',"
	<< "'" << point << "',"
	<< "'" << ground << "'"
	<< ")";

	string sqlInsert = ss.str();
	exit = sqlite3_exec(db, sqlInsert.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error inserting data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Data inserted successfully" << std::endl;
	}

	sqlite3_close(db);
}

void queryDatabase(string cli_req, string file, Response &res){
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	std::vector<string> string_list;
	std::string token;
	istringstream tokenStream(cli_req);
	while(getline(tokenStream, token, '\n')){
		string_list.push_back(token);
	}

	string username = string_list[0];

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open League database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "League Database opened successfully" << std::endl;
	}

	stringstream ss;
	ss << "SELECT UID, USERNAME, EMAIL, PASSWORD FROM USER WHERE USERNAME"
	<< "="
	<< "'" + username + "'";

	QR1.result.clear();
	
	string sqlQuery = ss.str();
	exit = sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error Querying Data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Data Queried successfully" << std::endl;
		stringstream content;
		for(string &c : QR1.result){
			content << c;
			content << "\n";
		}
		string line;
		bool userExists = false;
		while(getline(content, line, '\n')){
			if(strcmp(line.c_str(), username.c_str()) == 0){
				userExists = true;
				break;
			}
		}
		if(userExists){
			res.set_content(content.str(), "text/plain");
		}
		else{
			res.set_content("\n\n\n", "text/plain");
		}
	}
	
	sqlite3_close(db);	
}

void insertDatabaseLeague(string cli_req, string file, Response &res){
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	std::vector<string> string_list;
	std::string token;
	istringstream tokenStream(cli_req);
	while(getline(tokenStream, token, '\n')){
		string_list.push_back(token);
	}

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	string uid = string_list[0];
	string league_name = string_list[1];
	string round_robin = string_list[2];
	string qualifiers = string_list[3];
	string no_of_groups = string_list[4];
	string no_of_teams = string_list[5];
	string start_date = string_list[6];
	string no_of_match_times = string_list[7];
	string match_times = string_list[8];

	stringstream ss;
	ss << "INSERT INTO LEAGUE(UID,LNAME,ROUNDROBIN,QUALIFIERS,NUMBEROFGROUPS,NUMBEROFTEAMS,STARTDATE,NUMBEROFMATCHTIMES,MATCHTIMES) VALUES"
	<< "("
	<< "'" << uid << "',"
	<< "'" << league_name << "',"
	<< "'" << round_robin << "',"
	<< "'" << qualifiers << "',"
	<< "'" << no_of_groups << "',"
	<< "'" << no_of_teams << "',"
	<< "'" << start_date << "',"
	<< "'" << no_of_match_times << "',"
	<< "'" << match_times << "'"
	<< ")";

	string sqlInsert = ss.str();
	exit = sqlite3_exec(db, sqlInsert.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error inserting league data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "League Data inserted successfully" << std::endl;

		stringstream ss1;
		ss1 << "SELECT MAX(LID) FROM LEAGUE";

		QR1.result.clear();
		
		string sqlQuery = ss1.str();
		exit = sqlite3_exec(db, sqlQuery.c_str(), maxIDCallback, 0, &errMsg);
		if(exit!=SQLITE_OK){
			cerr << "Error retrieving max league data" << std::endl;
			cerr << errMsg << std::endl;
			sqlite3_free(errMsg);
		}
		else{
			stringstream content;
			for(string &c : QR1.result){
				content << c;
				content << "\n";
			}
			res.set_content(content.str(), "text/plain");
		}
	}

	sqlite3_close(db);
}

void insertDatabase(string cli_req, string file)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	std::vector<string> string_list;
	std::string token;
	istringstream tokenStream(cli_req);
	while(getline(tokenStream, token, '\n')){
		string_list.push_back(token);
	}

	string username = string_list[0];
	string email = string_list[1];
	string password = string_list[2];

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	stringstream ss;
	int LID = 1;
	ss << "INSERT INTO USER(USERNAME,EMAIL,PASSWORD) VALUES"
	<< "("
	<< "'" << username << "',"
	<< "'" << email << "',"
	<< "'" << password << "'"
	<< ")";

	string sqlInsert = ss.str();
	exit = sqlite3_exec(db, sqlInsert.c_str(), callback, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error inserting data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Data inserted successfully" << std::endl;
	}

	sqlite3_close(db);
	
}

void deleteDatabaseLeague(string cli_req, string file)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	std::vector<string> string_list;
	std::string token;
	istringstream tokenStream(cli_req);
	while(getline(tokenStream, token, '\n')){
		string_list.push_back(token);
	}

	string league_id = string_list[0];

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "deleting Database opened successfully" << std::endl;
	}

	stringstream ss;
	ss << "DELETE FROM LEAGUE WHERE LID = " << league_id;

	string sqlDelete = ss.str();
	exit = sqlite3_exec(db, sqlDelete.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error deleting data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Data deleted successfully" << std::endl;
	}
	
	sqlite3_close(db);
}

void deleteDatabase(string cli_req, string file)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	std::vector<string> string_list;
	std::string token;
	istringstream tokenStream(cli_req);
	while(getline(tokenStream, token, '\n')){
		string_list.push_back(token);
	}

	string username = string_list[0];
	string email = string_list[1];
	string password = string_list[2];

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	stringstream ss;
	ss << "DROP TABLE TEAM";

	string sqlDelete = ss.str();
	exit = sqlite3_exec(db, sqlDelete.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error deleting data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Data deleted successfully" << std::endl;
	}
	
	sqlite3_close(db);
}

void updateDatabaseTeam(string cli_req, string file, Response &res)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	std::vector<string> string_list;
	std::string token;
	istringstream tokenStream(cli_req);
	while(getline(tokenStream, token, '\n')){
		string_list.push_back(token);
	}

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	string tid = string_list[0];
	string uid = string_list[1];
	string lid = string_list[2];
	string team_name = string_list[3];
	string group = string_list[4];
	string position = string_list[5];
	string mp = string_list[6];
	string win = string_list[7];
	string loss = string_list[8];
	string draw = string_list[9];
	string gf = string_list[10];
	string ga = string_list[11];
	string gd = string_list[12];
	string point = string_list[13];
	string ground = string_list[14];

	stringstream ss;
	ss << "UPDATE TEAM SET "
	<< "UID = '" << uid << "', "
	<< "LID = '" << lid << "', "
	<< "TNAME = '" << team_name << "', "
	<< "TGROUP = '" << group << "', "
	<< "POSITION = '" << position << "', "
	<< "MP = '" << mp << "', "
	<< "WIN = '" << win << "', "
	<< "LOSS = '" << loss << "', "
	<< "DRAW = '" << draw << "', "
	<< "GF = '" << gf << "', "
	<< "GA = '" << ga << "', "
	<< "GD = '" << gd << "', "
	<< "POINTS = '" << point << "', "
	<< "GROUND = '" << ground << "' "
	<< "WHERE TID = '" << tid << "';";

	string sqlUpdate = ss.str();
	exit = sqlite3_exec(db, sqlUpdate.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error updating team" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "team updated successfully" << std::endl;
	}

	sqlite3_close(db);
}

void updateDatabaseMatch(string cli_req, string file){
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	std::vector<string> string_list;
	std::string token;
	istringstream tokenStream(cli_req);
	while(getline(tokenStream, token, '\n')){
		string_list.push_back(token);
	}

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	string mid = string_list[0];
	string team1_goal = string_list[1];
	string team2_goal = string_list[2];

	stringstream ss;
	ss << "UPDATE MATCH SET "
	<< "TEAM1GOAL = '" << team1_goal << "', "
	<< "TEAM2GOAL = '" << team2_goal << "', "
	<< "PLAYED = '" << 1 << "' "
	<< "WHERE MID = '" << mid << "';";

	string sqlInsert = ss.str();
	exit = sqlite3_exec(db, sqlInsert.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error updating match" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "match updated successfully" << std::endl;
	}

	sqlite3_close(db);
}

void queryDatabaseTeam(string cli_req, string file, Response &res)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	stringstream stream;
	stream << cli_req;

	string token;

	getline(stream, token, '\n');
	string user_id = token;
	getline(stream, token, '\n');
	string league_id = token;

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	stringstream ss;
	ss << "SELECT TID,UID,LID,TNAME,TGROUP,POSITION,MP,WIN,LOSS,DRAW,GF,GA,GD,POINTS,GROUND FROM TEAM WHERE UID"
	<< "="
	<< "'" + user_id + "'"
	<< " AND LID"
	<< '='
	<< "'" + league_id + "'";

	QR1.result.clear();
	
	string sqlQuery = ss.str();
	exit = sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error Querying Data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Data Queried successfully" << std::endl;
		stringstream content;
		for(string &c : QR1.result){
			content << c;
			content << "\n";
		}
		
		string line;
		bool teamExists = false;
		getline(content, line, '\n');
		if(strcmp(line.c_str(), "") != 0){
			teamExists = true;
		}
		if(teamExists){
			res.set_content(content.str(), "text/plain");
		}
		else{
			res.set_content("\n\n\n", "text/plain");
		}
	}

	
	sqlite3_close(db);
}

void queryDatabaseTeamID(string cli_req, string file, Response &res)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	stringstream ss1;
		ss1 << "SELECT MAX(TID) FROM TEAM";

		QR1.result.clear();
		
		string sqlQuery = ss1.str();
		exit = sqlite3_exec(db, sqlQuery.c_str(), maxIDCallback, 0, &errMsg);
		if(exit!=SQLITE_OK){
			cerr << "Error retrieving max league data" << std::endl;
			cerr << errMsg << std::endl;
			sqlite3_free(errMsg);
		}
		else{
			if(QR1.result.empty()){
			}
			stringstream content;
			for(string &c : QR1.result){
				content << c;
				content << "\n";
			}
			res.set_content(content.str(), "text/plain");
		}
	
	sqlite3_close(db);
}

void queryDatabaseMatchNumber(string cli_req, string file, Response &res){
    sqlite3* db;
    int exit = 0;
    char* errMsg;

	string league_id = cli_req;

    exit = sqlite3_open(file.c_str(), &db);
    if (exit) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        std::exit(1);
    } else {
        std::cout << "Database opened successfully" << std::endl;
    }

    std::stringstream ss1;
    ss1 << "SELECT COUNT(*) FROM MATCH WHERE LID = " << league_id;

    QR1.result.clear();

    std::string sqlQuery = ss1.str();
    exit = sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg);
    if (exit != SQLITE_OK) {
        std::cerr << "Error retrieving count data" << std::endl;
        std::cerr << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::stringstream content;
        for(string &c : QR1.result){
			content << c;
			content << "\n";
		}
        res.set_content(content.str(), "text/plain");
    }

    sqlite3_close(db);
}

void queryDatabaseLeague(string cli_req, string file, Response &res)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	string league_id = cli_req;

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	stringstream ss;
	ss << "SELECT LID,UID,LNAME,ROUNDROBIN,QUALIFIERS,NUMBEROFGROUPS,NUMBEROFTEAMS,STARTDATE,NUMBEROFMATCHTIMES,MATCHTIMES FROM LEAGUE WHERE LID"
	<< "="
	<< "'" + league_id + "'";

	QR1.result.clear();
	
	string sqlQuery = ss.str();
	exit = sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error Querying Data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Data Queried successfully" << std::endl;
		stringstream content;
		for(string &c : QR1.result){
			content << c;
			content << "\n";
		}
		
		string line;
		bool leagueExists = false;
		getline(content, line, '\n');
		if(strcmp(line.c_str(), "") != 0){
			leagueExists = true;
		}
		if(leagueExists){
			res.set_content(content.str(), "text/plain");
		}
		else{
			res.set_content("\n\n\n", "text/plain");
		}
	}

	sqlite3_close(db);
}

void queryDatabaseMatch(string cli_req, string file, Response &res)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	stringstream stream;
	stream << cli_req;

	string token;

	getline(stream, token, '\n');
	string user_id = token;
	getline(stream, token, '\n');
	string league_id = token;

	exit = sqlite3_open(file.c_str(), &db);
	std::cout << file.c_str() << std::endl;
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	stringstream ss;
	ss << "SELECT MID,UID,LID,TID1,TID2,TEAM1GOAL,TEAM2GOAL,MATCHDATE,MATCHTIME,PLAYED FROM MATCH WHERE UID"
	<< "="
	<< "'" + user_id + "'"
	<< " AND LID"
	<< '='
	<< "'" + league_id + "'";

	QR1.result.clear();
	
	string sqlQuery = ss.str();
	exit = sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error Querying Match Data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Match Data Queried successfully" << std::endl;
		stringstream content;
		for(string &c : QR1.result){
			content << c;
			content << "\n";
		}
		
		string line;
		bool leagueExists = false;
		getline(content, line, '\n');
		if(strcmp(line.c_str(), "") != 0){
			leagueExists = true;
		}
		if(leagueExists){
			res.set_content(content.str(), "text/plain");
		}
		else{
			res.set_content("\n\n\n", "text/plain");
		}
	}

	sqlite3_close(db);
}

void queryDatabaseLeagueList(string cli_req, string file, Response &res)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	string user_id = cli_req;

	exit = sqlite3_open(file.c_str(), &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	stringstream ss;
	ss << "SELECT LID,LNAME FROM LEAGUE WHERE UID"
	<< "="
	<< "'" + user_id + "'";

	QR1.result.clear();
	
	string sqlQuery = ss.str();
	exit = sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error Querying Data" << std::endl;
		cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else{
		std::cout << "Data Queried successfully" << std::endl;
		stringstream content;
		for(string &c : QR1.result){
			content << c;
			content << "\n";
		}
		
		string line;
		bool leagueExists = false;
		getline(content, line, '\n');
		if(strcmp(line.c_str(), "") != 0){
			leagueExists = true;
		}
		if(leagueExists){
			res.set_content(content.str(), "text/plain");
		}
		else{
			res.set_content("\n\n\n", "text/plain");
		}
	}
	
	sqlite3_close(db);
}
