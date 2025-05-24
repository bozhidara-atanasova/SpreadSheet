// StringCell.h
#pragma once
#include "Cell.h"
#include <string>

class StringCell : public Cell {
    std::string value;
public:
    StringCell(const std::string& v); // само декларация тук!
    std::string getValue() const override;
    Cell* clone() const override;
};
