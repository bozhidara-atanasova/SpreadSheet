#pragma once
#include "Cell.h"

class DoubleCell : public Cell {
    double value;

public:
    DoubleCell(double v);
    std::string toString() const override;
    double getValue() const override;
    Cell* clone() const override;
};
