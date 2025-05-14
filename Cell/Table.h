#pragma once
#include <vector>
#include "Cell.h"

class Table {
    std::vector<std::vector<Cell*>> data;
    void clear();            
public:
    Table() = default;
    size_t rows() const;
    size_t cols() const;

    Table(const Table&) = delete;
    Table& operator=(const Table&) = delete;

    Table(Table&& other) noexcept
        : data(std::move(other.data))
    {
        other.data.clear();
    }

    Table& operator=(Table&& other) noexcept
    {
        if (this != &other) {
            clear();                     
            data = std::move(other.data);
            other.data.clear();        
        }
        return *this;
    }
    Cell* at(size_t r, size_t c);
    const Cell* at(size_t r, size_t c) const;

    void set(size_t r, size_t c, Cell* p);   // takes the leading
    double getNumber(size_t r, size_t c) const;
    void   print() const;

    ~Table();
};