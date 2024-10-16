cmake_minimum_required(VERSION 3.10)

set(project Notely)
# set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(${project} C CXX)

add_subdirectory(${CMAKE_SOURCE_DIR}/dependencies/glfw)


include_directories(${CMAKE_SOURCE_DIR}/dependencies
                    ${CMAKE_SOURCE_DIR}/include
                    ${CMAKE_SOURCE_DIR}/dependencies/imgui
                    ${CMAKE_SOURCE_DIR}/dependencies/glad
)

# Source files
file(GLOB_RECURSE SOURCES
  #  ${CMAKE_SOURCE_DIR}/test/main.cpp
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/glad/*.c
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/*.cpp
)


# Add the executable
add_executable(${project} ${SOURCES})

#target_include_directories(${project})

target_link_libraries(${project} PRIVATE glfw GL) #incase of windows use opengl3.lib and use here
#target_link_directories(${project} PRIVATE libs/lib-vc2010-64)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_PARALLEL_LEVEL 16)

