#pragma once

#include <string>
#include <sstream>
#include <ostream>
#include <fstream>
#include <optional>
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

    void replaceWords(const std::string from, const std::string to) {
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = text.find(from, start_pos)) != std::string::npos) {
            text.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
            //TODO to.length()+1 if dont want case in comment
        }
    }

    std::optional<size_t> findPhrase(const std::string word1, const std::string word2, const std::string delims) {
        auto words = splitCleanText(text, delims);
        for (size_t i = 0; i < words.size() - 1; i++) {
            if (words[i] == word1 && words[i + 1] == word2) {
                return {i}; // возвращает индекс СЛОВА из списка слов; СЛОВО - первое слово словосочетания
            }
        }
        return std::nullopt;
    }

    void makeUpperFirstInWords() {
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

    void printText() {
        std::cout << (*this);
    }

private:
    [[nodiscard]] static std::vector<std::string>
    splitText(const std::string &txt, const std::string &delimiters) {
        std::vector<std::string> sentences;
        std::string sentence;
        for (char c: txt) {
            sentence += c;
            if (delimiters.find_first_not_of(c)) {
                if (!sentence.empty()) {
                    sentences.push_back(sentence);
                    sentence.clear();
                }
            }
        }
        if (!sentence.empty()) {
            sentences.push_back(sentence);
        }
        return sentences;
    }

    [[nodiscard]] static std::vector<std::string>
    splitCleanText(const std::string &txt, const std::string &delimiters) {
        std::vector<std::string> sentences;
        std::string sentence;
        for (char c: txt) {
            sentence += c;
            if (delimiters.find(c) != std::string::npos) {
                sentence = sentence.substr(0, sentence.length() - 1);
                if (!sentence.empty()) {
                    sentences.push_back(sentence);
                    sentence.clear();
                }
            }
        }
        if (!sentence.empty()) {
            sentences.push_back(sentence);
        }
        return sentences;
    }
};
