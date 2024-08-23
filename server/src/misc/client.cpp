#include <httplib.h>
#include <iostream>
#include <sqlite3.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void uploadFile(httplib::Client& cli, const std::string& url, const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return;
    }

    std::vector<char> fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    httplib::MultipartFormDataItems items = {
        {"files", std::string(fileContent.begin(), fileContent.end()), fs::path(filePath).filename().string(), "application/octet-stream"}
    };

    auto res = cli.Post("/upload", items);

    if (res && res->status == 200) {
        std::cout << "File " << filePath << " uploaded successfully." << std::endl;
    } else {
        std::cerr << "Error: File upload failed for " << filePath << std::endl;
    }
}


int main(int argc, char *argv[]) {
	httplib::Client cli("192.168.156.109", 8080);
	
	if (strcmp(argv[1], "upload") == 0){
		std::string item = argv[2];

		if (fs::is_regular_file(item)) {
			uploadFile(cli, "http://localhost:8080/upload", item);
		}
		else {
			std::cerr << "Error: Invalid path " << item << std::endl;
			return 1;
		}
	}
	if (strcmp(argv[1], "insert") == 0){
		if (auto res = cli.Post("/login/register?=leaguedata.db", "Prasiddha\nprasiddhapokh@gmail.com\n12345678", "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "delete_league") == 0){
		if (auto res = cli.Post("/league/delete", "1", "text/plain")) {
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
			// cout << res->body << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "team") == 0){
		if (auto res = cli.Post("/team/insert", "16\n16\nWho what\nA\n1\n1\n1\n1\n0\n0\n0\n0\n0", "text/plain")) {
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
			// cout << res->body << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "query_team_id") == 0){
		if (auto res = cli.Post("/team/query_id", "", "text/plain")) {
			cout << res->status << endl;
			// cout << res->body << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "query_league_id") == 0){
		if (auto res = cli.Post("/league/query_id", "16", "text/plain")) {
			cout << res->status << endl;
			// cout << res->body << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(argv[1], "query_league_list") == 0){
		if (auto res = cli.Post("/league/query_list", "16", "text/plain")) {
			cout << res->status << endl;
			// cout << res->body << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
  return 0;
}