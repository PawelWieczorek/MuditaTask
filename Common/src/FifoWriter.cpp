//
// Created by pawel on 02.05.20.
//

#include "../include/FifoWriter.h"

FifoWriter::FifoWriter(std::string name) : Fifo(name)
{
    this->open();
}

void FifoWriter::write(std::string s) {
    ::write(this->fifo_desc, s.c_str(), s.size() + 1);
}

void FifoWriter::open() {
    this->fifo_desc = ::open(this->name.c_str(), O_WRONLY | O_NONBLOCK);
}
