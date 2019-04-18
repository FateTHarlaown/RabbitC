cmake_minimum_required(VERSION 3.10)
project(unittest)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/..)

set(TEST_FILES
        test.cc
        lexer_test.cc
        ../tocken.cc
        ../token.h
        ../lex.yy.cc)

set(TEST_LIBRARIES gtest pthread)
add_executable(unittest ${TEST_FILES})
target_link_libraries(unittest ${TEST_LIBRARIES})
