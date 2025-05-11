#include "IntegerCell.h"
#include <sstream> // if toString uses stringstream

IntegerCell::IntegerCell(int v) : value(v) {}

std::string IntegerCell::toString() const {
    return std::to_string(value);
}

double IntegerCell::getValue() const {
    return static_cast<double>(value);
}

Cell* IntegerCell::clone() const {
    return new IntegerCell(*this);
}
