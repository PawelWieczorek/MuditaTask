//
// Created by pawel on 29.04.20.
//

#include "../include/Main.h"


int main(int argc, char *argv[])
{
    std::string inputFile = "";

    if (argc > 1)
    {
        inputFile = std::string(argv[1]);
    }

    App a(FIFO_1to2_NAME, FIFO_2to1_NAME, Program2exec, logFile, inputFile);

    a.create();
    a.execute();

    return 0;
}