cmake_minimum_required(VERSION 3.20)
project(ConsoleTeste)

# find_package(OpenGL)
# find_package(glfw3)

add_executable(ConsoleTeste Main.c)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(ConsoleTeste ${CURSES_LIBRARIES})

#set(CMAKE_XX_COMPILER g++)

#target_include_directories(
#	ConsoleTeste PUBLIC include
#)

#target_link_libraries(
#	ConsoleTeste PUBLIC glfw opengl 
#)

# add_executable(ConsoleTeste Main.c)
