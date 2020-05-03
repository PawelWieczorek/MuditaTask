//
// Created by pawel on 03.05.20.
//

#include "../include/ConsoleReader.h"

std::string ConsoleReader::read()
{
    std::string read_buff;
    getline(std::cin, read_buff);

    return read_buff;
}