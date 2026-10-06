#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

#include "./types.hpp"

std::string getTokenType(TokenType type) {
    switch (type) {
    case TokenType::KEYWORD:
        return "KEYWORD";
    case TokenType::IDENTIFIER:
        return "IDENTIFIER";
    case TokenType::SEMICOLON:
        return "SEMICOLON";
    case TokenType::INT_LITERAL:
        return "INT_LITERAL";
    default:
        return "UNKNOWN";
    }
}

int main(int argc, char *argv[]) {
    // if (argc == 1) {
    //     std::cout << "usage: " << argv[0] << " <filename>\n";
    // }

    std::vector<Token> tokens;
    std::string str = "return 0";
    std::size_t len = str.size();

    for (std::size_t i = 0; i < len; i++) {
        if (std::isspace(str[i])) {
            continue;
        }

        if (std::isalpha(str[i]) || str[i] == '_') {
            std::string text;
            while (std::isalnum(str[i]) || str[i] == '_') {
                text.push_back(str[i]);
                i++;
            }
            i--;

            if (text == "return" || text == "int") {
                tokens.push_back({TokenType::KEYWORD, text});
            }
        }

        if (std::isdigit(str[i])) {
            std::string text;
            while (std::isdigit(str[i])) {
                text.push_back(str[i]);
                i++;
            }
            i--;

            tokens.push_back({TokenType::INT_LITERAL, text});
        }

        // if (i == 0 && std::isdigit(str[i])) {
        //
        // }
    }

    for (std::size_t i = 0; i < tokens.size(); i++) {
        std::cout << i + 1 << ". Type: " << getTokenType(tokens[i].type)
                  << ", Value: " << tokens[i].value << "\n";
    }

    return 0;
}
