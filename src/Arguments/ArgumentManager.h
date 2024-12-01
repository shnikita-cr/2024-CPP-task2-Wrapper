#pragma once

#include <initializer_list>
#include <string>
#include <map>
#include <vector>
#include "../tech.h"
#include "ArgumentWrapper1.h"

class ArgumentManager {
private:
    using ArgMap = std::map<std::string, std::unique_ptr<ArgumentBase>>;
    ArgMap arguments;

    template<class T>
    void addArgument(const std::string &name, T value) {
        arguments[name] = std::make_unique<Argument<T>>(std::move(value));
    }

    template<class T>
    T getValue(const std::string &argumentName) const {
        auto it = arguments.find(argumentName);
        if (it == arguments.end()) {
            throw std::runtime_error("ArgumentName not found: " + argumentName);
        }

        auto *arg = dynamic_cast<Argument<T> *>(it->second.get());
        if (!arg) {
            throw std::runtime_error("Type mismatch for ArgumentName: " + argumentName);
        }
        return arg->getVal();
    }

    template<class... Args, std::size_t... I>
    std::tuple<Args...> getTupleHelper(const std::vector<std::string> &keys, std::index_sequence<I...>) const {
        return std::make_tuple(getValue<Args>(keys[I])...);
    }

public:

    ArgumentManager(std::initializer_list<ArgumentWrapper1> args) {
        for (const auto &arg: args) {
            arguments[arg.name] = arg.arg->clone();
        }
    }

    template<class... Args>
    std::tuple<Args...> getTuple(const std::vector<std::string> &keys) const {
        std::tuple<Args...> t;
        return getTupleHelper<Args...>(keys, std::index_sequence_for<Args...>{});
    }

    [[nodiscard]] std::vector<std::string> getNames() const {
        std::vector<std::string> names;
        for (auto &&a: arguments) {
            names.push_back(a.first);
        }
        return names;
    }

    template<class ...Args>
    auto getArgumentValues() const {
        return getTuple<Args...>(getNames());
    }
};



