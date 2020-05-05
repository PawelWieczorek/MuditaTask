//
// Created by pawel on 04.05.20.
//

#include "../include/App.h"

App::App(const std::string fifo_1to2, const std::string fifo_2to1) : fifo_1to2_name(fifo_1to2), fifo_2to1_name(fifo_2to1)
{
    fifo_2to1_write = nullptr;
    fifo_1to2_read = nullptr;

    isOpen = true;
    readingFromFifo = true;
    writingToFifo = true;

    fifo_queue = std::queue<std::string>();
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

    isOpen = false;
    while (readingFromFifo || writingToFifo) {}
}

void App::create()
{
    std::thread open_fifo_rd(&App::open_fifo_to_read, this, fifo_1to2_name);
    std::thread open_fifo_wr(&App::open_fifo_to_write, this, fifo_2to1_name);

    open_fifo_rd.detach();
    open_fifo_wr.detach();

    while (fifo_2to1_write == nullptr || fifo_1to2_read == nullptr) {}

}

void App::execute()
{
    std::thread read_fifo(&App::read_from_fifo, this);
    std::thread write_fifo(&App::write_to_fifo, this);

    read_fifo.detach();
    write_fifo.detach();

    while (readingFromFifo || writingToFifo) {}
}

void App::write_to_fifo()
{

    do {
        std::string write_buff = "";

        this->readWriteMutex.lock();

        if (!this->fifo_queue.empty())
        {
            write_buff = fifo_queue.front();
            fifo_queue.pop();
        }

        this->readWriteMutex.unlock();

        if (!write_buff.empty())
        {
            this->fifo_2to1_write->write(write_buff);

            if (write_buff == "end")
            {
                this->finish_program();
            }
        }

    } while(this->isOpen);

    this->writingToFifo = false;
}

void App::read_from_fifo()
{
    std::string read_buff = "";

    do {
        read_buff = this->fifo_1to2_read->read();

        if (!read_buff.empty())
        {
            this->readWriteMutex.lock();

            this->fifo_queue.push(read_buff);

            this->readWriteMutex.unlock();

            if (read_buff == "end")
            {
                usleep(1000);
                this->finish_program();
            }
        }

    } while(this->isOpen);

    this->readingFromFifo = false;
}

void App::finish_program()
{
    this->isOpen = false;
}