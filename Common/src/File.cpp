//
// Created by pawel on 03.05.20.
//

#include "../include/File.h"

File::File(std::string name) : name(name)
{
    file_stream = std::fstream();
}

File::~File()
{
    file_stream.close();
}
