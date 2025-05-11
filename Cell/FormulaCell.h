#pragma once
#include "Cell.h"
#include <string>

class Table; // forward declaration

class FormulaCell : public Cell {
    std::string formula;

public:
    FormulaCell(const std::string& f);
    std::string toString() const override;
    double getValue() const override;
    Cell* clone() const override;
};
