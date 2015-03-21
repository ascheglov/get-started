#include "crc32/crc32.hpp"

void Crc32::update(const void* data, std::size_t size)
{
    for (auto it = static_cast<const std::uint8_t*>(data), last = it + size; it != last; ++it)
        m_hash = table[(m_hash ^ *it) & 0xFF] ^ (m_hash >> 8);
}
