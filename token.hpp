#pragma once

#include "types.hpp"
#include <vector>

std::vector<Token> tokenize(const std::string &str);
std::string get_token_type(TokenType type);
