#pragma once

#include <initializer_list>
#include <string>
#include <map>
#include "../tech.h"
#include "ArgumentWrapper1.h"
#include "ArgumentWrapper2.h"

class ArgumentManager {
private:
    std::map<std::string, ArgumentWrapper1> args;
    typedef std::map<std::string, ArgumentWrapper1>::iterator ArgsIterator;
    typedef std::pair<std::string, ArgumentWrapper1> argPair;
public:
    ArgumentManager(std::initializer_list<ArgumentWrapper1> list) {
        for (const auto &i: list) {
            argPair p(i.getName(), i);
            args.insert(p);
        }
    }

    void print() const {
        for (const auto &l: args) {
            log("ArgumentManager print: argument name ==", l.first, " argument value == ", l.second);
        }
    }

    template<typename... Args>
    std::tuple<Args...> getValues() {
        args.


        return std::tuple<Args...>();
    }
};