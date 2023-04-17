cmake_minimum_required(VERSION 3.16)

project(plogBug LANGUAGES CXX)

# add_subdirectory(plog)

# toggle this flag
add_compile_definitions(FIXCUSTOMCONTAINER)

add_executable(${PROJECT_NAME} main.cpp)


target_include_directories(${PROJECT_NAME} PRIVATE plog/include)