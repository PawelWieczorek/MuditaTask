//
// Created by pawel on 29.04.20.
//

#include "../include/Main.h"

int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        std::cout << "Program2exec fd\n";
        std::cout << "\tfd - pipe read file descriptor\n";
        return 0;
    }

    int fd = std::stoi(argv[1]);

    char read_buff[256];

    do
    {
        read(fd, read_buff, sizeof(read_buff));
        std::cout << "Received message: " << std::string(read_buff) << "\n";
    } while (std::string(read_buff) != "end");

    return 0;
}