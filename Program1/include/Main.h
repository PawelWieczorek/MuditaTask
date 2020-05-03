//
// Created by pawel on 02.05.20.
//

#ifndef ZADANIE_MAIN_H
#define ZADANIE_MAIN_H

#include "../../Common/include/Common.h"
#include "../../Common/include/IRead.h"
#include "../../Common/include/FifoReader.h"
#include "../../Common/include/IWrite.h"
#include "../../Common/include/FifoWriter.h"
#include "../include/App.h"

#define MAX_NUM_OF_PROCESSES    20
const std::string FIFO_1to2_NAME = "./1to2fifo";
const std::string FIFO_2to1_NAME = "./2to1fifo";
const std::string Program2exec = "./Program2exec";
const std::string logFile = "./logFile.txt";

#endif //ZADANIE_MAIN_H
