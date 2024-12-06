#pragma once

#include <string>
#include <ostream>
#include <memory>
#include "ArgumentBase.h"
#include "Argument.h"

class ArgumentWrapper1 {
public:
    std::string name;
    std::unique_ptr<ArgumentBase> arg;

    template<class T>
    ArgumentWrapper1(std::string s, T t) :
            name(std::move(s)), arg(std::make_unique<Argument<T>>(std::forward<T>(t))) {}

    ArgumentWrapper1(const ArgumentWrapper1 &other)
            : name(other.name), arg(other.arg ? other.arg->clone() : nullptr) {}

    ArgumentWrapper1(ArgumentWrapper1 &&other) noexcept = default;

    friend std::ostream &operator<<(std::ostream &os, const ArgumentWrapper1 &wrapper) {
        os << wrapper.arg.get();
        return os;
    }
};
