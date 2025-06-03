#include "IntegerCell.h"
#include <sstream> 

IntegerCell::IntegerCell(int v) : value(v) {} 


std::string IntegerCell::getValue() const {
    return std::to_string(value);
}

Cell* IntegerCell::clone() const {
    return new IntegerCell(*this);
}
