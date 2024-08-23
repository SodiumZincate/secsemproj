#include "db.h"
#include "logic.h"

using namespace std;
namespace fs = std::filesystem;

void uploadFile(httplib::Client& cli, const std::string& filePath) {
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

void downloadIcon(std::string filename, QIcon& icon) {
    // Initialize the HTTP client
    httplib::Client cli("localhost", 8080);

    // Create the full URL for the request
    std::string url = "/icons/query?file=" + filename;
	cout << url << "::" << filename;

    // Send a GET request to the server to download the icon
    auto res = cli.Get(url.c_str());

    // Check if the request was successful
    if (res && res->status == 200) {
        QByteArray imageData(res->body.c_str(), res->body.size());
        
        // Load the image data into a QPixmap
        QPixmap pixmap;
        if (pixmap.loadFromData(imageData)) {
            // Set the QIcon with the QPixmap
			pixmap.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            icon = QIcon(pixmap);
            qDebug() << "Icon downloaded and stored successfully!";
        } else {
            qDebug() << "Failed to load the image from data.";
            icon = QIcon(); // Set to null if loading failed
        }
    } else {
        qDebug() << "Failed to download the image. Status code:" << res->status;
        icon = QIcon(); // Set to null if the request failed
    }
}

int updateDatabase(string clientReq, string mode, stringstream &clientRes) {
	httplib::Client cli("localhost", 8080);

	stringstream stream;
	stream << clientReq;
	
	if (strcmp(mode.c_str(), "upload_icon") == 0){
		std::string item = clientReq.c_str();

		if (fs::is_regular_file(item)) {
			uploadFile(cli, item);
		}
		else {
			std::cerr << "Error: Invalid path " << item << std::endl;
			return 1;
		}
	}
	if (strcmp(mode.c_str(), "register") == 0){
		if (auto res = cli.Post("/login/register?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "delete_league") == 0){
		if (auto res = cli.Post("/league/delete", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
		}
	}
	else if(strcmp(mode.c_str(), "query") == 0){
		if (auto res = cli.Post("/login/query?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "update_team") == 0){
		if (auto res = cli.Post("/team/update?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "query_team") == 0){
		if (auto res = cli.Post("/team/query?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "query_team_id") == 0){
		if (auto res = cli.Post("/team/query_id?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "query_league") == 0){
		if (auto res = cli.Post("/league/query?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "query_match") == 0){
		if (auto res = cli.Post("/match/query?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "query_match_number") == 0){
		if (auto res = cli.Post("/match/query_number?=leaguedata.db", clientReq, "text/plain")) {
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
	else if(strcmp(mode.c_str(), "insert_match") == 0){
		if (auto res = cli.Post("/match/insert?=leaguedata.db", clientReq, "text/plain")) {
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
	else if(strcmp(mode.c_str(), "update_match") == 0){
		if (auto res = cli.Post("/match/update?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "insert_team") == 0){
		if (auto res = cli.Post("/team/insert?=leaguedata.db", clientReq, "text/plain")) {
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
		if (auto res = cli.Post("/league/insert?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
			clientRes.clear();
			clientRes << res->body;
		}
		else {
			cout << "error code: " << res.error() << std::endl;
			return 1;
		}
	}
	else if(strcmp(mode.c_str(), "query_league_list") == 0){
		if (auto res = cli.Post("/league/query_list?=leaguedata.db", clientReq, "text/plain")) {
			cout << res->status << endl;
			cout << res->get_header_value("Content-Type") << endl;
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