//
// Created by pawel on 03.05.20.
//

#ifndef ZADANIE_CONSOLEREADER_H
#define ZADANIE_CONSOLEREADER_H

#include "Common.h"
#include "IRead.h"

class ConsoleReader : public IRead
{
    std::string read();
};

#endif //ZADANIE_CONSOLEREADER_H
