#include "CellFactory.h"
#include "Table.h"
#include <cstdlib>   // std::strtod, std::strtoll>

Cell* CellFactory::make(const std::string& raw,
    Table* owner,
    size_t row, size_t col)
{
    if (raw.empty())                        
        return new StringCell("");

    if (raw[0] == '=')                    
        return new FormulaCell(raw.substr(1), owner);

    if (raw.front() == '"' && raw.back() == '"') 
        return new StringCell(raw.substr(1, raw.size() - 2));

    if (raw.find('.') != std::string::npos)        
        return new DoubleCell(std::strtod(raw.c_str(), nullptr));

    return new IntegerCell(std::strtoll(raw.c_str(), nullptr, 10));
}
