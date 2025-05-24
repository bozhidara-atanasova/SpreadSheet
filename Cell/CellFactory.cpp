#include "CellFactory.h"
#include "IntegerCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"
#include <sstream>
#include <regex>

Cell* CellFactory::createCell(const std::string& input) {
    std::string trimmed = input;
    trimmed.erase(0, trimmed.find_first_not_of(" \t"));
    trimmed.erase(trimmed.find_last_not_of(" \t") + 1);

    if (trimmed.empty()) return nullptr;

    if (trimmed[0] == '=')
        return new FormulaCell(trimmed);

    if (trimmed.front() == '"' && trimmed.back() == '"')
        return new StringCell(trimmed.substr(1, trimmed.length() - 2));

    std::istringstream iss(trimmed);
    int i;
    if (iss >> i && iss.eof()) return new IntegerCell(i);

    iss.clear();
    iss.str(trimmed);
    double d;
    if (iss >> d && iss.eof()) return new DoubleCell(d);

    return nullptr;
}
