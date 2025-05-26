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

    for (size_t i = 0; i < table.getRowCount(); ++i) {
        for (size_t j = 0; j < table.getColCount(i); ++j) {
            const Cell* cell = table.getCell(i, j);
            if (cell)
                out << cell->getValue();
            if (j != table.getColCount(i) - 1)
                out << ","; 
        }
        out << "\n";
    }
    return true;
}

