//
// Created by pawel on 30.04.20.
//

#ifndef ZADANIE_FIFO_H
#define ZADANIE_FIFO_H

#include "Common.h"

class Fifo
{
protected:
    std::string name;
    int create();
    virtual int open() = 0;
    int fifo_desc;

public:
    Fifo(const std::string name);
    virtual ~Fifo();


};



#endif //ZADANIE_FIFO_H
