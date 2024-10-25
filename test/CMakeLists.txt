find_package(Check CONFIG NAMES Check check)

add_executable(main.test main_test.c temp_test.c)

target_include_directories(main.test PRIVATE ${CMAKE_BINARY_DIR}/test)

target_link_libraries(main.test PRIVATE PN_test_lib check m subunit)

set_target_properties(main.test PROPERTIES C_STANDARD 17)

add_test(NAME main_test COMMAND main.test)

add_custom_command(
    TARGET main.test
    POST_BUILD
    COMMAND ctest -C $<CONFIGURATION> --output-on-failure)
