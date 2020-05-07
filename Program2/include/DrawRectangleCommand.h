//
// Created by pawel on 05.05.20.
//

#ifndef ZADANIE_DRAWRECTANGLECOMMAND_H
#define ZADANIE_DRAWRECTANGLECOMMAND_H

#include "ICommand.h"

class DrawRectangleCommand : public ICommand
{
    int X;
    int Y;
    int W;
    int H;

public:
    DrawRectangleCommand(int X, int Y, int W, int H);

    virtual void execute(bitmap_image& image);
};

#endif //ZADANIE_DRAWRECTANGLECOMMAND_H
