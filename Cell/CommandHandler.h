// CommandHandler.h
#pragma once
#include "Table.h"
#include <string>

class CommandHandler {
    Table& table;
public:
    CommandHandler(Table& t);
    void execute(const std::string& line);
};
