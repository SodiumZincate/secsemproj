#include<iostream>
#include<sstream>
#include"sqlite3.h"

using namespace std;

int main(int argc, const char* argvp[])
{
	sqlite3 *db;
	int exit = 0;
	char *errMsg;

	stringstream ss;
	ss << "CREATE TABLE DATA"
		<< "(SN INT PRIMARY KEY NOT NULL,"
		<< "USERNAME TEXT NOT NULL,"
		<< "EMAIL TEXT NOT NULL,"
		<< "PASSWORD TEXT NOT NULL);";

	std::string sqlMsg = ss.str();
	// cout << sqlMsg << endl;

	exit = sqlite3_open("test.db", &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << endl;
		return 1;
	}
	else{
		cout << "Database opened successfully" << endl;
	}

	exit = sqlite3_exec(db, sqlMsg.c_str(), NULL, 0, &errMsg);
	if(exit!=SQLITE_OK){
		cerr << "Error creating table" << endl;
		sqlite3_free(errMsg);
	}
	else{
		cout << "Table created successfully" << endl;
	}

	sqlite3_close(db);
	return 0;

	return 0;
}
