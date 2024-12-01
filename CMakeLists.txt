cmake_minimum_required(VERSION 3.25)
project(2024_CPP_task2_Wrapper)

set(CMAKE_CXX_STANDARD 23)

add_executable(2024_CPP_task2_Wrapper
        src/main.cpp
        src/tech.h
        src/test.h
        src/Engine/Engine.h
        src/Engine/EngineImpl.h
        src/Wrapper/Wrapper.h
        src/Subject.h
        src/Arguments/Argument.h
        src/Arguments/ArgumentBase.h
        src/Arguments/ArgumentManager.h
        src/Arguments/ArgumentWrapper1.h src/Engine/CommandBase.h)
