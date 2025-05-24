#include "CommandHandler.h"
#include "Table.h"
#include <iostream>
#include <string>

int main() {
    Table table;
    CommandHandler handler(table);

    std::string line;
    std::cout << "Spreadsheet CLI\nType 'help' for commands\n";
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        handler.execute(line);
    }
    return 0;
}//
