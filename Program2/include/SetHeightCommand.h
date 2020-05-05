//
// Created by pawel on 05.05.20.
//

#ifndef ZADANIE_SETHEIGHTCOMMAND_H
#define ZADANIE_SETHEIGHTCOMMAND_H

#include "ICommand.h"

class SetHeightCommand : public ICommand
{
public:
    virtual void execute(bitmap_image image);
};

#endif //ZADANIE_SETHEIGHTCOMMAND_H
