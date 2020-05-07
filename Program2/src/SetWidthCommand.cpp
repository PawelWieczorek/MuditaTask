//
// Created by pawel on 05.05.20.
//

#include "../include/SetWidthCommand.h"

SetWidthCommand::SetWidthCommand(int W) : W(W) {}

void SetWidthCommand::execute(bitmap_image &image)
{
    unsigned int height = image.height();

    image.setwidth_height(this->W, height);

    image.set_all_channels(255, 255, 255);
}
