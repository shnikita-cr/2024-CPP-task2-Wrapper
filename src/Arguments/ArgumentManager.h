#pragma once

#include <initializer_list>
#include <string>
#include <map>
#include "../tech.h"
#include "ArgumentWrapper.h"

class ArgumentManager {
private:
    std::map<std::string, ArgumentWrapper> args;
    typedef std::map<std::string, ArgumentWrapper>::iterator ArgsIterator;
    typedef std::pair<std::string, ArgumentWrapper> argPair;
public:
    ArgumentManager(std::initializer_list<ArgumentWrapper> list) {
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
};