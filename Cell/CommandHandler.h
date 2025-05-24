#pragma once
#include "Table.h"
#include <string>

class CommandHandler {
    Table& table;
public:
    std::string currentFile;
    CommandHandler(Table& t);
    void execute(const std::string& line);
}; //this is for print, eidt, exit

