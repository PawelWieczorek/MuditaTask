//
// Created by pawel on 29.04.20.
//

#include "../include/Main.h"


int main(int argc, char *argv[])
{


//    int fd;
//
//    std::string myfifo = "./myfifo";
//
//    mkfifo(myfifo.c_str(), 0666);

//    fd = open(myfifo.c_str(), O_WRONLY);



//    std::string command = "./Program2exec " + FIFO_1to2_NAME + " " + FIFO_2to1_NAME + "&";
//
//    std::cout << command << "\n";
//
//    int status = system(command.c_str());
//    std::cout << status << "\n";
//
//
//    IWrite* iW = new FifoWriter(FIFO_1to2_NAME);
//    IRead* iR = new FifoReader(FIFO_2to1_NAME);
//
//
//    iW->write("Hello, Program2!");
//
//    std::cout << "After write\n";
//
//    std::cout << "Program2: " << iR->read() << "\n";
//
//    delete iR;
//    delete iW;

//    do
//    {
//        std::cout << "Give massage to send:\n";
//        getline(std::cin, write_buff);
////        write(, write_buff.c_str(), write_buff.size() + 1);
//    } while (write_buff != "end");

    std::string inputFile = "";

    if (argc > 1)
    {
        inputFile = std::string(argv[1]);
        std::cout << inputFile << "\n";
    }

    App a(FIFO_1to2_NAME, FIFO_2to1_NAME, Program2exec, logFile, inputFile);
    a.create();
    a.execute();



    return 0;
}