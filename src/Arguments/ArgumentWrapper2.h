#pragma once

#include <any>
#include <utility>

class ArgumentWrapper2 {
private:
    std::string name;
    std::any var;
public:
    template<class T>
    ArgumentWrapper2(std::string name, std::any t) :name(std::move(name)), var(std::move(t)) {}

    [[nodiscard]]  std::string getName() const {
        return name;
    }
};