// Table.cpp
#include "Table.h"
#include <iostream>
#include <iomanip>

Table::Table() {}

Table::Table(const Table& other) {
    copyFrom(other);
}

Table& Table::operator=(const Table& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

Table::~Table() {
    clear();
}

void Table::clear() {
    for (auto& row : data)
        for (auto cell : row)
            delete cell;
    data.clear();
}

void Table::copyFrom(const Table& other) {
    data.resize(other.data.size());
    for (size_t i = 0; i < other.data.size(); ++i) {
        data[i].resize(other.data[i].size());
        for (size_t j = 0; j < other.data[i].size(); ++j)
            data[i][j] = other.data[i][j] ? other.data[i][j]->clone() : nullptr;
    }
}

void Table::setCell(size_t row, size_t col, Cell* cell) {
    if (row >= data.size())
        data.resize(row + 1);
    if (col >= data[row].size())
        data[row].resize(col + 1);

    delete data[row][col];
    data[row][col] = cell;
}

const Cell* Table::getCell(size_t row, size_t col) const {
    if (row < data.size() && col < data[row].size())
        return data[row][col];
    return nullptr;
}

void Table::print() const {
    for (const auto& row : data) {
        for (const auto& cell : row) {
            if (cell)
                std::cout << std::setw(10) << cell->getValue() << " | ";
            else
                std::cout << std::setw(10) << " " << " | ";
        }
        std::cout << '\n';
    }
}
