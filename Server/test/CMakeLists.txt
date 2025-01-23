cmake_minimum_required(VERSION 3.27)
project(Test)
set(CMAKE_CXX_STANDARD 17)

aux_source_directory(./ SRC)

add_library(test ${SRC})
target_link_libraries(test protobuf)



