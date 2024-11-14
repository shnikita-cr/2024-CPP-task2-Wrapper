#pragma once

#include <iostream>
//#include "Engine/Engine.h"
//#include "Wrapper/Wrapper.h"

class Subject {
public:
    static void f3(int a, int b) {
        std::cout << "Subject::f3(" << a << ", " << b << ")" << std::endl;
    }
};

//void f(std::initializer_list<std::pair<std::string, int>> l) {}

template<class T>
void f(T &&a) {}

void test() {
//    Subject subj;
//
//    Wrapper wrapper(&subj, &Subject::f3, {{"arg1", 0},
//                                          {"arg2", 0}});
//    Engine engine;
//    engine.register_command(&wrapper, "command1");
//    std::cout << engine.execute("command1", {{"arg1", 4},
//                                             {"arg2", 5}});
//    f(<brace-enclosed initializer list>)'
//    28 |     f(
    f(
            {
                    {"arg1", 0},
                    {"arg2", 0}
            });
}
