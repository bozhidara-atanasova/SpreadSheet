// DoubleCell.cpp
#include "DoubleCell.h"
#include <string>
#include <sstream>
#include <iomanip>

DoubleCell::DoubleCell(double v) : value(v) {}

std::string DoubleCell::getValue() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value;
    return oss.str();
}

Cell* DoubleCell::clone() const {
    return new DoubleCell(*this);
}
