#include <httplib.h>
#include <iostream>
#include <sqlite3.h>
#include <filesystem>

using namespace std;

int main(int argc, char *argv[]) {
	httplib::Client cli("0.0.0.0", 8080);
	
	if (strcmp(argv[1], "insert") == 0){
		if (auto res = cli.Post("/login/register?=login.db", "Prasiddha\nprasiddhapokh@gmail.com\n12345678", "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "delete") == 0){
		if (auto res = cli.Post("/login/delete", "admin\nprasiddhapokh@gmail.com\n12345678", "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "query") == 0){
		if (auto res = cli.Post("/login/query", "Prasiddha\nprasiddhapokh@gmail.com\n12345678", "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			cout << res->body << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "team") == 0){
		if (auto res = cli.Post("/team/insert", "16\n15\nArgentina\n1\n1\n1\n1\n0\n0\n0\n0\n0", "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "league") == 0){
		if (auto res = cli.Post("/league/insert", "16\nVery long name for testing\n1\n2\n1\n4\n20", "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "query_team_list") == 0){
		if (auto res = cli.Post("/team/query_list", "16\n1", "text/plain")) {
			cout << res->status << endl;
			cout << res->body << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "query_league_id") == 0){
		if (auto res = cli.Post("/league/query_id", "16", "text/plain")) {
			cout << res->status << endl;
			cout << res->body << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "query_league_list") == 0){
		if (auto res = cli.Post("/league/query_list", "16", "text/plain")) {
			cout << res->status << endl;
			cout << res->body << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
  return 0;
}