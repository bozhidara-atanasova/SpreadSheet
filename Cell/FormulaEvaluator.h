#pragma once
#include <string>

class Table;

class FormulaEvaluator {
public:
    static double evaluate(const std::string& expr, const Table& table);
};
