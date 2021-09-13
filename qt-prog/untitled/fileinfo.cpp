#include "fileinfo.h"
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <exception>
#include <QMessageBox>
#include <sstream>

FileInfo_t getFileInfo(const std::string &fileName)
{
    std::ifstream fin(fileName);

    if (!fin.is_open())
    {
        throw std::invalid_argument("Invalid file!");
    }

    FileInfo_t inf;

    std::string line;
    while (getline(fin, line))
    {
        inf.numWhiteSpace += std::count_if(line.begin(), line.end(),
        [](char c) {return isspace(c); });
        inf.numSpecialSymbols += std::count_if(line.begin(), line.end(),
        [](char c) {return !isspace(c) && !isalnum(c); });
        inf.numNewLines++;
        inf.numCharacters += line.size();

    }
    if(inf.numNewLines != 0)
        inf.numNewLines--;
    return inf;
}

FileInfo_t check(std::string fileName, QWidget *parent )
{
    namespace fs = std::experimental::filesystem;

    fs::path filePath = fs::path(fileName);

    FileInfo_t file_info;

    while (true)
    {
        auto current_file_last_write_time = fs::last_write_time(filePath);

        file_info = getFileInfo(fileName);

        std::time_t cftime = decltype(current_file_last_write_time)::clock::to_time_t(current_file_last_write_time);
        std::cout << "File write time is " << std::asctime(std::localtime(&cftime)) << '\n';

        if (current_file_last_write_time == fs::last_write_time(filePath))
            break;
        else
            QMessageBox::information(parent, "Alert", "File has been modified while reading. Attempting again !!! ");
    }
    return file_info;
}

FileInfo_t getStringInfo(const std::string s)
{
    std::istringstream string(s);
    FileInfo_t inf;

    std::string line;
    while (getline(string, line))
    {
        inf.numWhiteSpace += std::count_if(line.begin(), line.end(),
        [](char c) {return isspace(c); });
        inf.numSpecialSymbols += std::count_if(line.begin(), line.end(),
        [](char c) {return !isspace(c) && !isalnum(c); });
        inf.numNewLines++;
        inf.numCharacters += line.size();

    }
    if(inf.numNewLines != 0)
        inf.numNewLines--;
    return inf;
}
