#pragma once

#include <utility>

#include "../Arguments/ArgumentManager.h"

template<typename T, typename Ret, typename... Args>
class Wrapper {
private:
    T *obj;

    ArgumentManager manager;

    Ret (T::*method)(Args...);

    Ret call(Args... callArgs) { return (obj->*method)(callArgs...); }


    template<typename... Keys>
    auto getValues(Keys &&... keys) { return manager.mapToTuple(keys...); }

public:

    Wrapper(T *object, Ret (T::*func)(Args...), ArgumentManager manager) :
            obj(object), method(func), manager(std::move(manager)) {}

    Wrapper(T *object, Ret (T::*func)(Args...)) : obj(object), method(func) {}

    Ret operator()(std::tuple<Args...> params) {
        auto lambda = [&](auto &&...args) {
            call(args...);
        };
        std::apply(lambda, params);
    }

    Ret operator()() {
//        std::tuple<Args...> params{3, 4};
        auto params = getValues("asd1", "asd2");

        auto lambda = [&](auto &&...args) {
            call(args...);
        };
        std::apply(lambda, params);
    }
};