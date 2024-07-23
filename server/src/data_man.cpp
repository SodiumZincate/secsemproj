#include "data_man.h"

// Callback function is called for each row
// data = database, argc = no. of columns in a row,
// argv = array of strings where each string is the value of a column in the row
// azcolName = array of strings where each string is the name of the column
static int callback(void* data, int argc, char **argv, char** azcolName){
	int i;
	for(i=0; i<argc; i++){
		std::cout << azcolName[i] << " = " << argv[i] << std::endl;
		QR1.result.push_back(argv[i]);
	}
	std::cout << std::endl;
	return 0;
}

static int maxLIDCallback(void* data, int argc, char** argv, char** azColName) {
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
	std::cout << file.c_str() << std::endl;
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

	stringstream ss;
	ss << "INSERT INTO TEAM(UID,LID,TNAME,TGROUP,POSITION,MP,WIN,LOSS,DRAW,GF,GA,GD,POINTS) VALUES"
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
	<< "'" << point << "'"
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

	std::cout << "Table Contents: " << std::endl;
	queryTeam(db);

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
	std::cout << file.c_str() << std::endl;
	if(exit){
		cerr << "Failed to open League database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "League Database opened successfully" << std::endl;
	}

	stringstream ss;
	ss << "SELECT LID, USERNAME, EMAIL, PASSWORD FROM DATA WHERE USERNAME"
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
		// std::cout << QR1.result[1] << std::endl;
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
			std::cout << "The user: " << username << " exists\n" << std::endl;
			res.set_content(content.str(), "text/plain");
		}
		else{
			std::cout << "The user: " << username << " doesn't exist\n" << std::endl;
			res.set_content("\n\n\n", "text/plain");
		}
	}

	// std::cout << "Table Contents: " << std::endl;
	// query(db);
	
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
	std::cout << file.c_str() << std::endl;
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	string uid = string_list[0];
	string league_name = string_list[1];
	string group_stage = string_list[2];
	string round_robin = string_list[3];
	string qualifiers = string_list[4];
	string no_of_groups = string_list[5];
	string no_of_teams = string_list[6];

	stringstream ss;
	ss << "INSERT INTO LEAGUE(UID,LNAME,GROUPSTAGE,ROUNDROBIN,QUALIFIERS,NUMBEROFGROUPS,NUMBEROFTEAMS) VALUES"
	<< "("
	<< "'" << uid << "',"
	<< "'" << league_name << "',"
	<< "'" << group_stage << "',"
	<< "'" << round_robin << "',"
	<< "'" << qualifiers << "',"
	<< "'" << no_of_groups << "',"
	<< "'" << no_of_teams << "'"
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
		exit = sqlite3_exec(db, sqlQuery.c_str(), maxLIDCallback, 0, &errMsg);
		if(exit!=SQLITE_OK){
			cerr << "Error retrieving max league data" << std::endl;
			cerr << errMsg << std::endl;
			sqlite3_free(errMsg);
		}
		else{
			if(QR1.result.empty()){
				std::cout << "wtf" << endl;
			}
			stringstream content;
			for(string &c : QR1.result){
				std::cout << "MAX ID: " << c << std::endl;
				content << c;
				content << "\n";
			}
			res.set_content(content.str(), "text/plain");
		}
	}

	std::cout << "Table Contents: " << std::endl;
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
	std::cout << file.c_str() << std::endl;
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	stringstream ss;
	int LID = 1;
	ss << "INSERT INTO DATA(USERNAME,EMAIL,PASSWORD) VALUES"
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

	std::cout << "Table Contents: " << std::endl;

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
	std::cout << file.c_str() << std::endl;
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

	std::cout << "Table Contents: " << std::endl;
	queryTeam(db);
	queryLeague(db);
	
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
	std::cout << file.c_str() << std::endl;
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
		std::exit(1);
	}
	else{
		std::cout << "Database opened successfully" << std::endl;
	}

	stringstream ss;
	ss << "SELECT TID,UID,LID,TNAME,TGROUP,POSITION,MP,WIN,LOSS,DRAW,GF,GA,GD,POINTS FROM TEAM WHERE UID"
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
		// std::cout << QR1.result[1] << std::endl;
		stringstream content;
		for(string &c : QR1.result){
			cout << c << endl;
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
			std::cout << "The user_id: " << user_id << " has teams\n" << std::endl;
			res.set_content(content.str(), "text/plain");
		}
		else{
			std::cout << "The user id: " + user_id + " doesn't have teams\n" << std::endl;
			res.set_content("\n\n\n", "text/plain");
		}
	}

	// std::cout << "Table Contents: " << std::endl;
	// query(db);
	
	sqlite3_close(db);
}

void queryDatabaseLeague(string cli_req, string file, Response &res)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	string league_id = cli_req;

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
	ss << "SELECT LID,UID,LNAME,GROUPSTAGE,ROUNDROBIN,QUALIFIERS,NUMBEROFGROUPS,NUMBEROFTEAMS FROM LEAGUE WHERE LID"
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
		// std::cout << QR1.result[1] << std::endl;
		stringstream content;
		for(string &c : QR1.result){
			cout << c << endl;
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
			std::cout << "The user_id: " << league_id << " exists\n" << std::endl;
			res.set_content(content.str(), "text/plain");
		}
		else{
			std::cout << "The user id: " + league_id + " exists\n" << std::endl;
			res.set_content("\n\n\n", "text/plain");
		}
	}

	sqlite3_close(db);
}

// void queryDatabaseLeagueID(string cli_req, string file, Response &res)
// {
// 	sqlite3 *db;
// 	int exit = 0;
// 	char *errMsg;

// 	stringstream stream;
// 	string token;

// 	getline(stream, token, '\n');
// 	string user_id = cli_req;
// 	getline(stream, token, '\n');
// 	string league_name = cli_req;

// 	exit = sqlite3_open(file.c_str(), &db);
// 	std::cout << file.c_str() << std::endl;
// 	if(exit){
// 		cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
// 		std::exit(1);
// 	}
// 	else{
// 		std::cout << "Database opened successfully" << std::endl;
// 	}

// 	stringstream ss;
// 	ss << "SELECT LID FROM LEAGUE WHERE UID"
// 	<< "="
// 	<< "'" + user_id + "'"
// 	<< " AND LNAME"
// 	<< "="
// 	<< "'" + league_name + "'";

// 	QR1.result.clear();
	
// 	string sqlQuery = ss.str();
// 	exit = sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg);
// 	if(exit!=SQLITE_OK){
// 		cerr << "Error Querying Data" << std::endl;
// 		cerr << errMsg << std::endl;
// 		sqlite3_free(errMsg);
// 	}
// 	else{
// 		std::cout << "Data Queried successfully" << std::endl;
// 		// std::cout << QR1.result[1] << std::endl;
// 		stringstream content;
// 		for(string &c : QR1.result){
// 			cout << c << endl;
// 			content << c;
// 			content << "\n";
// 		}
		
// 		string line;
// 		bool leagueExists = false;
// 		getline(content, line, '\n');
// 		if(strcmp(line.c_str(), "") != 0){
// 			leagueExists = true;
// 		}
// 		if(leagueExists){
// 			std::cout << "The user_id: " << user_id << " has leagues\n" << std::endl;
// 			res.set_content(content.str(), "text/plain");
// 		}
// 		else{
// 			std::cout << "The user id: " + user_id + " doesn't have leagues\n" << std::endl;
// 			res.set_content("\n\n\n", "text/plain");
// 		}
// 	}

// 	sqlite3_close(db);
// }

void queryDatabaseLeagueList(string cli_req, string file, Response &res)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	string user_id = cli_req;

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
		// std::cout << QR1.result[1] << std::endl;
		stringstream content;
		for(string &c : QR1.result){
			cout << c << endl;
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
			std::cout << "The user_id: " << user_id << " has leagues\n" << std::endl;
			res.set_content(content.str(), "text/plain");
		}
		else{
			std::cout << "The user id: " + user_id + " doesn't have leagues\n" << std::endl;
			res.set_content("\n\n\n", "text/plain");
		}
	}

	// std::cout << "Table Contents: " << std::endl;
	// query(db);
	
	sqlite3_close(db);
}
