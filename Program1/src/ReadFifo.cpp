//
// Created by pawel on 02.05.20.
//

#include "../include/ReadFifo.h"

ReadFifo::ReadFifo(const std::string n) : Fifo(n)
{
    this->open();
    std::cout << "Fifo opened\n";
}

void ReadFifo::open()
{
    std::cout << "Openning fifo\n";
    this->fifo_desc = ::open(this->name.c_str(), O_RDONLY);
}

std::string ReadFifo::read()
{
    char read_buff[256];

    ::read(this->fifo_desc, read_buff, sizeof(read_buff));

    return std::string(read_buff);
}