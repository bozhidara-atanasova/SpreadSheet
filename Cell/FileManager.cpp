#include "FileManager.h"
#include "CellFactory.h"
#include <fstream>
#include <sstream>

Table FileManager::load(const std::string& path)
{
    std::ifstream in(path);
    if (!in) throw std::runtime_error("Cannot open " + path);

    Table t;
    std::string line;
    size_t r = 0;

    while (std::getline(in, line))
    {
        std::stringstream ss(line);
        std::string cellTxt;
        size_t c = 0;

        while (std::getline(ss, cellTxt, ','))
        {
            t.set(r, c, CellFactory::make(cellTxt, &t, r, c));
            ++c;
        }
        ++r;
    }
    return t;             
}

void FileManager::save(const std::string& path, const Table& t)
{
    std::ofstream out(path);
    if (!out) throw std::runtime_error("Cannot write " + path);

    for (size_t r = 0; r < t.rows(); ++r)
    {
        for (size_t c = 0; c < t.cols(); ++c)
        {
            const Cell* ce = t.at(r, c);
            if (ce) out << ce->text();
            if (c + 1 < t.cols()) out << ',';
        }
        if (r + 1 < t.rows()) out << '\n';
    }
}
