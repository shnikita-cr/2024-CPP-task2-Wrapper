#pragma once

#include <map>
#include "../Wrapper/Wrapper.h"

template<class T, class R, class ...Args>
class Engine {
private:
    std::map<std::string, Wrapper<T, R, Args...> *> wrappers{};
public:
    Engine() = default;

    void register_command(Wrapper<T, R, Args...> *wrapper, const std::string &name) {
        wrappers.push_back(name, wrapper);
    }

    R execute(const std::string &name, const params_t &params) {
        auto f = wrappers.find(name);
        if (f) {
            return f(params);
        }
    }
};
