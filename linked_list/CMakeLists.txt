cmake_minimum_required(VERSION 3.0.0)
project(linked_list)

add_executable(linked_list main.cpp linked_list.cpp node_list.cpp)

target_link_libraries(linked_list)