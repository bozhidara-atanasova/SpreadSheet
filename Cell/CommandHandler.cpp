#include "CommandHandler.h"
#include "FileManager.h"
#include "CellFactory.h"
#include <iostream>
#include <sstream>

void CommandHandler::trim(std::string& s) {
    size_t p = s.find_first_not_of(" \t");
    if (p == std::string::npos) s.clear();
    else s.erase(0, p);
}

void CommandHandler::repl() {
    std::string line;
    std::cout << "Type 'help' for commands.\n";
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;

        std::stringstream ss(line);
        std::string cmd; ss >> cmd;

        if (cmd == "open") {
            ss >> file;
            try {
                table = FileManager::load(file);
                hasTable = true;
                std::cout << "Opened.\n";
            }
            catch (const std::exception& e) { std::cout << e.what() << '\n'; }
        }

        else if (cmd == "close") {
            if (hasTable) { hasTable = false; table = Table(); std::cout << "Closed.\n"; }
            else std::cout << "No file.\n";
        }

        else if (cmd == "save") {
            if (!hasTable) { std::cout << "No file.\n"; continue; }
            try { FileManager::save(file, table); std::cout << "Saved.\n"; }
            catch (const std::exception& e) { std::cout << e.what() << '\n'; }
        }

        else if (cmd == "saveas") {
            std::string path; ss >> path;
            if (!hasTable) { std::cout << "No file.\n"; continue; }
            try { FileManager::save(path, table); file = path; std::cout << "Saved as.\n"; }
            catch (const std::exception& e) { std::cout << e.what() << '\n'; }
        }

        else if (cmd == "print") {
            if (hasTable) table.print();
            else std::cout << "No file.\n";
        }

        else if (cmd == "edit") {
            if (!hasTable) { std::cout << "No file.\n"; continue; }
            size_t r, c; ss >> r >> c;
            std::string val; std::getline(ss, val); trim(val);
            try {
                table.set(r - 1, c - 1, CellFactory::make(val, &table, r - 1, c - 1));
                std::cout << "OK.\n";
            }
            catch (const std::exception& e) { std::cout << e.what() << '\n'; }
        }

        else if (cmd == "help") {
            std::cout << "open <file>\nclose\nsave\nsaveas <file>\nprint\n"
                "edit <row> <col> <value>\nhelp\nexit\n";
        }

        else if (cmd == "exit") { std::cout << "Bye.\n"; break; }

        else if (cmd.empty()) { /* празен ред */ }

        else std::cout << "Unknown command.\n";
    }
}
