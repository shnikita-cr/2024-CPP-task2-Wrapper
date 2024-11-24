#pragma once

#include <iostream>
#include <functional>
#include "Wrapper/Wrapper.h"
#include "Engine/Engine.h"

//https://stackoverflow.com/questions/16868129/how-to-store-variadic-template-arguments

class Subject {
    int i;
public:
    explicit Subject(int i) : i(i) {}

    void printMe() const {
        std::cout << "subject i=" << i << std::endl;
    }

    void f3(int a, int b) const {
        std::cout << "Subject::f3(i:=" << i << ", a:=" << a << ", b:=" << b << ")" << std::endl;
    }
};

void f(int i) {
    log("f(i)", i);
}

void test() {
    int i;
    Wrapper wrapper(&i, &f, {"3", 3});

//    Subject subj(3);
//    Wrapper wrapper(&subj, &Subject::printMe);
//
//    Engine engine;
//    engine.register_command(&wrapper, "command1");
//    std::cout << engine.execute("command1", {{"arg1", 4},
//                                             {"arg2", 5}});
//    f(<brace-enclosed initializer list>)'
}