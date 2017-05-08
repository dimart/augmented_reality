cmake_minimum_required(VERSION 3.6)

include_directories(/usr/local/Cellar/opencv3/3.2.0/include)
link_directories(/usr/local/Cellar/opencv3/3.2.0/lib)

project(hw1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(hw1 ${SOURCE_FILES})

target_link_libraries (hw1 opencv_core opencv_highgui opencv_imgproc opencv_videoio)