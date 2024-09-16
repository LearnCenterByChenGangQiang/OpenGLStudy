#pragma once 

#include <iostream>

/*
单例类:全局只有一个实例
 */

#define app Application::getInstance()

class Application
{
public:
    ~Application();
    static Application* getInstance();

    void test()
    {
        std::cout << "application test" << std::endl;
    }
private:    
    Application();
    static Application* mInstance;
};