#pragma once
#include <string>
class Cell {
public:
    virtual std::string toString() const = 0; 
    virtual double getValue() const = 0;      
    virtual Cell* clone() const = 0;         
    virtual ~Cell() {}                      
};
