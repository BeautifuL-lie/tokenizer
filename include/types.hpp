#pragma once

#include <string>

enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    SEMICOLON,
    INT_LITERAL
};

struct Token {
    TokenType type;
    std::string value;
};
