//
// Created by pawel on 29.04.20.
//

#include "../include/Main.h"
#include "../include/App.h"


int main(int argc, char *argv[]) {

    if (argc < 3) {
        return -1;
    }

    const std::string param1(argv[1]);
    const std::string param2(argv[2]);

    App a(param1, param2);

    a.create();

    a.execute();

//    IRead *iR = new FifoReader(argv[1]);
//    IWrite *iW = new FifoWriter(argv[2]);
//
//    std::string read_buff = "";
//
//    do {
//        read_buff = iR->read();
//        std::cout << "Program1: " << read_buff << "\n";
//
//        iW->write("Accepted: " + read_buff + "\n");
//
//    } while (read_buff != "end");
//
//    delete iR;
//    delete iW;

    return 0;
}