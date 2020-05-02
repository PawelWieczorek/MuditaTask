//
// Created by pawel on 02.05.20.
//

#include "../include/WriteFifo.h"

WriteFifo::WriteFifo(std::string name) : Fifo(name)
{
    this->open();
}

void WriteFifo::write(std::string s) {
    ::write(this->fifo_desc, s.c_str(), s.size() + 1);
}

void WriteFifo::open() {
    this->fifo_desc = ::open(this->name.c_str(), O_WRONLY);
}
