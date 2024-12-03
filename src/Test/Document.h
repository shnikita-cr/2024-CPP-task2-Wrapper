#pragma once

#include <string>
#include <sstream>
#include <ostream>
#include <fstream>
#include "../tech.h"

class Document {
private:
    std::string text;
public:
    Document() {
        text = "";
    }

    explicit Document(std::string text) : text(std::move(text)) {}

    void readFile(const std::string &fileName) {
        std::ifstream f(fileName);
        if (f.is_open()) {
            std::string word;
            while (!f.eof()) {
                f >> word;
                text += " " + word;
            }
            f.close();
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Document &document) {
        os << "text: " << document.text;
        return os;
    }
};
