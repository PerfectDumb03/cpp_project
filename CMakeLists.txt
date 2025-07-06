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
        include/GameHandlerOld.h
        include/GraphicalCircle.h
        include/GraphicalSquare.h
        include/Player.h
        include/Shape.h
        include/ShapeCircle.h
        include/ShapeSquare.h
        include/CatchSquares.h
        include/GameMode.h
        include/CatchBalls.h
        include/GameOverScreen.h
        include/InputHandler.h
        include/GameModeFactory.h
)

set(Sources
        src/Game.cpp
        src/GameHandlerOld.cpp
        src/GraphicalCircle.cpp
        src/GraphicalSquare.cpp
        src/main.cpp
        src/player.cpp
        src/Shape.cpp
        src/ShapeCircle.cpp
        src/ShapeSquare.cpp
        src/CatchSquares.cpp
        src/GameMode.cpp
        src/CatchBalls.cpp
        src/GameOverScreen.cpp
        src/inputHandler.cpp
        src/GameModeFactory.cpp
)

add_executable(FaceDetectionStarter "${Includes}" "${Sources}")

target_link_libraries(FaceDetectionStarter ${OpenCV_LIBS})

message(STATUS "Ensure 'haarcascade_frontalface_default.xml' is in the build/executable directory or update path in main.cpp.")
