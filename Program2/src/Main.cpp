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

    return 0;
}