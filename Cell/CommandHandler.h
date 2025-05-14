#pragma once
#include <string>
#include "Table.h"

class CommandHandler {
private:
    bool hasTable = false;   
    Table table;            
    std::string file;              
    static void trim(std::string& s);

public:
    void repl();                 
};
