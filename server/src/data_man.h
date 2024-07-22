#pragma once

#include "httplib.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include "sqlite3.h"
#include <string>
#include <string.h>

using namespace httplib;
using namespace std;

struct QueryResult{
	std::vector<string> result;
};

extern QueryResult QR1;

static int callback(void* data, int argc, char **argv, char** azcolName);

void queryTeam(sqlite3 *db);

void queryLeague(sqlite3 *db);

void insertDatabaseLeague(string, string);

void insertDatabaseTeam(string, string);

void insertDatabase(string, string);

void deleteDatabase(string, string);

void queryDatabase(string, string, Response&);

void queryDatabaseTeamList(string, string, Response&);

void queryDatabaseLeagueID(string cli_req, string file, Response &res);

void queryDatabaseLeagueList(string, string, Response&);