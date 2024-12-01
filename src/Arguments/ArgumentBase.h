#pragma once

class ArgumentBase {
public:
    virtual ~ArgumentBase() = default;

    virtual void print() const = 0;

    virtual std::unique_ptr<ArgumentBase> clone() const = 0;
};