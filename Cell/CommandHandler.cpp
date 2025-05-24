// CommandHandler.cpp
#include "CommandHandler.h"
#include "FileManager.h"
#include "CellFactory.h"
#include <sstream>
#include <iostream>

CommandHandler::CommandHandler(Table& t) : table(t) {}

void CommandHandler::execute(const std::string& line) {
    std::stringstream ss(line);
    std::string cmd;
    ss >> cmd;

    if (cmd == "open") {
        std::string file;
        ss >> file;
        if (FileManager::loadFromFile(table, file))
            std::cout << "Successfully opened " << file << "\n";
        else
            std::cout << "Failed to open " << file << "\n";
    }
    else if (cmd == "print") {
        table.print();
    }
    else if (cmd == "edit") {
        size_t row, col;
        std::string content;
        ss >> row >> col;
        std::getline(ss, content);
        Cell* c = CellFactory::createCell(content);
        table.setCell(row, col, c);
    }
    else if (cmd == "exit") {
        std::cout << "Exiting...\n";
        exit(0);
    }
    else if (cmd == "help") {
        std::cout << "The following commands are supported:\n";
        std::cout << "open <file>     - opens <file>\n";
        std::cout << "close           - closes currently opened file\n";
        std::cout << "save            - saves the currently open file\n";
        std::cout << "saveas <file>   - saves the file to the specified path\n";
        std::cout << "edit <r> <c> <value> - edit cell at row r, column c\n";
        std::cout << "print           - prints the current table\n";
        std::cout << "exit            - exits the program\n";
    }
    else {
        std::cout << "Unknown command\n";
    }
}
