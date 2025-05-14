#include "DoubleCell.h"
#include <sstream>
#include <iomanip>

DoubleCell::DoubleCell(double v) : value(v) {}

std::string DoubleCell::text() const {
    std::ostringstream os; os << std::setprecision(10) << value; return os.str();
}
double DoubleCell::number(Table&) const { return value; }
