cmake_minimum_required(VERSION 3.5)

project(tcp)

#搜索当前目录下所有文件
aux_source_directory(./ SRC)
# 显示头文件
file(GLOB HEAD ./*.h)

#将当前目录下的源文件打包成静态库
add_library(tcp ${SRC} ${HEAD})

# 链接核心模块库
target_link_libraries(tcp PRIVATE Qt${QT_VERSION_MAJOR}::Core Ws2_32)
