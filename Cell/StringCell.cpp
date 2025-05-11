#include "StringCell.h"
#include <sstream>

StringCell::StringCell(const std::string& v) : value(v) {}

std::string StringCell::toString() const {
    return value;
}

double StringCell::getValue() const {
    double result = 0;
    std::stringstream ss(value);
    ss >> result;
    if (ss.fail()) return 0; 
    return result;
}

Cell* StringCell::clone() const {
    return new StringCell(*this);
}
