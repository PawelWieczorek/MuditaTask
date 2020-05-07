//
// Created by pawel on 03.05.20.
//

#include "../include/FileReader.h"

void FileReader::open()
{
    file_stream.open(name, std::fstream::in);
}

std::string FileReader::read()
{
    std::string read_buff;

    if (!std::getline(file_stream, read_buff, '\n'))
    {
        return "";
    }

    return read_buff;
}

FileReader::FileReader(std::string name) : File(name)
{
    open();
}

