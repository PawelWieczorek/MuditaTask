//
// Created by pawel on 02.05.20.
//

#ifndef ZADANIE_WRITEFIFO_H
#define ZADANIE_WRITEFIFO_H

#include "Common.h"
#include "Fifo.h"
#include "IWrite.h"

class FifoWriter : public Fifo, public IWrite
{
public:
    FifoWriter(std::string name);

    virtual void write(std::string s);

protected:
    virtual void open();
};

#endif //ZADANIE_WRITEFIFO_H
