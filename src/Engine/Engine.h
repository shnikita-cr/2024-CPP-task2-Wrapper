#pragma once

#include "../Wrapper/Wrapper.h"
#include "CommandBase.h"

class Engine {
private:
    using CommandMap = std::map<std::string, CommandBase *>;
    CommandMap commands;
public:
    Engine() = default;

    template<class T, typename Ret, typename... Args>
    void registerCommand(Wrapper<T, Ret, Args...> *command, const std::string &name) {
        commands[name] = dynamic_cast<CommandBase *>(command);
    }

    void execute(const std::string &name, const ArgumentManager &manager) {
        auto it = commands.find(name);
        if (it == commands.end()) {
            throw std::runtime_error("CommandName not found: " + name);
        }
        it->second->execute(manager);
    }
};
