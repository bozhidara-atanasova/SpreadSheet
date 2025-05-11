#include <iostream>
#include "IntegerCell.h"
#include "DoubleCell.h"
#include "StringCell.h"

int main() {
    //Creating diffrent type cells
    IntegerCell intCell(42);
    DoubleCell doubleCell(3.14);
    StringCell stringCell1("Hello");
    StringCell stringCell2("123.45"); 

    // Test toString()
    std::cout << "IntegerCell toString(): " << intCell.toString() << std::endl;
    std::cout << "DoubleCell toString(): " << doubleCell.toString() << std::endl;
    std::cout << "StringCell1 toString(): " << stringCell1.toString() << std::endl;
    std::cout << "StringCell2 toString(): " << stringCell2.toString() << std::endl;

    // Test getValue()
    std::cout << "IntegerCell getValue(): " << intCell.getValue() << std::endl;
    std::cout << "DoubleCell getValue(): " << doubleCell.getValue() << std::endl;
    std::cout << "StringCell1 getValue(): " << stringCell1.getValue() << std::endl;
    std::cout << "StringCell2 getValue(): " << stringCell2.getValue() << std::endl;

    // Test clone()
    Cell* clone = stringCell2.clone();
    std::cout << "Cloned StringCell2 toString(): " << clone->toString() << std::endl;
    delete clone; //clean the memory

    return 0;
}
