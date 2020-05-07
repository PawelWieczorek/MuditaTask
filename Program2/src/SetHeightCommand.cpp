//
// Created by pawel on 05.05.20.
//

#include "../include/SetHeightCommand.h"

SetHeightCommand::SetHeightCommand(int H) : H(H) {}

void SetHeightCommand::execute(bitmap_image &image)
{
    unsigned int width = image.width();

    image.setwidth_height(width, this->H);

    image.set_all_channels(255, 255, 255);
}
