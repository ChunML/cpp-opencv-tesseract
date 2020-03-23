cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(CMAKE_CXX_COMPILER /usr/bin/g++-8)

project(TEXT_EXTRACTION)

find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(TESSERACT REQUIRED tesseract)
pkg_search_module(LEPTONICA REQUIRED lept)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${TESSERACT_INCLUDE_DIRS})
include_directories(${LEPTONICA_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
target_link_libraries(main ${TESSERACT_LIBRARIES})
target_link_libraries(main ${LEPTONICA_LIBRARIES})
target_link_libraries(main stdc++fs) # need this if using g++ 8
set_property(TARGET main PROPERTY CXX_STANDARD 17)