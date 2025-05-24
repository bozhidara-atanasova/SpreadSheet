#pragma once
#include <string>

class Cell {
public:
    virtual ~Cell() = default; //virtual destructor
    virtual std::string getValue() const = 0; //returns all as string
    virtual Cell* clone() const = 0; //because of this we can make deep copy
};
