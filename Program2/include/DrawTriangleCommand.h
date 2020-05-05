//
// Created by pawel on 05.05.20.
//

#ifndef ZADANIE_DRAWTRIANGLECOMMAND_H
#define ZADANIE_DRAWTRIANGLECOMMAND_H

#include "ICommand.h"

class DrawTriangleCommand : public ICommand
{
public:
    virtual void execute(bitmap_image image);
};

#endif //ZADANIE_DRAWTRIANGLECOMMAND_H
