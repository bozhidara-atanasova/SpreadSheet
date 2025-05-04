#include <iostream>
#include "Cell.h"

class IntegerCell : public Cell {
    int value;

public:
    IntegerCell(int v);
    std::string toString() const override;
    double getValue() const override;
    Cell* clone() const override;
};
int main()
{
    std::cout << "Hello World!\n";
}

