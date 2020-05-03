//
// Created by pawel on 03.05.20.
//

#ifndef ZADANIE_FILEWRITER_H
#define ZADANIE_FILEWRITER_H

#include "File.h"
#include "IWrite.h"

class FileWriter : public File, public IWrite
{
public:
    FileWriter(const std::string name);
    virtual void write(std::string);
    virtual void open();
};

#endif //ZADANIE_FILEWRITER_H
