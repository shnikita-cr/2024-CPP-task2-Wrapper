#pragma once

class Engine {
private:
public:
    Engine() = default;

    virtual ~Engine() = default;

    virtual void register_command() = 0;

    virtual void execute() = 0;
};
