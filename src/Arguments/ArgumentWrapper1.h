#pragma once

#include <string>
#include <ostream>
#include "ArgumentBase.h"
#include "Argument.h"

class ArgumentWrapper1 {
private:
    std::string name;
    ArgumentBase *arg;
public:
    template<class T>
    ArgumentWrapper1(std::string s, T t) :
            name(std::move(s)) {
        arg = new Argument<T>(t);
        dynamic_cast<Argument<T> *>(arg)->setValue(t);
    }

    template<class T>
    T getValue() {
        return dynamic_cast<Argument<T> *>(arg)->getValue();
    }

    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    friend std::ostream &operator<<(std::ostream &os, const ArgumentWrapper1 &wrapper) {
        os << wrapper.arg;
        return os;
    }
};
