// CellFactory.h
#pragma once
#include "Cell.h"
#include <string>

class CellFactory {
public:
    static Cell* createCell(const std::string& input);
};
