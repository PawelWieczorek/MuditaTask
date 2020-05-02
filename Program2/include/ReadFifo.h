//
// Created by pawel on 02.05.20.
//

#ifndef ZADANIE_READFIFO_H
#define ZADANIE_READFIFO_H

#include "Fifo.h"
#include "IRead.h"

class ReadFifo : public Fifo, public IRead
{
public:
    ReadFifo(const std::string name);

    void open();
    std::string read();
};

#endif //ZADANIE_READFIFO_H
