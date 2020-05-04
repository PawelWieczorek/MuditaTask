//
// Created by pawel on 03.05.20.
//

#include "../include/FileWriter.h"

void FileWriter::open()
{
    file_stream.open(name, std::fstream::out);
}

void FileWriter::write(std::string s)
{
    file_stream.write(s.c_str(), s.size());
}

FileWriter::FileWriter(const std::string name) : File(name)
{
    open();
}

