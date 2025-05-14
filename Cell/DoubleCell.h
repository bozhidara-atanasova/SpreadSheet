#pragma once
#include "Cell.h"

class DoubleCell : public Cell {
private:
    double value;
public:
    DoubleCell(double v);
    std::string text()   const override;
    double number(Table&) const override;
};
