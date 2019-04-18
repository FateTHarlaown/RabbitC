cmake_minimum_required(VERSION 3.10)
project(RabbitC)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./unittest)
aux_source_directory(. SOURCE_FILES)

add_executable(RabbitC ${SOURCE_FILES})

#test
enable_testing()
add_test(NAME unittest COMMAND unittest)