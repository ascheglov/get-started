#pragma once

#include "crc32/crc32.hpp"

#include "string"

inline std::uint32_t crc32_num(const std::string& text) {
    Crc32 crc32;
    crc32.update(text.c_str(), text.size());
    return crc32.digest();
}

inline std::string crc32_hex(const std::string& text) {
    auto hash = crc32_num(text);
    static const char hex_table[17] = "0123456789ABCDEF";
    std::string hash_hex;
    for (auto i = 7; i >= 0; --i) {
        auto nibble = (hash >> i * 4) & 0xF;
        hash_hex.push_back(hex_table[nibble]);
    }
    return hash_hex;
}
