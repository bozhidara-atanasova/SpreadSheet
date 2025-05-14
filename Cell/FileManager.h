#pragma once
#include <string>
#include "Table.h"

struct FileManager {
    static Table load(const std::string& path);
    static void  save(const std::string& path, const Table& t);
};
