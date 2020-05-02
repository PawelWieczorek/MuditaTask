//
// Created by pawel on 30.04.20.
//

#include "../include/Fifo.h"

Fifo::Fifo(std::string name) : name(name)
{
    this->create();
}

Fifo::~Fifo() {
    unlink(name.c_str());
}

int Fifo::create()
{
    return mkfifo(name.c_str(), 0666);
}
