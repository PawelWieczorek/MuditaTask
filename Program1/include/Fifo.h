//
// Created by pawel on 30.04.20.
//

#ifndef ZADANIE_FIFO_H
#define ZADANIE_FIFO_H

#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

class Fifo
{
    std::string name;

public:
    Fifo(std::string name);

    virtual ~Fifo();

    int create();
};



#endif //ZADANIE_FIFO_H
