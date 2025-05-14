#include "Table.h"
#include "FormulaCell.h"
#include <iostream>
#include <iomanip>

void Table::clear()
{
    for (auto& row : data)
        for (Cell* c : row) delete c;
    data.clear();
}

Table::~Table() { clear(); }

size_t Table::rows() const { return data.size(); }

size_t Table::cols() const
{
    size_t maxC = 0;
    for (const auto& row : data)
        if (row.size() > maxC) maxC = row.size();
    return maxC;
}

Cell* Table::at(size_t r, size_t c)
{
    return (r < data.size() && c < data[r].size()) ? data[r][c] : nullptr;
}
const Cell* Table::at(size_t r, size_t c) const
{
    return const_cast<Table*>(this)->at(r, c);
}

void Table::set(size_t r, size_t c, Cell* p)
{
    if (r >= data.size()) data.resize(r + 1);
    if (c >= data[r].size()) data[r].resize(c + 1, nullptr);

    delete data[r][c];       
    data[r][c] = p;
}

double Table::getNumber(size_t r, size_t c) const
{
    const Cell* ce = at(r, c);
    if (!ce) return 0;
    return ce->number(const_cast<Table&>(*this)); 
}

void Table::print() const
{
    size_t C = cols();
    std::vector<size_t> w(C, 0);

    for (size_t c = 0; c < C; ++c)
        for (size_t r = 0; r < rows(); ++r)
            if (const Cell* ce = at(r, c))
                if (ce->text().size() > w[c]) w[c] = ce->text().size();

    for (size_t r = 0; r < rows(); ++r)
    {
        for (size_t c = 0; c < C; ++c)
        {
            std::cout << "| ";
            const Cell* ce = at(r, c);
            std::cout << std::left << std::setw(w[c])
                << (ce ? ce->text() : "") << ' ';
        }
        std::cout << "|\n";
    }
}
