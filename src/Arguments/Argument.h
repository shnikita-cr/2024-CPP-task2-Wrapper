#pragma once

#include <string>
#include "../tech.h"
#include "ArgumentBase.h"

template<class T>
class Argument : public ArgumentBase {
    T val;
public:
    explicit Argument(const T &init) : val(init) {}

    void setValue(const T &_val) {
        val = _val;
    }

    [[nodiscard]] T getValue() const {
        return val;
    }

    void hello() override {
        log("hello");
    }
};