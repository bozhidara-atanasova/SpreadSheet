#pragma once
#include <string>
#include "IntegerCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"

struct CellFactory {
    static Cell* make(const std::string& raw, Table* t,
        size_t r, size_t c);
};
