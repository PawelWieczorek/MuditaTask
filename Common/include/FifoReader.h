//
// Created by pawel on 02.05.20.
//

#ifndef ZADANIE_READFIFO_H
#define ZADANIE_READFIFO_H

#include "Fifo.h"
#include "IRead.h"

class FifoReader : public Fifo, public IRead
{
public:
    FifoReader(std::string name);

    int open();
    std::string read();
};

#endif //ZADANIE_READFIFO_H
