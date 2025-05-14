#include "StringCell.h"

StringCell::StringCell(const std::string& v) : value(v) {}

std::string StringCell::text() const { return '"' + value + '"'; }
double      StringCell::number(Table&) const { return 0; }
