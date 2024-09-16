cmake_minimum_required(VERSION 3.10)


project(openGL_leture)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 在项目中加一个全局的预编译宏
add_definitions(-DDEBUG)

include_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/include
)

link_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib-vc2022
)
add_subdirectory(wrapper)
add_subdirectory(application)



add_executable(openglStudy  "main.cpp" "glad.c")

target_link_libraries(openglStudy glfw3.lib wrapper app)
