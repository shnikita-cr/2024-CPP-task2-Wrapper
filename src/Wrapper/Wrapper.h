#pragma once

#include <utility>

#include "../Arguments/ArgumentManager.h"

template<typename T, typename Ret, typename... Args>
class Wrapper {
private:
    T *obj;

    ArgumentManager manager;

    Ret (T::*method)(Args...);

public:
    Wrapper(T *object, Ret (T::*func)(Args...), ArgumentManager manager = {}) :
            obj(object), method(func), manager(std::move(manager)) {}

    auto getValues(const std::vector<std::string> &paramNames) {
        return manager.getTuple<Args...>(paramNames);
    }

    Ret operator()() {
        auto params = getValues({"asd1", "asd2"});
        return std::apply(
                [this](auto &&... args) {
                    return (obj->*method)(std::forward<Args>(args)...);
                },
                params
        );
    }
};
