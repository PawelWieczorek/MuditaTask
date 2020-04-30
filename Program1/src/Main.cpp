//
// Created by pawel on 29.04.20.
//

#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    std::string write_buff;


//    int fd;
//
//    std::string myfifo = "./myfifo";
//
//    mkfifo(myfifo.c_str(), 0666);

//    fd = open(myfifo.c_str(), O_WRONLY);

    do
    {
        std::cout << "Give massage to send:\n";
        getline(std::cin, write_buff);
//        write(, write_buff.c_str(), write_buff.size() + 1);
    } while (write_buff != "end");



    return 0;
}