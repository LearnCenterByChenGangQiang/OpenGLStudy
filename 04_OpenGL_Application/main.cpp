#include <iostream>
#include <glad/glad.h> //必须在glfw3.h之前包含
#include <GLFW/glfw3.h>
#include <string>
#include <assert.h>
#include "wrapper/checkError.h"
#include "application/Application.h"
/*
目标:将错误检查封装成一个函数

*/

// 声明且实现一个窗体变化的回调函数
void frameBufferSizeCallBack(GLFWwindow* window, int width, int height) {
	std::cout << "窗体大小变化: width=" << width << ", height=" << height << std::endl;
	glViewport(0, 0, width, height);
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
	if (!app->init(800, 600, "OpenGLStudy")) {
		return -1;
	}


	// // 设置窗体变化的回调函数
	// glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	// // 设置键盘输入的回调函数
	// glfwSetKeyCallback(window, keyCallBack);


	// 设置视口大小
	glViewport(0, 0, 800, 600);
	// 设置清空颜色
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	//3.执行窗体循环
	while (app->update())
	{
		// 执行opengl画布清理操作
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT));

		// 渲染操作

	}
	
	app->destroy();

	return 0;
}