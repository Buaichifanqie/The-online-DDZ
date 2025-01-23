cmake_minimum_required(VERSION 3.5)

project(crypto)



#搜索当前目录下所有文件
aux_source_directory(./ SRC)
# 显示头文件
file(GLOB HEAD ./*.h)

#将当前目录下的源文件打包成静态库
add_library(crypto ${SRC} ${HEAD})

# 链接核心模块库
target_link_libraries(crypto PRIVATE Qt${QT_VERSION_MAJOR}::Core
    "D:\\OpenSSL-Win64\\lib\\VC\\x64\\MD\\libcrypto.lib")
