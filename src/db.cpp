#include "db.h"

using namespace std;

int updateDatabase(string clientReq, string mode, stringstream &clientRes) {
	httplib::Client cli("localhost", 8080);
	
	sqlite3_close(db);
	return 0;
}