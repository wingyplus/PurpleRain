cmake_minimum_required(VERSION 3.8)
project(PurpleRain)

include(./cmake/FindSDL2.cmake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

add_executable(purple-rain PurpleRain.cc Window.cc Background.cc)
target_link_libraries(purple-rain ${SDL2_LIBRARIES})
