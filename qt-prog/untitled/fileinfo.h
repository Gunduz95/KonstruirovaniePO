#ifndef FILEINFO_H
#define FILEINFO_H

#include <iostream>
#include <QMessageBox>

struct FileInfo_t
{
    unsigned int numCharacters = 0;
    unsigned int numSpecialSymbols = 0;
    unsigned int numNewLines = 0;
    unsigned int numWhiteSpace = 0;
};


FileInfo_t getFileInfo(const std::string &fileName);
FileInfo_t check(std::string fileName, QWidget *parent);

FileInfo_t getStringInfo(const std::string s);

#endif // FILEINFO_H
