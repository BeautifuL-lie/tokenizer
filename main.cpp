#include "types.hpp"
#include "utils.hpp"

#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
    if (argc == 1) {
        std::cout << "usage: " << argv[0] << " <file>\n";
        return 1;
    }

    std::string filetxt = util::readfile(argv[1]);

    std::vector<Token> tokens;

    // {
    //     std::ifstream file(argv[1]);
    //
    //     if (!file.is_open()) {
    //         std::cerr << "Error opening the file!" << std::endl;
    //         return 1;
    //     }
    //
    //     std::string line;
    //
    //     while (std::getline(file, line)) {
    //         std::size_t len = line.size();
    //
    //         for (std::size_t i = 0; i < len; i++) {
    //             if (std::isspace(line[i])) {
    //                 continue;
    //             }
    //
    //             if (std::isalpha(line[i]) || line[i] == '_') {
    //                 std::string text;
    //                 while (std::isalnum(line[i]) || line[i] == '_') {
    //                     text.push_back(line[i]);
    //                     i++;
    //                 }
    //                 i--;
    //
    //                 if (text == "return" || text == "int") {
    //                     tokens.push_back({TokenType::KEYWORD, text});
    //                 }
    //             }
    //
    //             if (std::isdigit(line[i])) {
    //                 std::string text;
    //                 while (std::isdigit(line[i])) {
    //                     text.push_back(line[i]);
    //                     i++;
    //                 }
    //                 i--;
    //
    //                 tokens.push_back({TokenType::INT_LITERAL, text});
    //             }
    //         }
    //     }
    // }

    // for (std::size_t i = 0; i < tokens.size(); i++) {
    //     std::cout << i + 1 << ". Type: " << getTokenType(tokens[i].type)
    //               << ", Value: " << tokens[i].value << "\n";
    // }

    return 0;
}
