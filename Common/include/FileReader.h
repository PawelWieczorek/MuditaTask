//
// Created by pawel on 03.05.20.
//

#ifndef ZADANIE_FILEREADER_H
#define ZADANIE_FILEREADER_H

#include "File.h"
#include "IRead.h"

class FileReader : public File, public IRead
{
public:
    FileReader(const std::string name);
    virtual void open();
    virtual std::string read();
};


#endif //ZADANIE_FILEREADER_H
