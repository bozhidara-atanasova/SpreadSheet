#pragma once
#include "Cell.h"

class IntegerCell : public Cell {
private:
    long long value;
public:
    IntegerCell(long long v);
    std::string text()   const override;
    double number(Table&) const override;
};
