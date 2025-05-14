#include "FormulaEvaluator.h"
#include "Table.h"
#include <cctype>
#include <sstream>

FormulaEvaluator::FormulaEvaluator(const Table& t) : tbl(t) {}

void FormulaEvaluator::skip(const std::string& s, size_t& p) {
    while (p < s.size() && isspace((unsigned char)s[p])) ++p;
}

double FormulaEvaluator::parseValue(const std::string& e, size_t& p) const {
    skip(e, p);
    if (e[p] == 'R') {                             // R<row>C<col>
        ++p; int r = 0, c = 0;
        while (p < e.size() && isdigit(e[p])) { r = r * 10 + (e[p++] - '0'); }
        ++p;                                   // 'C'
        while (p < e.size() && isdigit(e[p])) { c = c * 10 + (e[p++] - '0'); }
        return tbl.getNumber(r - 1, c - 1);
    }
    size_t st = p;
    while (p < e.size() && (isdigit(e[p]) || e[p] == '.' || e[p] == '+' || e[p] == '-')) ++p;
    return std::stod(e.substr(st, p - st));
}

double FormulaEvaluator::eval(const std::string& expr) const {
    size_t p = 0;
    double total = 0, last = 0;
    char op = '+';
    while (p <= expr.size()) {
        if (p == expr.size() || expr[p] == '+' || expr[p] == '-' ||
            expr[p] == '*' || expr[p] == '/') {
            // apply previous op
            if (p != 0) { /* need a value before delimiter */
                double val = parseValue(expr, p); // parseValue uses old p; adjust:
                // but current p already at operator; we need backup pointer
            }
        }
        ++p;
    }
    return total;
}
