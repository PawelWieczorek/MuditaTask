//
// Created by pawel on 05.05.20.
//

#ifndef ZADANIE_SETWIDTHCOMMAND_H
#define ZADANIE_SETWIDTHCOMMAND_H

#include "ICommand.h"

class SetWidthCommand : public ICommand
{
    int W;

public:
    SetWidthCommand(int W);

    virtual void execute(bitmap_image& image);
};

#endif //ZADANIE_SETWIDTHCOMMAND_H
