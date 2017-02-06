cmake_minimum_required(VERSION 3.6)
project(linkedlist)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c list_node.h linked_list.c linked_list.h)
add_executable(linkedlist ${SOURCE_FILES})