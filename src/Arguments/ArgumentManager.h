#pragma once

#include <initializer_list>
#include <string>
#include <map>
#include "../tech.h"
#include "ArgumentWrapper1.h"
#include "ArgumentWrapper2.h"

class ArgumentManager {
private:
    using ArgMap = std::map<std::string, std::unique_ptr<ArgumentBase>>;
    ArgMap arguments;
public:
    ArgumentManager(std::initializer_list<ArgumentWrapper1> args) {
        for (auto &arg: args) {
            addArgument(arg.name, arg);
        }
    }

    template<typename T>
    void addArgument(const std::string &name, T value) {
        arguments[name] = std::make_unique<Argument<T>>(std::move(value));
    }

    template<typename T>
    T getValue(const std::string &name) const {
        auto it = arguments.find(name);
        if (it == arguments.end()) {
            throw std::runtime_error("Argument not found: " + name);
        }
        auto ptr = dynamic_cast<Argument<T> *>(it->second.get());
        if (!ptr) {
            throw std::bad_cast();
        }
        return ptr->value;
    }

    template<typename... Keys>
    auto mapToTuple(Keys &&... keys) { //fixme error
        return std::make_tuple(arguments.at(keys).template get<std::decay_t<decltype(arguments.at(
                keys).template get<typename std::remove_reference<Keys>::type>())>>()...);
    }

    // Метод для отладки: отображение всех аргументов
    void printArguments() const {
        for (const auto &[name, arg]: arguments) {
            std::cout << name << ": ";
            log(arg.get());
            std::cout << "\n";
        }
    }

//    template<typename... Args>
//    std::tuple<Args...> getValues() {
//        auto f = [&]() {
//            for (auto &arg: arguments) {
//                arg.second.get<>()
//            }
//        };
//
//        return std::tuple<Args...>();
//    }
};