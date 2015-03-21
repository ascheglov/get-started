#include "crc32/helpers.hpp"

#include "third_party/catch/catch.hpp"

TEST_CASE("crc32_num", "") {
    REQUIRE(crc32_num("123456789") == 0xCBF43926ul);
}

TEST_CASE("crc32_hex", "") {
    REQUIRE(crc32_hex("123456789") == "CBF43926");
}
