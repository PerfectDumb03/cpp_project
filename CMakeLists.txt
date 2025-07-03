cmake_minimum_required(VERSION 3.11)
project(FaceDetectionStarter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

set(Includes
        include/Game.h
        include/GameMode.h
        include/GraphicalCircle.h
        include/GraphicalSquare.h
        include/InputHandler.h
        include/Player.h
        include/Shape.h
        include/ShapeCircle.h
        include/ShapeSquare.h
        include/CatchSquares.h
)

set(Sources
        src/Game.cpp
        src/GameMode.cpp
        src/gameStart.cpp
        src/GraphicalCircle.cpp
        src/GraphicalSquare.cpp
        src/inputHandler.cpp
        src/main.cpp
        src/player.cpp
        src/Shape.cpp
        src/ShapeCircle.cpp
        src/ShapeSquare.cpp
        src/CatchSquares.cpp
)

add_executable(FaceDetectionStarter "${Includes}" "${Sources}")

target_link_libraries(FaceDetectionStarter ${OpenCV_LIBS})

message(STATUS "Ensure 'haarcascade_frontalface_default.xml' is in the build/executable directory or update path in main.cpp.")
