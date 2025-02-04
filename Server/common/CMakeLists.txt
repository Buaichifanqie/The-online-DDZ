cmake_minimum_required(VERSION 3.27)
project(common)
set(CMAKE_CXX_STANDARD 17)

# 取出当前目录中所有的源文件, 存储到一个变量中
aux_source_directory(./ SRC)
# 把源文件制作成静态库
add_library(common STATIC ${SRC})
target_link_libraries(common
        /usr/local/lib/libjsoncpp.so)



#cmake_minimum_required(VERSION 3.27)
#project(common)
#set(CMAKE_CXX_STANDARD 17)
## 取出当前目录中所有的源文件, 存储到一个变量中
#aux_source_directory(./ SRC)
## 把源文件制作成静态库
#add_library(common STATIC ${SRC})
## 查找 jsoncpp 库
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(JSONCPP jsoncpp)
## 链接 jsoncpp 库
#target_link_libraries(common ${JSONCPP_LIBRARIES})
#target_include_directories(common PUBLIC ${JSONCPP_INCLUDE_DIRS})
