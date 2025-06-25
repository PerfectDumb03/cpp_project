#set minimum version (fetch_content available since 3.11)
cmake_minimum_required(VERSION 3.11)
#set project name
project(cpp_project VERSION 1.0.0 LANGUAGES CXX)

#set variable exeName
set(exeName "cpp_project")

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Sources
    
)
#add executable
add_executable(${exeName} ${Sources})
#include
target_include_directories(${exeName} PUBLIC "${CMAKE_SOURCE_DIR}/include/")

# Detect the operating system
if(WIN32)
    message(STATUS "Compiling on Windows")
    add_definitions(-DOS_WINDOWS)
elseif(APPLE)
    message(STATUS "Compiling on macOS")
    add_definitions(-DOS_MAC)
endif()
