//
// Created by pawel on 29.04.20.
//

#include "../include/Main.h"
#include "../include/IRead.h"
#include "../include/ReadFifo.h"

int main()
{
    std::string write_buff;


//    int fd;
//
//    std::string myfifo = "./myfifo";
//
//    mkfifo(myfifo.c_str(), 0666);

//    fd = open(myfifo.c_str(), O_WRONLY);

    IRead* iR = new ReadFifo(FIFO_1to2_NAME);

    std::cout << iR->read();

    delete iR;

//    do
//    {
//        std::cout << "Give massage to send:\n";
//        getline(std::cin, write_buff);
////        write(, write_buff.c_str(), write_buff.size() + 1);
//    } while (write_buff != "end");



    return 0;
}