#pragma once

#include <string>
#include <sstream>
#include <ostream>
#include <fstream>
#include "../tech.h"

class Document {
private:
    std::string text;
    std::string spaces;
public:
    Document() {
        text = "";
    }

    explicit Document(std::string text) : text(std::move(text)) {
        spaces = " ";
    }

    void setSpaces(const std::string &_spaces) {
        spaces = _spaces;
    }

    void readFile(const std::string &fileName) {
        std::ifstream f(fileName);
        std::stringstream ss;
        ss << f.rdbuf();
        text = ss.str();
        f.close();
    }

    friend std::ostream &operator<<(std::ostream &os, const Document &document) {
        os << "text:\n" << '"' << document.text << '"';
        return os;
    }

    void replaceWords(const std::string &from, const std::string &to) {
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = text.find(from, start_pos)) != std::string::npos) {
            text.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
            //TODO to.length()+1 if dont want upper case
        }
    }

    int findPhrase(const std::string &phrase) {

    }

    void makeUpperWords() {
        for (size_t i = 0; i < text.size(); i++) {
            if (isalpha(text[i]) && (i > 0 ? !isalpha(text[i - 1]) : 1)) {
                text[i] = _toupper(text[i]);
            }
        }
    }

    void makeUpperFirstInSentence() {
        size_t start_pos = 0, dot_pos = 0;
        while ((dot_pos = text.find('.', start_pos)) != std::string::npos) {
            start_pos = makeUpperFirstInSentenceHelper(start_pos, dot_pos);
        }
        if (start_pos != text.length())
            makeUpperFirstInSentenceHelper(start_pos, text.length());
    }

    void numerateFormatSentences() {
//        size_t start_pos = 0, dot_pos = 0;
//        size_t counter = 1;
//        while ((dot_pos = text.find('.', start_pos)) != std::string::npos) {
//            std::string sentence;
//            sentence = text.substr(start_pos, dot_pos + 1);
//            std::cout << "sentence: '" << sentence << "' end" << '\n';
////            for (size_t i = start_pos; i <= dot_pos; i++) {
////                if (!isalpha(text[i])) {
////                    std::cout << "passing" << std::endl;
////                    continue;
//                }
//
//                break;
//            };
//            start_pos = dot_pos + 1;
//        }
//        if (start_pos != text.length())
//            makeUpperFirstInSentenceHelper(start_pos, text.length());
    }

private:
    size_t makeUpperFirstInSentenceHelper(size_t start_pos, size_t dot_pos) {
        std::string sentence;
        sentence = text.substr(start_pos, dot_pos + 1);
        std::cout << "sentence: '" << sentence << "' end" << '\n';
        for (size_t i = start_pos; i <= dot_pos; i++) {
            if (!isalpha(text[i])) {
                std::cout << "passing" << std::endl;
                continue;
            }
            text[i] = _toupper(text[i]);
            break;
        };
        return start_pos = dot_pos + 1;
    }


//    bool isSpace(char ch) {
//        return (std::any_of(spaces.begin(), spaces.end(), [ch](const char &x) {
//            return x == ch;
//        }));
//    }

    inline void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
    }

    inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }
};
