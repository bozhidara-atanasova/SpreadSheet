#include "IntegerCell.h"
#include <sstream> 

IntegerCell::IntegerCell(int v) : value(v) {} //constructor,uses initializing list to 
//give value to value 

std::string IntegerCell::getValue() const {
    return std::to_string(value);
}
//int -> to string
Cell* IntegerCell::clone() const {
    return new IntegerCell(*this);
}
//method for deep copy