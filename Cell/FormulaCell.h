#pragma once
#include "Cell.h"
#include <string>
#include "Table.h"

class FormulaCell : public Cell {
    std::string formula;
    const Table* table = nullptr;
public:
    FormulaCell(const std::string& f);
    void setTable(const Table* t); 
    std::string getValue() const override;
    Cell* clone() const override;
};
