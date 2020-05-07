//
// Created by pawel on 07.05.20.
//

#include "../include/CommandParser.h"


ICommand* CommandParser::parse(std::string command)
{
    ICommand* result = nullptr;
    std::smatch matcher;

    if (std::regex_search(command, matcher, SetHeightPattern))
    {
        result = new SetHeightCommand(std::stoi(matcher[1]));
        return result;
    }

    if (std::regex_search(command, matcher, SetWidthPattern))
    {
        result = new SetWidthCommand(std::stoi(matcher[1]));
        return result;
    }

    if (std::regex_search(command, matcher, DrawTrianglePattern))
    {
        result = new DrawTriangleCommand(std::stoi(matcher[1]), std::stoi(matcher[2]), std::stoi(matcher[3]),
                                         std::stoi(matcher[4]), std::stoi(matcher[5]), std::stoi(matcher[6]));
        return result;
    }

    if (std::regex_search(command, matcher, DrawRectanglePattern))
    {
        result = new DrawRectangleCommand(std::stoi(matcher[1]), std::stoi(matcher[2]),
                                          std::stoi(matcher[3]), std::stoi(matcher[4]));
        return result;
    }

    if (std::regex_search(command, matcher, RenderPattern))
    {
        result = new RenderCommand(matcher[1], matcher[2]);
    }

    return result;
}
