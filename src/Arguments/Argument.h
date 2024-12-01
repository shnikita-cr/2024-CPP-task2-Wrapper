#pragma once

#include <string>
#include "../tech.h"
#include "ArgumentBase.h"

template<class T>
class Argument : public ArgumentBase {
    T val;
public:
    explicit Argument(T init) : val(std::move(init)) {}

    [[nodiscard]] std::unique_ptr<ArgumentBase> clone() const override {
        return std::make_unique<Argument<T>>(val);
    }

    T getVal() const {
        return val;
    }

    void print() const override {
        std::cout << val << std::endl;
    }
};