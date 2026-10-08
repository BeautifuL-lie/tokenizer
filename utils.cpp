#include <fstream>
#include <sstream>
#include <string>

#include "./utils.hpp"

namespace util {
    std::string readfile(const std::string &filepath) {
        std::ifstream file(filepath);

        if (!file.is_open()) {
            return "";
        }

        std::ostringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
} // namespace util
