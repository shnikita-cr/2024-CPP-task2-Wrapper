#pragma once

#include <functional>
#include <utility>

using params_t = std::vector<std::pair<std::string, int>>;

template<class T, class R, class ...Args>
class Wrapper {
private:
    T *obj;
    std::function<R(Args...)> *func;
    std::vector<std::pair<std::string, int>> params;
public:
    Wrapper(T *_obj,
            std::function<R(Args...)> *_func,
            params_t _params
    ) : obj(_obj), func(_func), params(std::move(_params)) {}

    R operator()(const params_t &_params) {
        return func(_params);
    }
};