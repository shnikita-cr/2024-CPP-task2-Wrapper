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
    T getValue(const std::string &key) const {
        auto it = arguments.find(key);
        if (it == arguments.end()) {
            throw std::runtime_error("Key not found: " + key);
        }

        auto *arg = dynamic_cast<Argument<T> *>(it->second.get());
        if (!arg) {
            throw std::runtime_error("Type mismatch for key: " + key);
        }
        return arg->val;
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


    void printArguments() const {
        for (const auto &[name, arg]: arguments) {
            std::cout << name << ": ";
            log(arg.get());
            std::cout << "\n";
        }
    }

    std::vector<std::string> getNames() {
        std::vector<std::string> names;
        for (auto &&a: arguments) {
            names.push_back(a.first);
        }
        return names;
    }
};



