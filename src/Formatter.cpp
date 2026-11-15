#include <string>
#include <cctype>

class Formatter {
public:
    std::string replaceWords(const std::string& text, const std::string& from, const std::string& to) {
        if (from.empty())
            return text;
        
        std::string newtext = text;
        size_t index = 0;
        while ((index = newtext.find(from, index)) != std::string::npos) {
            newtext.replace(index, from.length(), to);
            index += to.length(); 
        }

        return newtext;
    }

    bool isStringInText(const std::string& text, const std::string& request) {
        return text.find(request) != std::string::npos;
    }

    std::string eachCapitalize(const std::string& text) {
        std::string newtext = text;
        bool newWord = true;
    
        for (char& c : newtext) {
            if (std::isspace(c)) {
                newWord = true;
            } else if (newWord && std::isalpha(c)) {
                c = static_cast<char>(std::toupper(c));
                newWord = false;
            }
        }

        return newtext;
    }

    std::string firstCapitalize(const std::string& text) {
        std::string newtext = text;
        bool newSent = true;
    
        for (char& c : newtext) {
            if (c == '.' || c == '!' || c == '?') {
                newSent = true;
            } else if (newSent && std::isalpha(c)) {
                c = static_cast<char>(std::toupper(c));
                newSent = false;
            }
        }

        return newtext;
    }

    std::string enumerateSentences(const std::string& text) {
        std::string newtext = "1. ";
        int i = 2;

    
        for (char c : text) {
            if (c == '.') {
                newtext += ".\n" + std::to_string(i) + ".";
                i++;
            } else {
                newtext += c;
            }
        }

        return newtext;
    }
};