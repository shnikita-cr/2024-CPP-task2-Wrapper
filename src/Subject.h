#pragma once

#include <iostream>

class Subject {
    int i;
public:
    explicit Subject(int i) : i(i) {}

    int f3(int a, std::string b) {
        std::cout << "Subject::f3(i:=" << i << ", a:=" << a << ", b:=" << b << ")" << std::endl;
        return 5;
    }
};