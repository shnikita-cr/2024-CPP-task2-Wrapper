#pragma once

#include <fstream>
#include "Subject.h"
#include "../Wrapper/Wrapper.h"
#include "../Engine/Engine.h"
#include "Document.h"

void unitTest1() {
    Subject subj(3);
    Wrapper wrapper2(&subj, &Subject::f3, {{"asd1", 3},
                                           {"asd2", std::string("asd")}});
    auto v1 = wrapper2();
    std::cout << "wrapper call res: " << v1 << '\n';
    auto v2 = wrapper2({{"asd2", std::string("dsa")},
                        {"asd1", 5}});
    std::cout << "another wrapper call res: " << v2 << '\n';
    Engine engine;
    engine.registerCommand(&wrapper2, "command1");
    engine.execute("command1", {{"asd1", 4},
                                {"asd2", std::string("das")}});
}


void test2() {
    Document document;
    document.readFile("../src/Test/text.txt");
    std::cout << document << std::endl;
//    document.replaceWords()
}