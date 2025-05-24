// FileManager.cpp
#include "FileManager.h"
#include "CellFactory.h"
#include <fstream>
#include <sstream>

bool FileManager::loadFromFile(Table& table, const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return false;

    std::string line;
    size_t row = 0;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string cellStr;
        size_t col = 0;
        while (std::getline(ss, cellStr, ',')) {
            Cell* c = CellFactory::createCell(cellStr);
            table.setCell(row, col++, c);
        }
        ++row;
    }
    return true;
}

bool FileManager::saveToFile(const Table& table, const std::string& filename) {
    // TODO: serialization logic if needed
    return false;
}
