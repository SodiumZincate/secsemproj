#pragma once

#include "httplib.h"
#include <iostream>
#include "sqlite3.h"
#include <filesystem>
#include "appUI.h"

void downloadIcon(std::string, QIcon&);

int updateDatabase(std::string, std::string, std::stringstream&);