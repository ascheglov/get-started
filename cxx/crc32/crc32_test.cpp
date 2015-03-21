#include "crc32/crc32.hpp"

#include "third_party/catch/catch.hpp"

namespace {

struct Crc32Fixture {
    Crc32 crc32;
};

}  // anon. namespace

TEST_CASE_METHOD(Crc32Fixture, "empty string", "") {
    crc32.update("", 0);
    REQUIRE(crc32.digest() == 0);
}

TEST_CASE_METHOD(Crc32Fixture, "NULL pointer", "") {
    crc32.update(nullptr, 0);
    REQUIRE(crc32.digest() == 0);
}

TEST_CASE_METHOD(Crc32Fixture, "single string", "") {
    crc32.update("123456789", 9);
    REQUIRE(crc32.digest() == 0xCBF43926ul);
}

TEST_CASE_METHOD(Crc32Fixture, "two updates", "") {
    crc32.update("12345", 5);
    crc32.update("6789", 4);
    REQUIRE(crc32.digest() == 0xCBF43926ul);
}
