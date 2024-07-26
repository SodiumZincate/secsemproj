#include "data_man.h"
#include "data_man.cpp"

QueryResult QR1;

auto form_html = R"(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Form with Button</title>
    </head>
    <body>
        <form action="/files" method="get">
            <button type="submit">View All Files</button>
        </form>
    </body>
    </html>
)";

// void uploadFile(const std::string& url, const std::string& filePath) {
//     httplib::Client cli("0.0.0.0", 8080);
//     std::ifstream file(filePath, std::ios::binary);
    
//     if (!file.is_open()) {
//         std::cerr << "Error: Could not open file " << filePath << std::endl;
//         return;
//     }

//     std::vector<char> fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
//     httplib::MultipartFormDataItems items = {
//         {"files", std::string(fileContent.begin(), fileContent.end()),
// 		std::filesystem::path(filePath).filename().string(), "application/octet-stream"}
//     };

//     auto res = cli.Post("/upload", items);

//     if (res && res->status == 200) {
//         std::cout << "File " << filePath << " uploaded successfully." << std::endl;
//     } else {
//         std::cerr << "Error: File upload failed for " << filePath << std::endl;
//     }
// }


void run_server() {
    Server svr;
    string upload_dir = "./uploads";

    if (!filesystem::exists(upload_dir)) {
        filesystem::create_directory(upload_dir);
    }

    svr.Get("/", [](const Request &req, Response &res) {
        res.set_content(form_html, "text/html");
    });

    svr.Get("/files", [upload_dir](const Request &req, Response &res) {
        string content;
        for (const auto &entry : filesystem::directory_iterator(upload_dir)) {
            if (entry.is_regular_file()) {
                content += entry.path().filename().string();
				content += "\n";
            }
        
		}
		for (const auto &entry : filesystem::directory_iterator(upload_dir + "/logos")) {
            if (entry.is_regular_file()) {
                content += entry.path().filename().string();
				content += "\n";
            }
        }
        res.set_content(content, "text/plain");
    });

    svr.Get("/icons/query", [upload_dir](const Request &req, Response &res) {
        std::string filename = req.get_param_value("file");
        std::filesystem::path file_path = upload_dir + "/logos/" + filename;
        
        if (std::filesystem::exists(file_path) && std::filesystem::is_regular_file(file_path)) {
            // Read file content
            std::ifstream file(file_path, std::ios::binary);
            if (file) {
                std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                res.set_content(content, "image/png"); // Set appropriate MIME type if known
            } else {
                res.status = 404;
                res.set_content("File not found", "text/plain");
            }
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

	svr.Post("/login/register", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;
        std::string filepath = upload_dir + "/" + "leaguedata.db";
		// queryDatabase(cli_req, filepath, res);

		insertDatabase(cli_req, filepath);
    });

	svr.Post("/login/delete", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		deleteDatabase(cli_req, filepath);
    });

	svr.Post("/league/delete", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		deleteDatabaseLeague(cli_req, filepath);
    });

	svr.Post("/login/query", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		queryDatabase(cli_req, filepath, res);
    });

	svr.Post("/team/insert", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;
		// std::vector<string> string_list;
		// std::string token;
		// while(getline(tokenStream, token, '\n')){
		// 	string_list.push_back(token);
		// }
        std::string filepath = upload_dir + "/" + "leaguedata.db";
		insertDatabaseTeam(cli_req, filepath);
    });

	svr.Post("/match/insert", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;
		// std::vector<string> string_list;
		// std::string token;
		// while(getline(tokenStream, token, '\n')){
		// 	string_list.push_back(token);
		// }
        std::string filepath = upload_dir + "/" + "leaguedata.db";
		insertDatabaseMatch(cli_req, filepath);
    });

	svr.Post("/league/insert", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;
		// std::vector<string> string_list;
		// std::string token;
		// while(getline(tokenStream, token, '\n')){
		// 	string_list.push_back(token);
		// }
        std::string filepath = upload_dir + "/" + "leaguedata.db";
		insertDatabaseLeague(cli_req, filepath, res);
    });

	svr.Post("/league/query", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		queryDatabaseLeague(cli_req, filepath, res);
    });

	svr.Post("/match/query", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		queryDatabaseMatch(cli_req, filepath, res);
    });

	svr.Post("/match/query_number", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		queryDatabaseMatchNumber(cli_req, filepath, res);
    });

	// svr.Post("/league/query_id", [upload_dir](const Request &req, Response &res) {
	// 	string cli_req = req.body;

    //     std::string filepath = upload_dir + "/" + "leaguedata.db";
	// 	queryDatabaseLeagueID(cli_req, filepath, res);
    // });

	svr.Post("/league/query_list", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		queryDatabaseLeagueList(cli_req, filepath, res);
    });

	svr.Post("/team/update", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		updateDatabaseTeam(cli_req, filepath, res);
    });

	svr.Post("/team/query", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		queryDatabaseTeam(cli_req, filepath, res);
    });

	svr.Post("/team/query_id", [upload_dir](const Request &req, Response &res) {
		string cli_req = req.body;

        std::string filepath = upload_dir + "/" + "leaguedata.db";
		queryDatabaseTeamID(cli_req, filepath, res);
    });

	svr.Post("/upload", [&](const httplib::Request &req, httplib::Response &res) {
		if(req.is_multipart_form_data()){
			for(const auto &file : req.files){

		std::cout << "Received a file upload request" << std::endl;
		std::cout << "File name: " << file.second.filename << std::endl;
		std::cout << "File size: " << file.second.content.size() << " bytes" << std::endl;

        if (file.second.content.empty()) {
            res.status = 400;
            res.set_content("No file uploaded or file is empty", "text/plain");
            return;
        }

        // Save the uploaded file
        std::string file_path = upload_dir + "/logos/" + file.second.filename;
        std::ofstream ofs(file_path, std::ios::binary);
        ofs.write(file.second.content.c_str(), file.second.content.size());
		
        if (ofs.good()) {
            std::cout << "File uploaded successfully to " << file_path << std::endl;
            res.set_content("File uploaded successfully: " + file_path, "text/plain");
        } else {
            std::cout << "File upload failed" << std::endl;
            res.status = 404;
            res.set_content("<html><body><h1>File upload failed</h1></body></html>", "text/html");
        }
			}
    }
	});

    std::cout << "Server is listening on http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);

	string stopString;
	std::cin >> stopString;
	if(strcmp(stopString.c_str(), "stop") == 0){
		svr.stop();
	}
}

int main(int argc, char* argv[]) {
	thread server_thread(run_server);

    server_thread.join();
	
    return 0;
}