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
        std::ifstream f(fileName); //todo remove function
        f >> (*this);
        f.close();
    }

    friend std::istream &operator>>(std::istream &is, Document &document) {
        std::stringstream ss;
        ss << is.rdbuf();
        document.text = ss.str();
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Document &document) {
        os << "text:\n" << "'\n" << document.text << "\n'";
        return os;
    }

    void replaceWords(const std::string &from, const std::string &to) {
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = text.find(from, start_pos)) != std::string::npos) {
            text.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
            //TODO to.length()+1 if dont want case in comment
        }
    }

//    int findPhrase(const std::string &phrase) {
//
//    }

    void makeUpperWords() {
        for (size_t i = 0; i < text.size(); i++) {
            if (isalpha(text[i]) && (i > 0 ? !isalpha(text[i - 1]) : 1)) {
                text[i] = _toupper(text[i]);
            }
        }
    }

    void makeUpperFirstInSentence() {
        auto sentences = splitText(text, ".");
        std::ostringstream modifiedText;
        for (auto &sentence: sentences) {
            sentence[0] = _toupper(sentence[0]);
            modifiedText << sentence;
        }
        text = modifiedText.str();
    }

    void addNumberingNewLinesToSentences() {
        auto sentences = splitText(text, ".");
        std::ostringstream numberedText;
        for (size_t i = 0; i < sentences.size(); ++i) {
            numberedText << (i + 1) << ". " << sentences[i] << "\n";
        }
        text = numberedText.str();
    }

private:
    [[nodiscard]] static std::vector<std::string> splitText(const std::string &txt, const std::string &delims) {
        std::vector<std::string> sentences;
        std::string sentence;
        for (char c: txt) {
            sentence += c;
            if (delims.find_first_not_of(c)) {
                sentences.push_back(sentence);
                sentence.clear();
            }
        }
        if (!sentence.empty()) {
            sentences.push_back(sentence);
        }
        return sentences;
    }

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
