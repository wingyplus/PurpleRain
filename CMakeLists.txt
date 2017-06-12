cmake_minimum_required(VERSION 3.8)
project(PurpleRain)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(purple-rain PurpleRain.cc Window.cc Background.cc)
target_link_libraries(purple-rain SDL2)
