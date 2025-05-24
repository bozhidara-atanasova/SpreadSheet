#pragma once
#include "Cell.h"
#include <string>

class StringCell : public Cell {
    std::string value;
public:
    StringCell(const std::string& v); 
    std::string getValue() const override;
    Cell* clone() const override;
};
