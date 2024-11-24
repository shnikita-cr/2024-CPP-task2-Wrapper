#pragma once

#include <functional>
#include <utility>
#include "../tech.h"

template<class T, class F, class ...Args>
class Wrapper {
private:
//    using ReturnType = std::invoke_result_t<F(Args...)>;
    using ReturnType = typename std::invoke_result_t<F(Args...)>;

    T obj;
//    std::function<ReturnType(Args...)> bf;
    std::function<ReturnType(Args...)> bcf;
public:
    Wrapper(T &&obj, F &&func, Args...args) : obj(obj) {
//        (obj->*(func))(args...);
//        bcf = std::bind(func, obj, args...);
        auto ff = std::bind(func, obj, args...);
        ff();
    }
//    operator
};