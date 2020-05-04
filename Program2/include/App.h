//
// Created by pawel on 04.05.20.
//

#ifndef ZADANIE_APP_H
#define ZADANIE_APP_H

#include "../../Common/include/Common.h"
#include "../../Common/include/IRead.h"
#include "../../Common/include/IWrite.h"
#include "../../Common/include/FileWriter.h"
#include "../../Common/include/FileReader.h"
#include "../../Common/include/FifoWriter.h"
#include "../../Common/include/FifoReader.h"
#include "../../Common/include/ConsoleReader.h"
#include "Main.h"

class App
{
    IWrite* fifo_2to1_write;
    IRead* fifo_1to2_read;

    const std::string fifo_2to1;
    const std::string fifo_1to2;
    bool isOpen;
    bool readFromFifo;
    bool writeToFifo;

    void open_fifo_to_write(std::string fifo_to_write);
    void open_fifo_to_read(std::string fifo_to_read);
    void write_to_fifo();
    void read_from_fifo();

public:
    App(const std::string fifo_2to1, const std::string fifo_1to2);
    virtual ~App();
    void create();
    void execute();
};

#endif //ZADANIE_APP_H
