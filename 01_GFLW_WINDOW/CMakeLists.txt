cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(openGL_leture)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/include
)

link_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib-vc2022
)


# 添加可执行文件
add_executable(openglStudy  "main.cpp" "glad.c")

target_link_libraries(openglStudy glfw3.lib)
