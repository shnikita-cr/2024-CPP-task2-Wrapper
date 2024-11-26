#pragma once

#include "../Arguments/ArgumentManager.h"

template<typename T, typename Ret, typename... Args>
class Wrapper {
private:
    T *obj;

    Ret (T::*method)(Args...);

    Ret call(Args... callArgs) {
        return (obj->*method)(callArgs...);
    }


public:
    Wrapper(T *object, Ret (T::*func)(Args...), const ArgumentManager &manager) : obj(object), method(func) {}

    Wrapper(T *object, Ret (T::*func)(Args...)) : obj(object), method(func) {}

    Ret operator()(Args... args) {
        return call(args...);
    }
};