#include<iostream>
#include<sstream>
#include<sqlite3.h>

using namespace std;

static int callback(void* data, int argc, char **argv, char** azcolName){
	int i;
	for(i=0; i<argc; i++){
		cout << azcolName[i] << " = " << argv[i] << endl; 
	}
	cout << endl;
	return 0;
}

int main(int argc, const char* argvp[])
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	stringstream ss1;
	ss1 << "CREATE TABLE DATA"
		<< "(SN INT PRIMARY KEY NOT NULL,"
		<< "USERNAME TEXT NOT NULL,"
		<< "EMAIL TEXT NOT NULL,"
		<< "PASSWORD TEXT NOT NULL);";

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

	string sqlQuery = "SELECT * FROM DATA";
	sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg);

	stringstream ss2;
	ss2 << "INSERT INTO DATA VALUES"
	<< "(1,"
	<< "'Prasiddha',"
	<< "'prasiddhapokh@gmail.com',"
	<< "'12345678')";

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
	sqlite3_exec(db, sqlQuery.c_str(), callback, 0, &errMsg);
	
	sqlite3_close(db);
	return 0;

	return 0;
}
