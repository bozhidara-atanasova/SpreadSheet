// Table.h
#pragma once
#include "Cell.h"
#include <vector>
#include <string>

class Table {
    std::vector<std::vector<Cell*>> data;
    void clear();
    void copyFrom(const Table& other);
public:
    Table();
    Table(const Table& other);
    Table& operator=(const Table& other);
    ~Table();

    void setCell(size_t row, size_t col, Cell* cell);
    const Cell* getCell(size_t row, size_t col) const;
    void print() const;
};
