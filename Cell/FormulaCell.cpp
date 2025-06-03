#include "FormulaCell.h"
#include "FormulaEvaluator.h"
#include <sstream>


FormulaCell::FormulaCell(const std::string& f) : formula(f) {}
void FormulaCell::setTable(const Table* t) {
    table = t;
}

std::string FormulaCell::getValue() const {
    if (!table) return "ERROR"; 

    try {
        FormulaEvaluator evaluator(*table);
        double result = evaluator.eval(formula.substr(1)); 
        std::ostringstream oss;
        oss << result;
        return oss.str();
    }
    catch (...) {
        return "ERROR";
    }
}

Cell* FormulaCell::clone() const {
    return new FormulaCell(*this);
}

