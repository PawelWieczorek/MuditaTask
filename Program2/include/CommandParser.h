//
// Created by pawel on 07.05.20.
//

#ifndef ZADANIE_COMMANDPARSER_H
#define ZADANIE_COMMANDPARSER_H

#include <regex>
#include "ICommand.h"
#include "SetHeightCommand.h"
#include "SetWidthCommand.h"
#include "DrawRectangleCommand.h"
#include "DrawTriangleCommand.h"
#include "RenderCommand.h"

class CommandParser
{
    const std::regex SetWidthPattern = std::regex("^SET_WIDTH\\s+([0-9]+)$");
    const std::regex SetHeightPattern = std::regex("^SET_HEIGHT\\s+([0-9]+)$");
    const std::regex DrawRectanglePattern = std::regex(
            "^DRAW_RECTANGLE\\s+([0-9]+),([0-9]+),([0-9]+),([0-9]+)$");
    const std::regex DrawTrianglePattern = std::regex
            ("^DRAW_TRIANGLE\\s+([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+)$");
    const std::regex RenderPattern = std::regex("^RENDER +([a-zA-Z\\s\\d]+)\\.(bmp|jpg|png)");

public:
    ICommand* parse(std::string command);
};

#endif //ZADANIE_COMMANDPARSER_H
