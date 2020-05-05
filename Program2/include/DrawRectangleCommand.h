//
// Created by pawel on 05.05.20.
//

#ifndef ZADANIE_DRAWRECTANGLECOMMAND_H
#define ZADANIE_DRAWRECTANGLECOMMAND_H

#include "ICommand.h"

class DrawRectangleCommand : public ICommand
{
public:
    virtual void execute(bitmap_image image);
};

#endif //ZADANIE_DRAWRECTANGLECOMMAND_H
