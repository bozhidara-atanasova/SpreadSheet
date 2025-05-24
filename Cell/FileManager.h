// FileManager.h
#pragma once
#include "Table.h"
#include <string>

class FileManager {
public:
    static bool loadFromFile(Table& table, const std::string& filename);
    static bool saveToFile(const Table& table, const std::string& filename);
};
