#include<iostream>
#include"sqlite3.h"

using namespace std;

int main(int argc, const char* argvp[])
{
	sqlite3 *db;
	int exit = 0;
	exit = sqlite3_open("test.db", &db);
	if(exit){
		cerr << "Failed to open database: " << sqlite3_errmsg(db) << endl;
		return 1;
	}
	else{
		cout << "Database opened successfully" << endl;
	}
	sqlite3_close(db);
	return 0;

	return 0;
}
