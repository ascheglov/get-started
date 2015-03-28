add_executable(web_calc
    crc32_bindings.cpp
)
target_link_libraries(web_calc
    --bind  # enables embind
    crc32
)
configure_file(web_calc.html web_calc.html COPYONLY)
