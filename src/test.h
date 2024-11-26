#pragma once

#include "Subject.h"
#include "Wrapper/Wrapper.h"

void test() {
    Subject subj(3);

    Wrapper wrapper1(&subj, &Subject::f3);
    Wrapper wrapper2(&subj, &Subject::f3, {{"asd1", "add"},
                                           {"asd2", "add"}});
//    std::cout << "wrapper call: " << wrapper(42, "hello") << '\n';
}


