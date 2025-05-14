#pragma once
#include "Cell.h"
#include <string>

class StringCell : public Cell {
private:
    std::string value;
public:
    StringCell(const std::string& v);
    std::string text()   const override;
    double      number(Table&) const override;
};
