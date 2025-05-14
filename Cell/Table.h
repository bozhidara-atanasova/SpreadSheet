#pragma once
#include <vector>
#include "Cell.h"

class Table {
private:
    std::vector<std::vector<Cell*>> data;
    void clear();                       // clear the memory
public:
    Table() {}
    ~Table();                           // here we clear all
    size_t rows() const;
    size_t cols() const;

    Cell* at(size_t r, size_t c);
    const Cell* at(size_t r, size_t c) const;

    void set(size_t r, size_t c, Cell* p);   // takes the leading
    double getNumber(size_t r, size_t c) const;
    void   print() const;
};
