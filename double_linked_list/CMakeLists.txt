cmake_minimum_required(VERSION 3.0.0)
project(double_linked_list)

add_executable(double_linked_list main.cpp linked_list.cpp node_list.cpp)

target_link_libraries(double_linked_list )