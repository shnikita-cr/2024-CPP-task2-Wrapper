#pragma once

#include <string>
#include "../tech.h"
#include "ArgumentBase.h"

template<class T>
class Argument : public ArgumentBase {
public:
    T val;

    explicit Argument(T init) : val(std::move(init)) {}

    [[nodiscard]] std::unique_ptr<ArgumentBase> clone() const override {
        return std::make_unique<Argument<T>>(val);
    }

    void print() const override {
        log(val);
    }
};