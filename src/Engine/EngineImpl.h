#pragma once

#include "Engine.h"


class EngineImpl: public Engine{
private:

public:

};

//
//class Engine {
//private:
////    template<class T, class F, class ...Args>
////    using ReturnType = typename std::invoke_result_t<F(Args...)>;
////    EngineImpl engineImpl{};
//    std::vector<std::any> a;
//public:
//    Engine() = default;
//
////    template<class T, class F, class ...Args>
////    void register_command(Wrapper<T, F, Args...> *wrapper, const std::string &name) {
////        log("run", name);
////        wrapper();
////    }
//
////    ReturnType execute(const std::string &name, const Args... params) {
////        auto f = wrappers.find(name);
////        if (f) {
////            return f.second(params...);
////        }
////    }
//};