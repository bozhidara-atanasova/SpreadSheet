#pragma once
#include <string>

class Table;

class FileManager {
public:
    static bool load(const std::string& filename, Table& table);
    static bool save(const std::string& filename, const Table& table);
};
