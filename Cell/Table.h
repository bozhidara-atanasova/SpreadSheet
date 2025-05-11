#pragma once
#include <vector>
#include <string>

class Cell;

class Table {
    std::vector<std::vector<Cell*>> cells;

public:
    Table();
    Table(const Table& other);
    Table& operator=(const Table& other);
    ~Table();

    void setCell(size_t row, size_t col, Cell* newCell);
    void print() const;
    double getCellValue(size_t row, size_t col) const;
};
