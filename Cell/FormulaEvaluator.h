#pragma once
#include <string>
#include <cctype>

class Table;

class FormulaEvaluator {
    const Table& tbl;
    static void skip(const std::string& s, size_t& p);
    double parseValue(const std::string& e, size_t& p) const;
public:
    FormulaEvaluator(const Table& t);
    double eval(const std::string& expr) const;     // + - * /  and  R<r>C<c>
};
