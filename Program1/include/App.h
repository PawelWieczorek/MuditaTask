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


class App
{
    IRead* inputRead;
    IWrite* fifo_1to2_write;
    IRead* fifo_2to1_read;
    IWrite* logFile_write;
    std::queue<std::string> fifo_1to2_queue;
    const std::string fifo_1to2_name;
    const std::string fifo_2to1_name;
    const std::string programExec;
    const std::string logFile;
    const std::string inputFile;
    std::mutex writeMutex;
    bool isOpen;
    bool readingFromFifo;
    bool writingToFifo;
    unsigned counter;

    void open_fifo_to_write(std::string fifo_to_write);
    void open_fifo_to_read(std::string fifo_to_read);
    void write_to_fifo();
    void read_from_fifo();
    IRead* get_input_reader();

    void run_Program2() const;

public:
    App(
            const std::string fifo_1to2,
            const std::string fifo_2to1,
            const std::string programExec,
            const std::string logFile,
            const std::string inputFile = ""
    );
    void create();
    void execute();
    ~App();


};

#endif //ZADANIE_APP_H
