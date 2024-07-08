#include "db.h"

using namespace std;

// Callback function is called for each row
// data = database, argc = no. of columns in a row,
// argv = array of strings where each string is the value of a column in the row
// azcolName = array of strings where each string is the name of the column
static int callback(void* data, int argc, char **argv, char** azcolName){
	int i;
	for(i=0; i<argc; i++){
		cout << azcolName[i] << " = " << argv[i] << endl; 
	}
	cout << endl;
	return 0;
}

void query(sqlite3 *db){
	char *errMsg;
	string sqlQuery = "SELECT * FROM DATA";
	if(sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg) != SQLITE_OK){
		cerr << "SQL Error: " << errMsg << endl;
		sqlite3_free(errMsg);
	}
}

int initDatabase(string username, string email, string password)
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	stringstream ss1;
	ss1 << "CREATE TABLE DATA"
		<< "("
        << "LID INTEGER PRIMARY KEY AUTOINCREMENT, "
		<< "USERNAME TEXT NOT NULL,"
		<< "EMAIL TEXT NOT NULL,"
		<< "PASSWORD TEXT NOT NULL"
		<< ")";

	std::string sqlCreate = ss1.str();
	// cout << sqlMsg << endl;

	exit = sqlite3_open("test.db", &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << endl;
		return 1;
	}
	else{
		cout << "Database opened successfully" << endl;
	}

	exit = sqlite3_exec(db, sqlCreate.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error creating table" << endl;
		cerr << errMsg << endl;
		sqlite3_free(errMsg);
	}
	else{
		cout << "Table created successfully" << endl;
	}

	cout << "Table Contents before inserting data: " << endl;
	query(db);

	stringstream ss2;
	int LID = 1;
	ss2 << "INSERT INTO DATA(USERNAME,EMAIL,PASSWORD) VALUES"
	<< "("
	<< "'" << username << "',"
	<< "'" << email << "',"
	<< "'" << password << "'"
	<< ")";

	string sqlInsert = ss2.str();
	exit = sqlite3_exec(db, sqlInsert.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error inserting data" << endl;
		cerr << errMsg << endl;
		sqlite3_free(errMsg);
	}
	else{
		cout << "Data inserted successfully" << endl;
	}

	cout << "Table Contents after inserting data: " << endl;
	query(db);

	// stringstream ss3;
	// ss3 << "DELETE FROM DATA WHERE USERNAME"
	// << "="
	// << "'" << username << "'";

	// string sqlDelete = ss3.str();
	// exit = sqlite3_exec(db, sqlDelete.c_str(), NULL, 0, &errMsg);
	// if(exit!=SQLITE_OK){
	// 	cerr << "Error deleting data" << endl;
	// 	cerr << errMsg << endl;
	// 	sqlite3_free(errMsg);
	// }
	// else{
	// 	cout << "Data deleted successfully" << endl;
	// }

	// cout << "Table Contents after deleting data: " << endl;
	// query(db);
	
	sqlite3_close(db);
	return 0;
}