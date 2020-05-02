//
// Created by pawel on 29.04.20.
//

#include "../include/Main.h"
#include "../include/ReadFifo.h"
#include "../include/WriteFifo.h"

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        return -1;
    }

    IRead* iR = new ReadFifo(argv[1]);
    IWrite* iW = new WriteFifo(argv[2]);

    std::cout << "Program1: "<< iR->read() << "\n";

    iW->write("Hello, Program1!\n");

    delete iR;
    delete iW;

    return 0;
}