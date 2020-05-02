//
// Created by pawel on 02.05.20.
//

#ifndef ZADANIE_IWRITE_H_H
#define ZADANIE_IWRITE_H_H

class IWrite
{
public:
    virtual void write(std::string s) = 0;
    virtual ~IWrite() {}
};

#endif //ZADANIE_IWRITE_H_H
