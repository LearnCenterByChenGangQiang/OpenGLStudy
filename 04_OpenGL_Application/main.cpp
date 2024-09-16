#include <iostream>
#include <glad/glad.h> //必须在glfw3.h之前包含
#include <GLFW/glfw3.h>
#include <string>
#include <assert.h>
#include "wrapper/checkError.h"
#include "application/Application.h"

void OnResize(int width, int height)
{
	std::cout << "OnResize: " << width << " " << height << std::endl;
	GL_CALL(glViewport(0, 0, width, height));
}

void OnKeyBoard(int key, int action, int mods)
{
	std::cout << "OnKeyBoard: " << key << " " << action << " " << mods << std::endl;
	
}


int main() {
	if (!app->init(800, 600, "OpenGLStudy")) {
		return -1;
	}

	app->setResizeCallback(OnResize);
	app->setKeyBoardCallback(OnKeyBoard);

	// 设置视口大小及清空颜色
	glViewport(0, 0, 800, 600);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	while (app->update())
	{
		// 执行opengl画布清理操作
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT));

		// 渲染操作

	}
	
	app->destroy();

	return 0;
}