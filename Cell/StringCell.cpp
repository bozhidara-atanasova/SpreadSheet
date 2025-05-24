#include "StringCell.h"

StringCell::StringCell(const std::string& v) : value(v) {}

std::string StringCell::getValue() const {
    return value;
}

Cell* StringCell::clone() const {
    return new StringCell(*this);
}
