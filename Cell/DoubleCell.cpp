#include "DoubleCell.h"
#include <string>

DoubleCell::DoubleCell(double v) : value(v) {}

std::string DoubleCell::toString() const {
    return std::to_string(value);
}

double DoubleCell::getValue() const {
    return value;
}

Cell* DoubleCell::clone() const {
    return new DoubleCell(*this);
}
