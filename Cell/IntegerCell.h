#pragma once
#include "Cell.h"

class IntegerCell : public Cell {
    int value;
public:
    IntegerCell(int v); //constructor
    std::string getValue() const override; //returns text representing of a number 
    Cell* clone() const override; //deep copy
};
