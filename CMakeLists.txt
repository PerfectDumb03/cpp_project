cmake_minimum_required(VERSION 3.11)
project(FaceDetectionStarter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

set(Sources
    src/main.cpp
    src/Game.cpp
    include/Game.h
    src/Shape.cpp
    include/Shape.h
    src/ShapeSquare.cpp
    include/ShapeSquare.h
        src/GraphicalSquare.cpp
        include/GraphicalSquare.h
        src/ShapeCircle.cpp
        include/ShapeCircle.h
        src/GraphicalCircle.cpp
        include/GraphicalCircle.h
)

add_executable(FaceDetectionStarter "${Sources}")

target_link_libraries(FaceDetectionStarter ${OpenCV_LIBS})

message(STATUS "Ensure 'haarcascade_frontalface_default.xml' is in the build/executable directory or update path in main.cpp.")
