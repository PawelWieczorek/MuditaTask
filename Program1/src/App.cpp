//
// Created by pawel on 03.05.20.
//

#include "../include/App.h"

App::App(const std::string fifo_1to2,
         const std::string fifo_2to1,
         const std::string programExec,
         const std::string logFile,
         const std::string inputFile
        )
            : fifo_1to2_name(fifo_1to2),
              fifo_2to1_name(fifo_2to1),
              programExec(programExec),
              logFile(logFile),
              inputFile(inputFile)
{
    inputRead = nullptr;
    fifo_1to2_write = nullptr;
    fifo_2to1_read = nullptr;
    logFile_write = nullptr;

    counter = 0;

    isOpen = true;
    readingFromFifo = true;
    writingToFifo = true;

    fifo_1to2_queue = std::queue<std::string>();

}

App::~App()
{
    delete inputRead;
    delete fifo_1to2_write;
    delete fifo_2to1_read;
    delete logFile_write;

    isOpen = false;
    std::string command = "pkill -f " + Program2exec;

    usleep(2000000);
    system(command.c_str());
    while (readingFromFifo || writingToFifo) {}
}

void App::create()
{
    logFile_write = new FileWriter(logFile);
    inputRead = get_input_reader();

    std::thread open_fifo_rd(&App::open_fifo_to_read, this, fifo_2to1_name);
    std::thread open_fifo_wr(&App::open_fifo_to_write, this, fifo_1to2_name);

    open_fifo_rd.detach();
    open_fifo_wr.detach();

    run_Program2();

    while(fifo_1to2_write == nullptr || fifo_2to1_read == nullptr) {}

}

void App::execute()
{
    std::thread write_to_fifo(&App::write_to_fifo, this);
    write_to_fifo.detach();

    std::thread read_from_fifo(&App::read_from_fifo, this);
    read_from_fifo.detach();

    std::string input_buff = "";

    do {
        input_buff = this->inputRead->read();

        if (input_buff.empty() && counter > 10000)
        {
            input_buff = "end";
        }

        if (!input_buff.empty()) {
            counter = 0;

            this->writeMutex.lock();

            this->fifo_1to2_queue.push(input_buff);

            this->writeMutex.unlock();
        }
        else
        {
            counter++;
        }

        usleep(100);

    } while (input_buff != "end");

    usleep(1000000);

    isOpen = false;

    while (readingFromFifo || writingToFifo) {}
}

void App::run_Program2() const {
    std::string command = Program2exec + " " + fifo_1to2_name + " " + fifo_2to1_name + "&";
    system(command.c_str());
}

void App::open_fifo_to_read(std::string fifo_to_read)
{
    this->fifo_2to1_read = new FifoReader(fifo_to_read);
}

void App::open_fifo_to_write(std::string fifo_to_write)
{
    this->fifo_1to2_write = new FifoWriter(fifo_to_write);
}

void App::write_to_fifo()
{
    do {
        std::string write_buff = "";

        this->writeMutex.lock();

        if (!this->fifo_1to2_queue.empty())
        {
            write_buff = this->fifo_1to2_queue.front();
            this->fifo_1to2_queue.pop();
        }

        this->writeMutex.unlock();

        if (!write_buff.empty())
        {
            this->fifo_1to2_write->write(write_buff);
        }

        usleep(100);

    } while(this->isOpen);

    this->writingToFifo = false;
}

void App::read_from_fifo()
{
    std::string read_buff = "";

    do {
        read_buff = this->fifo_2to1_read->read();
        if (!read_buff.empty())
        {
            this->logFile_write->write(read_buff + "\n");
            if (read_buff == "end")
            {
                this->isOpen = false;
            }
        }
        usleep(100);

    } while(this->isOpen);

    this->readingFromFifo = false;
}

IRead * App::get_input_reader()
{
    IRead* result;

    if (!inputFile.empty())
    {
        result = new FileReader(inputFile);
    }
    else
    {
        result = new ConsoleReader();
    }

    return result;
}