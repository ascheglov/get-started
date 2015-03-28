add_library(crc32 STATIC
    crc32.hpp crc32.cpp crc32_data.cpp
    helpers.hpp
)
set_target_properties(crc32 PROPERTIES FOLDER "CRC32 Library")

#------------------------------------------------------------------------------
# tests

add_executable(crc32_tests
    ../tests/tests_runner.cpp
    crc32_test.cpp
    helpers_test.cpp
)
target_link_libraries(crc32_tests crc32)
set_target_properties(crc32_tests PROPERTIES FOLDER "CRC32 Library")

# run tests
if (NOT EMSCRIPTEN)
    add_custom_command(TARGET crc32_tests POST_BUILD COMMAND crc32_tests)
else()
    add_custom_command(TARGET crc32_tests POST_BUILD COMMAND node crc32_tests)
endif()
