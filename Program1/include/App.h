//
// Created by pawel on 03.05.20.
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
#include <queue>
#include <mutex>
#include <thread>

class App
{
    IRead* input_read;
    IWrite* fifo_1to2_write;
    IRead* fifo_2to1_read;
    IWrite* logFile_write;
    std::queue<std::string> fifo_1to2_queue;
    const std::string fifo_1to2;
    const std::string fifo_2to1;
    const std::string programExec;
    const std::string logFile;
    std::mutex write_mutex;
    bool isOpen;
    bool readFromFifo;
    bool writeToFifo;

    void open_fifo_to_write(std::string fifo_to_write);
    void open_fifo_to_read(std::string fifo_to_read);
    void write_to_fifo();
    void read_from_fifo();

    void run_Program2() const;

public:
    App(std::string fifo_1to2, std::string fifo_2to1, std::string programExec, std::string logFile);
    void create();
    void execute();
    ~App();


};

#endif //ZADANIE_APP_H
