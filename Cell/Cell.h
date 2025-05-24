#pragma once
#include <string>

class Cell {
public:
    virtual ~Cell() = default;
    virtual std::string getValue() const = 0; //returns the value of the cell like text
    virtual Cell* clone() const = 0; //creates copy of the cell
};
//define the interface for all types of cells