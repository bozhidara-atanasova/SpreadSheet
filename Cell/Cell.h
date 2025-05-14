#pragma once
#include <string>

class Table;

class Cell {
public:
    virtual ~Cell() {}
    virtual std::string text() const = 0;       // print / save
    virtual double      number(Table& t) const = 0; // for formulas
};
