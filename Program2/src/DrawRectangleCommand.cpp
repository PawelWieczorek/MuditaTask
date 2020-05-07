//
// Created by pawel on 05.05.20.
//

#include "../include/DrawRectangleCommand.h"

DrawRectangleCommand::DrawRectangleCommand(int X, int Y, int W, int H) : X(X), Y(Y), W(W), H(H) {}

void DrawRectangleCommand::execute(bitmap_image& image)
{
    image_drawer drawer(image);

    drawer.pen_color(0, 0, 0);
    drawer.pen_width(3);

    drawer.rectangle(X, Y, X+W, Y+H);
}
