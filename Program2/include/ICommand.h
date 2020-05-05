//
// Created by pawel on 05.05.20.
//

#ifndef ZADANIE_ICOMMAND_H
#define ZADANIE_ICOMMAND_H

#include "bitmap_image.h"

class ICommand
{
public:
    virtual void execute(bitmap_image image) = 0;
    virtual ~ICommand() {}
};

#endif //ZADANIE_ICOMMAND_H
