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
}//this method is for loading the table as text file

bool FileManager::saveToFile(const Table& table, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) return false;

    for (size_t r = 0; r < table.getRowCount(); ++r) {
        for (size_t c = 0; c < table.getColCount(r); ++c) {
            const Cell* cell = table.getCell(r, c);
            if (cell) {
                std::string val = cell->getValue();
                if (val.find(',') != std::string::npos || val.find('"') != std::string::npos) {
                    val = "\"" + val + "\"";
                }
                out << val;
            }
            if (c < table.getRowCount() - 1)
                out << ",";
        }
        out << "\n";
    }
    return true;
}

