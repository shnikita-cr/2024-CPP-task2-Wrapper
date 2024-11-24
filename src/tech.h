#pragma once

#include <iostream>

template<class Arg>
void log(const Arg &a) {
    std::cout << a << ' ';
}

template<class Arg, class ...Args>
void log(const Arg &a, const Args &...args) {
    log(a);
    log(args...);
    std::cout << std::endl;
}