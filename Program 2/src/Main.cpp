//
// Created by pawel on 29.04.20.
//

#include <iostream>
#include <string>

int main()
{
    std::string input = "";

    while(true)
    {
        std::getline(std::cin, input);
        if (input == "end")
        {
            break;
        }
        std::cout << input << "\n";
    }
    return 0;
}