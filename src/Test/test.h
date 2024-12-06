#pragma once

#include <fstream>
#include "Subject.h"
#include "../Wrapper/Wrapper.h"
#include "../Engine/Engine.h"
#include "Document.h"

void unitTest1() {
    Subject subj(3);
    Wrapper wrapper(&subj, &Subject::f3, {{"asd1", 3},
                                          {"asd2", std::string("asd")}});
    auto v1 = wrapper();
    std::cout << "wrapper call res: " << v1 << '\n';

    Engine engine;
    engine.registerCommand(&wrapper, "command1");
    engine.execute("command1", {{"asd1", 4},
                                {"asd2", std::string("das")}});
}

void unitTest2() {
    Subject subj(3);
    Wrapper wrapper(&subj, &Subject::f3, {{"asd1", 3},
                                          {"asd2", std::string("asd")}});
    auto v2 = wrapper({{"asd2", std::string("dsa")},
                       {"asd1", 5}});
    std::cout << "another wrapper call res: " << v2 << '\n';
}

void unitTest3() {
    Subject subj(3);
    Wrapper wrapper(&subj, &Subject::f3, {{"asd1", 3},
                                          {"asd2", std::string("asd")}});
    Engine engine;
    engine.registerCommand(&wrapper, "command1");
    engine.execute("command1", {{"asd1", 4},
                                {"asd2", std::string("das")}});
}

void test2() {
    Document document;
    document.readFile("../src/Test/text.txt");
    std::cout << "before: " << document << std::endl;
    auto idx = document.findPhrase("abc", "ad", " .,;");
    if (idx.has_value())
        std::cout << "idx for found phrase: " << idx.value() << std::endl;
    std::cout << "idx for found phrase: not found" << std::endl;
    std::cout << "after:" << document << std::endl;
}

void test3() {
    Document document;
    document.readFile("../src/Test/text.txt");

    Wrapper wrapperReplaceWords(&document, &Document::replaceWords, {{"1from", std::string("a")},
                                                                     {"2to",   std::string("b")}});
    Wrapper wrapperPrintText(&document, &Document::printText, {{}});

    Engine engine;
    engine.registerCommand(&wrapperReplaceWords, "replaceWords");
    engine.registerCommand(&wrapperPrintText, "printText");
    engine.execute("printText", {{}});
    engine.execute("replaceWords", {{"1from", std::string("Lorem")},
                                    {"2to",   std::string("REPLACED")}});
    engine.execute("printText", {{}});
}