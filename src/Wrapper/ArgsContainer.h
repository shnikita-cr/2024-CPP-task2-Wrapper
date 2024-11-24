#pragma once

template<class ...Args>
class ArgsContainer {
public:
    ArgsContainer(Args..._args) {
        Args args = _args;
    }
};