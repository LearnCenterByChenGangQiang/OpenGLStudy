#include <iostream>
#include <glad/glad.h> //必须在glfw3.h之前包含
#include <GLFW/glfw3.h>

/*
目标:
	-创建glfw窗体系统
	-加入窗体变化的事件回调
*/

// 声明且实现一个窗体变化的回调函数
void frameBufferSizeCallBack(GLFWwindow* window, int width, int height) {
	std::cout << "窗体大小变化: width=" << width << ", height=" << height << std::endl;
}

// 键盘输入的回调函数
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		std::cout << "按下了:"<< key << std::endl;
		std::cout << "scancode:" << scancode << std::endl;
		std::cout << "action:" << action << std::endl;
		std::cout << "mods:" << mods << std::endl;
	}
	// 按下esc键退出程序
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	//1.初始化glfw基本环境
	glfwInit();
	// 设置opengl主版本号和次版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// 设置opengl启用核心模式(非立即渲染模式)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//2.创建窗体对象
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGLStudy", NULL, NULL);
	if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
	// 设置当前窗体为opengl的绘制舞台
	glfwMakeContextCurrent(window);

	// 设置窗体变化的回调函数
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	// 设置键盘输入的回调函数
	glfwSetKeyCallback(window, keyCallBack);

	//3.执行窗体循环
	while (!glfwWindowShouldClose(window))
	{
		// 检查消息队列是否有需要处理的鼠标、键盘等消息
		glfwPollEvents();

	}
	
	//4.退出程序前相关清理
	glfwTerminate();

	return 0;
}