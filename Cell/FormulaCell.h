#pragma once
#include "Cell.h"
#include <string>

class FormulaCell : public Cell {
    std::string formula; // example "=R1C2+R2C3"
public:
    FormulaCell(const std::string& f);
    std::string getValue() const override; // for now it returns the formula, but in the future i will make it to calculate everything
    Cell* clone() const override;
};
