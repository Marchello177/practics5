cmake_minimum_required(VERSION 3.10)

project(my_console_utility)

set(CMAKE_C_STANDARD 99)

add_executable(my_console_utility main.c utils.c users.c processes.c)

