// IntegerCell.h
#pragma once
#include "Cell.h"

class IntegerCell : public Cell {
    int value;
public:
    IntegerCell(int v);
    std::string getValue() const override;
    Cell* clone() const override;
};
