cmake_minimum_required(VERSION 3.5)

project(thread)

#搜索当前目录下所有文件
aux_source_directory(./ SRC)

#将当前目录下的源文件打包成静态库
add_library(thread ${SRC})

# 链接核心模块库
target_link_libraries(thread PRIVATE Qt${QT_VERSION_MAJOR}::Core)
