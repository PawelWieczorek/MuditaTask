//
// Created by pawel on 05.05.20.
//

#include "../include/RenderCommand.h"

RenderCommand::RenderCommand(const std::string &name, const std::string &extension) : name(name),
                                                                                      extension(extension) {}

void RenderCommand::execute(bitmap_image &image)
{
    image.save_image(name+ ".bmp");
}
