#include "crc32/crc32.hpp"

#include <emscripten/bind.h>
using namespace emscripten;

// Extension method which takes std::string.
static void crc32_update(Crc32& crc32, const std::string& data) {
    crc32.update(data.data(), data.size());
}

EMSCRIPTEN_BINDINGS(crc32) {
    class_<Crc32>("Crc32")
        .constructor()
        .function("update", &crc32_update)
        .property("digest", &Crc32::digest)
        ;
}
