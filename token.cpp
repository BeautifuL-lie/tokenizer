#include "token.hpp"

#include "types.hpp"

#include <cctype>
#include <string>
#include <vector>

std::vector<Token> tokenize(const std::string &str) {
    std::vector<Token> tokens;
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
    }
    return tokens;
}

std::string get_token_type(TokenType type) {
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
