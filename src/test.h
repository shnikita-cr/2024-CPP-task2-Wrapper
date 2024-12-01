#pragma once

#include "Subject.h"
#include "Wrapper/Wrapper.h"

void test() {
    Subject subj(3);
    Wrapper wrapper2(&subj, &Subject::f3, {{"asd1", 3},
                                           {"asd2", std::string("asd")}});
    std::cout << "wrapper call res: " << wrapper2() << '\n';
}


