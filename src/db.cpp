#include "db.h"

using namespace std;

int updateDatabase(string clientReq, string mode, stringstream &clientRes) {
	httplib::Client cli("localhost", 8080);
	
	if (strcmp(mode.c_str(), "register") == 0){
		if (auto res = cli.Post("/login/register?=login.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "delete") == 0){
		if (auto res = cli.Post("/login/delete?=login.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "query") == 0){
		if (auto res = cli.Post("/login/query?=login.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			cout << res->body << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "insert_league") == 0){
		if (auto res = cli.Post("/league/insert?=login.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			cout << res->body << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	cli.stop();
	return 0;
}