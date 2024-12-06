#pragma once

#include <string>
#include <ostream>
#include <memory>
#include "ArgumentBase.h"
#include "Argument.h"

class ArgumentWrapper {
public:
    std::string name;
    std::unique_ptr<ArgumentBase> arg;

    template<class T>
    ArgumentWrapper(std::string s, T t) :
            name(std::move(s)), arg(std::make_unique<Argument<T>>(std::forward<T>(t))) {}

    ArgumentWrapper(const ArgumentWrapper &other)
            : name(other.name), arg(other.arg ? other.arg->clone() : nullptr) {}

    ArgumentWrapper(ArgumentWrapper &&other) noexcept = default;

    friend std::ostream &operator<<(std::ostream &os, const ArgumentWrapper &wrapper) {
        os << wrapper.arg.get();
        return os;
    }
};
