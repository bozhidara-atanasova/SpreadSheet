#pragma once
#include "Cell.h"
#include <string>

class CellFactory {
public:
    static Cell* createCell(const std::string& input);
};
//takes one argument and parses the content of the input
//and after that returns a newly created cell of some of the
//typess