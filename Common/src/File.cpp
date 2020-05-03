//
// Created by pawel on 03.05.20.
//

#include "../include/File.h"

File::File(std::string name) : name(name)
{
    file_stream = std::fstream(name.c_str());
}

File::~File()
{
    std::cout << "Destruktor\n";
    file_stream.close();
}
