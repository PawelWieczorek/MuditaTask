//
// Created by pawel on 03.05.20.
//

#ifndef ZADANIE_FILE_H
#define ZADANIE_FILE_H

#include "Common.h"

class File
{
protected:
    std::string name;
    std::fstream file_stream;

public:
    File(std::string name);
    virtual ~File();
    virtual void open() = 0;
};

#endif //ZADANIE_FILE_H
