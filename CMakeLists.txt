cmake_minimum_required(VERSION 3.25)
project(2024_CPP_task2_Wrapper)

set(CMAKE_CXX_STANDARD 17)

add_executable(2024_CPP_task2_Wrapper
        src/main.cpp
        src/test.h
        src/Engine/Engine.h
        src/Wrapper/Wrapper.h
        src/Wrapper/ArgsContainer.h src/tech.h src/Engine/EngineImpl.h)
