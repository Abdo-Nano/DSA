cmake_minimum_required(VERSION 3.30)
project(Graph)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graph main.cpp
        AdjacencyBasedRepr.h
        ImageAsGraph.h)
