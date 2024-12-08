cmake_minimum_required(VERSION 3.29)
project(CLI_Task_Manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLI_Task_Manager main.cpp
        header.h
        taskManager.cpp
        consoleCommandManager.cpp)
