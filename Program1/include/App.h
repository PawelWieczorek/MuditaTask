//
// Created by pawel on 02.05.20.
//

#ifndef ZADANIE_APP_H
#define ZADANIE_APP_H

class App
{
    void init();
    App();
    static App* instance;

public:
    static App * create();
    virtual ~App();
};

App* App::instance = nullptr;

#endif //ZADANIE_APP_H
