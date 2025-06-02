#include "FormulaEvaluator.h"
#include "Table.h"
#include "Cell.h"
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <functional>


FormulaEvaluator::FormulaEvaluator(const Table& t) : tbl(t) {}

void FormulaEvaluator::skip(const std::string& s, size_t& p) {
    while (p < s.length() && isspace(s[p])) ++p;
}

double FormulaEvaluator::parseValue(const std::string& e, size_t& p) const {
    skip(e, p);

    if (p < e.length() && e[p] == 'R') {
        ++p;
        int row = 0, col = 0;
        while (p < e.length() && isdigit(e[p])) row = row * 10 + (e[p++] - '0');
        if (p >= e.length() || e[p] != 'C') throw std::runtime_error("Invalid reference format");
        ++p;
        while (p < e.length() && isdigit(e[p])) col = col * 10 + (e[p++] - '0');

        const Cell* cell = tbl.getCell(row - 1, col - 1); 
        if (!cell) return 0;
        try {
            return std::stod(cell->getValue());
        }
        catch (...) {
            return 0;
        }
    }

    size_t start = p;
    while (p < e.length() && (isdigit(e[p]) || e[p] == '.' || e[p] == '+' || e[p] == '-')) ++p;
    try {
        return std::stod(e.substr(start, p - start));
    }
    catch (...) {
        return 0;
    }
}

double FormulaEvaluator::eval(const std::string& expr) const {
    size_t p = 0;
    std::function<double()> parseExpr, parseTerm, parseFactor, parsePower;

    parseExpr = [&]() {
        double v = parseTerm();
        while (true) {
            skip(expr, p);
            if (p < expr.length() && expr[p] == '+') {
                ++p;
                v += parseTerm();
            }
            else if (p < expr.length() && expr[p] == '-') {
                ++p;
                v -= parseTerm();
            }
            else break;
        }
        return v;
        };

    parseTerm = [&]() {
        double v = parseFactor();
        while (true) {
            skip(expr, p);
            if (p < expr.length() && expr[p] == '*') {
                ++p;
                v *= parseFactor();
            }
            else if (p < expr.length() && expr[p] == '/') {
                ++p;
                double d = parseFactor();
                if (d == 0) throw std::runtime_error("Division by zero");
                v /= d;
            }
            else break;
        }
        return v;
        };

    parseFactor = [&]() {
        double v = parsePower();
        while (true) {
            skip(expr, p);
            if (p < expr.length() && expr[p] == '^') {
                ++p;
                v = std::pow(v, parsePower());
            }
            else break;
        }
        return v;
        };

    parsePower = [&]() {
        skip(expr, p);
        if (p < expr.length() && expr[p] == '(') {
            ++p;
            double v = parseExpr();
            if (p >= expr.length() || expr[p] != ')') throw std::runtime_error("Mismatched parentheses");
            ++p;
            return v;
        }
        else {
            return parseValue(expr, p);
        }
        };

    try {
        return parseExpr();
    }
    catch (...) {
        throw; 
    }
}
