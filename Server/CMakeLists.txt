cmake_minimum_required(VERSION 3.24)
project(Server)

set(CMAKE_CXX_STANDARD 17)

# 添加头文件目录，这样就可以包含其它头文件目录了
include_directories(
        ${PROJECT_SOURCE_DIR}/common
        ${PROJECT_SOURCE_DIR}/http
        ${PROJECT_SOURCE_DIR}/reactor
        ${PROJECT_SOURCE_DIR}/tcp
        ${PROJECT_SOURCE_DIR}/thread
        ${PROJECT_SOURCE_DIR}/Crypto
        ${PROJECT_SOURCE_DIR}/serialize
        ${PROJECT_SOURCE_DIR}/game
        ${PROJECT_SOURCE_DIR}/database
        "/usr/local/ssl/include/"
        "/usr/include/mysql/"
#        "/usr/local/include/"
        "/usr/local/include/json/"
        "/usr/local/include/sw/redis++/"

        # test测试
        ${PROJECT_SOURCE_DIR}/test

)


# 添加子目录
add_subdirectory(common)
add_subdirectory(http)
add_subdirectory(reactor)
add_subdirectory(tcp)
add_subdirectory(thread)
add_subdirectory(Crypto)
add_subdirectory(serialize)
add_subdirectory(game)
add_subdirectory(database)

#测试用目录
add_subdirectory(test)

link_directories(/usr/local/ssl/lib64/)
link_directories(/usr/lib/mysql)
link_directories(/usr/local/lib64/)
link_directories(/usr/local/lib/)

# link_directories(/home/buaichifanqie/tool/jsoncpp-master/build/lib/)

# 链接子目录中的静态库文件
link_libraries(tcp http reactor thread common test Crypto serialize game database)

#指定可执行文件生成到对应的目录中
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Server main.cpp)


