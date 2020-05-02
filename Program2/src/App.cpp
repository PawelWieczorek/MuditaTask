//
// Created by pawel on 02.05.20.
//

#include "../include/App.h"


App::App() {}

App::~App()
{
    if (App::instance != nullptr)
    {
        delete App::instance;
    }
}


App* App::create()
{
    if (App::instance == nullptr)
    {
        App::instance = new App();
    }

    return App::instance;
}