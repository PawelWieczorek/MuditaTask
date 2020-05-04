//
// Created by pawel on 03.05.20.
//

#include "../include/FileReader.h"

void FileReader::open()
{
    file_stream.open(name, std::fstream::in);
    std::cout << std::boolalpha << "Opened file: " << file_stream.is_open() << "\n";
}

std::string FileReader::read()
{
    std::string read_buff;

    if (!std::getline(file_stream, read_buff, '\n'))
    {
        return "end";
    }

    std::cout << "Read line: " << read_buff << "\n";

    return read_buff;
}

FileReader::FileReader(std::string name) : File(name)
{
    open();
}

