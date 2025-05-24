// FormulaCell.h
#pragma once
#include "Cell.h"
#include <string>

class FormulaCell : public Cell {
    std::string formula; // напр. "=R1C2+R2C3"
public:
    FormulaCell(const std::string& f);
    std::string getValue() const override; // за сега просто връща формулата
    Cell* clone() const override;
};
