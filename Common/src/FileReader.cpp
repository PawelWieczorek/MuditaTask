//
// Created by pawel on 03.05.20.
//

#include "../include/FileReader.h"

void FileReader::open()
{
    file_stream.open(name);
}

std::string FileReader::read()
{
    std::string read_buff;

    getline(file_stream, read_buff);

    return read_buff;
}

