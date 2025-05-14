#include "IntegerCell.h"
#include <string>

IntegerCell::IntegerCell(long long v) : value(v) {}

std::string IntegerCell::text() const { return std::to_string(value); }
double      IntegerCell::number(Table&) const { return static_cast<double>(value); }
