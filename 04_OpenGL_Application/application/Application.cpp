#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Application* Application::mInstance = nullptr;

Application* Application::getInstance()
{
    if (mInstance == nullptr)
    {
        mInstance = new Application();
    }
    return mInstance;
}

Application::Application()
{

}

Application::~Application()
{
    
}

bool Application::init(const int& width, const int& height, const char* title)
{
    mWidth = width;
    mHeight = height;
    mTitle = title;
    //1.初始化glfw基本环境
	glfwInit();
	// 设置opengl主版本号和次版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 设置opengl启用核心模式(非立即渲染模式)

    //2.创建窗体对象
	mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
	if (mWindow == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
	// 设置当前窗体为opengl的绘制舞台
	glfwMakeContextCurrent(mWindow);

    // 初始化glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return false;
	}


    return true;
}

bool Application::update()
{
    if(glfwWindowShouldClose(mWindow))
    {
        return false;
    }

    // 检查消息队列是否有需要处理的鼠标、键盘等消息
	glfwPollEvents();
    // 切换双缓冲
	glfwSwapBuffers(mWindow);
    return true;
}

void Application::destroy()
{
    // 销毁glfw
    glfwTerminate();
}