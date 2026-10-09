#include "../include/token.hpp"
#include "../include/types.hpp"
#include "../include/utils.hpp"

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "usage: " << argv[0] << " <file>\n";
        return 1;
    }

    std::string filetxt = util::readfile(argv[1]);

    std::vector<Token> tokens = tokenize(filetxt);

    for (std::size_t i = 0; i < tokens.size(); i++) {
        std::cout << i + 1 << ". Type: " << get_token_type(tokens[i].type)
                  << ", Value: " << tokens[i].value << "\n";
    }

    return 0;
}
