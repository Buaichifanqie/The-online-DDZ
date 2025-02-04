cmake_minimum_required(VERSION 3.27)
project(Crypto)
set(CMAKE_CXX_STANDARD 17)

aux_source_directory(./ SRC)

add_library(Crypto STATIC ${SRC})
target_link_libraries(Crypto crypto)