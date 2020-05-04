//
// Created by pawel on 04.05.20.
//

#include "../include/App.h"

App::App(std::string fifo_2to1, std::string fifo_1to2) : fifo_2to1(fifo_1to2), fifo_1to2(fifo_1to2)
{
    fifo_2to1_write = nullptr;
    fifo_1to2_read = nullptr;

    isOpen = true;
    readFromFifo = true;
    writeToFifo = true;
}

void App::open_fifo_to_read(std::string fifo_to_read)
{
    this->fifo_1to2_read = new FifoReader(fifo_to_read);
}

void App::open_fifo_to_write(std::string fifo_to_write)
{
    this->fifo_2to1_write = new FifoWriter(fifo_to_write);
}

App::~App()
{
    delete fifo_1to2_read;
    delete fifo_2to1_write;
}