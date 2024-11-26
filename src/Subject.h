#pragma once

#include <iostream>

class Subject {
    int i;
public:
    Subject(int i) : i(i) {}

    void printMe()  {
        std::cout << "subject i=" << i << std::endl;
    }

    void f3(int a, int b)  {
        std::cout << "Subject::f3(i:=" << i << ", a:=" << a << ", b:=" << b << ")" << std::endl;
    }
};