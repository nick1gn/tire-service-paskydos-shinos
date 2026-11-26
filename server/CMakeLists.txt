cmake_minimum_required(VERSION 3.20)
project(tire_shop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app
    src/tier-service.cpp
    src/main.cpp
)

target_include_directories(app PRIVATE include)
