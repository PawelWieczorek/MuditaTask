//
// Created by pawel on 30.04.20.
//

#include "../include/Fifo.h"

Fifo::Fifo(std::string name) : name(name)
{
    this->create();
    std::cout << "Fifo created\n";
}

Fifo::~Fifo() {
    unlink(name.c_str());
}

int Fifo::create()
{
    std::cout << "Creating fifo\n";
    return mkfifo(name.c_str(), 0666);
}
