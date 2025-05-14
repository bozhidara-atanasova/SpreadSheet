#pragma once
#include "Cell.h"
#include <string>

class FormulaCell : public Cell {
    std::string expr;      // without '='
    Table* owner;          // we will need it for R..C..
public:
    FormulaCell(const std::string& e, Table* t);
    std::string text() const override;
    double      number(Table&) const override;
};
