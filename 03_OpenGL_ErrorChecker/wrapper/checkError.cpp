#include "checkError.h"
#include <glad/glad.h>
#include <cassert>
#include <iostream>
#include <string>


void checkError() {
	GLenum errorCode = glGetError();
	std::string error_str = "";
	if (errorCode != GL_NO_ERROR)
	{
		switch (errorCode)
		{
		case GL_INVALID_ENUM:
			error_str = "GL_INVALID_ENUM";
			break;
		case GL_INVALID_VALUE:
			error_str = "GL_INVALID_VALUE";
			break;
		case GL_INVALID_OPERATION:
			error_str = "GL_INVALID_OPERATION";
			break;
		case GL_OUT_OF_MEMORY:
			error_str = "GL_OUT_OF_MEMORY";
			break;
		default:
			error_str = "Unknown error";
			break;
		}
		std::cerr << "OpenGL error: " << error_str << std::endl;

		// assert会根据传入的bool值来判断程序是否出错，如果为true则程序继续执行，否则程序终止
		assert(false);
	}
}
