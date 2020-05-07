//
// Created by pawel on 04.05.20.
//

#include "../include/App.h"

App::App(const std::string fifo_1to2, const std::string fifo_2to1) : fifo_1to2_name(fifo_1to2), fifo_2to1_name(fifo_2to1)
{
    fifo_2to1_write = nullptr;
    fifo_1to2_read = nullptr;

    App::isOpen = true;
    App::readingFromFifo = true;
    App::writingToFifo = true;

    writeQueue = std::queue<std::string>();
    commandQueue = std::queue<ICommand*>();
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

    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = (void (*)(int)) &App::finish_program;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    this->create_bitmap();
}

void App::execute()
{
    std::thread read_fifo(&App::read_from_fifo, this);
    std::thread write_fifo(&App::write_to_fifo, this);
    std::thread execution(&App::execute_commands, this);

    read_fifo.detach();
    write_fifo.detach();
    execution.detach();

    while (readingFromFifo || writingToFifo) {}
}

void App::write_to_fifo()
{

    do {
        std::string write_buff = "";

        this->writeMutex.lock();

        if (!this->writeQueue.empty())
        {
            write_buff = writeQueue.front();
            writeQueue.pop();
        }

        this->writeMutex.unlock();

        if (!write_buff.empty())
        {
            this->fifo_2to1_write->write(write_buff);
        }
        usleep(100);

    } while(App::isOpen);

    App::writingToFifo = false;
}

void App::read_from_fifo()
{
    std::string read_buff = "";

    do {
        read_buff = this->fifo_1to2_read->read();

        if (!read_buff.empty())
        {
            ICommand* command = parser.parse(read_buff);

            if (command != nullptr)
            {
                this->commandMutex.lock();

                this->commandQueue.push(command);

                this->commandMutex.unlock();
            }
            else
            {
                this->writeMutex.lock();

                this->writeQueue.push("Bad_command: " + read_buff);

                this->writeMutex.unlock();
            }
        }
        usleep(100);

    } while(App::isOpen);


    App::readingFromFifo = false;
}

void App::finish_program()
{
    App::isOpen = false;
}

void App::execute_commands()
{

    do
    {

        ICommand* command = nullptr;
        this->commandMutex.lock();

        if (!this->commandQueue.empty())
        {
            command = commandQueue.front();
            commandQueue.pop();
        }

        this->commandMutex.unlock();

        if (command != nullptr)
        {
            command->execute(this->image);
            delete command;
        }
        usleep(100);
    } while (App::isOpen);
}

void App::create_bitmap()
{
    this->image = bitmap_image(200, 200);
    this->image.set_all_channels(255,255,255);
}

volatile bool App::isOpen;
volatile bool App::readingFromFifo;
volatile bool App::writingToFifo;