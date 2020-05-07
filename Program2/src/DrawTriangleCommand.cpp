//
// Created by pawel on 05.05.20.
//

#include "../include/DrawTriangleCommand.h"

DrawTriangleCommand::DrawTriangleCommand(int X1, int Y1, int X2, int Y2, int X3, int Y3) : X1(X1), Y1(Y1), X2(X2),
                                                                                           Y2(Y2), X3(X3), Y3(Y3) {}

void DrawTriangleCommand::execute(bitmap_image& image)
{
    image_drawer drawer(image);

    drawer.pen_color(0, 0, 0);
    drawer.pen_width(3);

    drawer.triangle(X1, Y1, X2, Y2, X3, Y3);
}
