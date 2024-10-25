list(APPEND CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")

add_executable(temp_ex temp_ex.c)
target_include_directories(temp_ex PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(temp_ex PN_test_lib)

install(
    TARGETS temp_ex
    EXPORT ${PROJECT_NAME}-targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
