//
// Created by pawel on 05.05.20.
//

#ifndef ZADANIE_DRAWTRIANGLECOMMAND_H
#define ZADANIE_DRAWTRIANGLECOMMAND_H

#include "ICommand.h"

class DrawTriangleCommand : public ICommand
{
    int X1;
    int Y1;
    int X2;
    int Y2;
    int X3;
    int Y3;


public:
    DrawTriangleCommand(int X1, int Y1, int X2, int Y2, int X3, int Y3);

    virtual void execute(bitmap_image& image);
};

#endif //ZADANIE_DRAWTRIANGLECOMMAND_H
