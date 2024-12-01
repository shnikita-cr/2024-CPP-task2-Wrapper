#pragma once


#include "../Arguments/ArgumentManager.h"
#include "../Engine/CommandBase.h"

template<typename T, typename Ret, typename... Args>
class Wrapper : public CommandBase {
private:
    T *obj;

    ArgumentManager manager;

    Ret (T::*method)(Args...);

    Ret call(std::tuple<Args...> &params) const {
        return std::apply(
                [this](auto &&... args) {
                    return (obj->*method)(std::forward<Args>(args)...);
                },
                params
        );
    }

public:

    Wrapper(T *object, Ret (T::*func)(Args...), ArgumentManager manager = {}) :
            obj(object), method(func), manager(std::move(manager)) {}

    Ret operator()() {
        auto params = manager.getArgumentValues<Args...>();
        return call(params);
    }

    Ret operator()(const ArgumentManager &tManager) {
        auto params = tManager.getArgumentValues<Args...>();
        return call(params);
    }

    void execute(const ArgumentManager &tManager) override {
        auto params = tManager.getArgumentValues<Args...>();
        call(params);
    }
};
