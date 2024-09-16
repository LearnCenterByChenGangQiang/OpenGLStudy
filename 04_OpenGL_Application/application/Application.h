#pragma once 

#include <iostream>

/*
单例类:全局只有一个实例
 */

#define app Application::getInstance()

class GLFWwindow;

class Application
{
public:
    ~Application();
    static Application* getInstance();

    bool init(const int& width=800, const int& height=600, const char* title="Window");
    bool update();
    void destroy();

    uint32_t getWidth() const {return mWidth;};
    uint32_t getHeight() const {return mHeight;};

private:    
    Application();
    static Application* mInstance;

    uint32_t mWidth {0};
    uint32_t mHeight {0};
    const char* mTitle {nullptr};
    GLFWwindow* mWindow {nullptr};
};
