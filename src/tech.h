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

template<class T>
void printT(T &&t) {
    std::cout << typeid(t).name() << std::endl;
}

template<typename TupleT, typename Fn>
void for_each_tuple2(TupleT &&tp, Fn &&fn) {
    std::apply
            (
                    [&fn](auto &&...args) {
                        (fn(std::forward<decltype(args)>(args)), ...);
                    }, std::forward<TupleT>(tp)
            );
}
