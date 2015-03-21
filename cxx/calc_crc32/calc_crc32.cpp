#include <iostream>
#include <string>

#include "crc32/helpers.hpp"

int main() {
    std::cout << "Input a line of text to calculate its crc32:\n> ";
    std::string line;
    getline(std::cin, line);
    std::cout << crc32_hex(line) << '\n';
}
