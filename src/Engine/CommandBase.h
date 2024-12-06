#pragma once

#include "../Arguments/ArgumentManager.h"


class CommandBase {
public:
    virtual ~CommandBase() = default;

    virtual void execute(const ArgumentManager &manager) = 0;
};
