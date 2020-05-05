//
// Created by pawel on 05.05.20.
//

#ifndef ZADANIE_RENDERCOMMAND_H
#define ZADANIE_RENDERCOMMAND_H

#include "ICommand.h"

class RenderCommand : public ICommand
{
public:
    virtual void execute(bitmap_image image);
};

#endif //ZADANIE_RENDERCOMMAND_H
