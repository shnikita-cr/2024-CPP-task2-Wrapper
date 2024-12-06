cmake_minimum_required(VERSION 3.25)
project(2024_CPP_task2_Wrapper)

set(CMAKE_CXX_STANDARD 23)

add_executable(2024_CPP_task2_Wrapper
        src/main.cpp
        src/tech.h
        src/Test/test.h
        src/Engine/Engine.h
        src/Wrapper/Wrapper.h
        src/Test/Subject.h
        src/Arguments/Argument.h
        src/Arguments/ArgumentBase.h
        src/Arguments/ArgumentManager.h
        src/Arguments/ArgumentWrapper.h
        src/Engine/CommandBase.h
        src/Test/Document.h)
target_link_libraries(2024_CPP_task2_Wrapper -static)


