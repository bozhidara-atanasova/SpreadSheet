// FormulaCell.cpp
#include "FormulaCell.h"

FormulaCell::FormulaCell(const std::string& f) : formula(f) {}

std::string FormulaCell::getValue() const {
    return formula; // TODO: replace with actual evaluations
}

Cell* FormulaCell::clone() const {
    return new FormulaCell(*this);
}
