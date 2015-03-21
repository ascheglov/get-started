#pragma once

#include <cstddef>
#include <cstdint>

class Crc32 {
public:
    Crc32() = default;

    void update(const void* data, std::size_t size);
    std::uint32_t digest() const {
        return ~m_hash;
    }
private:
    std::uint32_t m_hash = ~0ul;
    static const std::uint_least32_t table[256];
};
