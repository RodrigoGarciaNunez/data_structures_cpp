cmake_minimum_required(VERSION 3.0.0)
project(search_binary_tree)

add_executable(search_binary_tree main.cpp search_binary_tree.cpp tree_node.cpp)

target_link_libraries(search_binary_tree)