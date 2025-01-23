cmake_minimum_required(VERSION 3.5)

project(ddz-network-client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 自动处理UI文件，最后生成一个ui_xxx.h文件
set(CMAKE_AUTOUIC ON)
# 自动处理元对象相关的宏 例如Q_OBJECT
set(CMAKE_AUTOMOC ON)
# 自动处理qrc文件，会将其生成相应的c++代码，最后嵌入到可执行文件中
set(CMAKE_AUTORCC ON)

# C++标准
set(CMAKE_CXX_STANDARD 17)
# 让编译器严格按照上面的标准进行程序的构建，如果编译器不支持上面的标准，cmake会报错并且停止构建
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

# 搜索qt相关的组件（QT模块）                                使用了sql模块
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED Sql Multimedia)
#                                                              使用多媒体模块
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED Multimedia)

#存储根节点源文件的名字
set(PROJECT_SOURCES
        main.cpp
 )

# 添加头文件目录--要写到添加子目录上面
include_directories(
    ${PROJECT_SOURCE_DIR}/card
    ${PROJECT_SOURCE_DIR}/windows
    ${PROJECT_SOURCE_DIR}/control
    ${PROJECT_SOURCE_DIR}/player
    ${PROJECT_SOURCE_DIR}/strategy
    ${PROJECT_SOURCE_DIR}/thread
    ${PROJECT_SOURCE_DIR}/tcp
    ${PROJECT_SOURCE_DIR}/serialize
)

# 添加子目录
add_subdirectory(card)
add_subdirectory(windows)
add_subdirectory(control)
add_subdirectory(player)
add_subdirectory(strategy)
add_subdirectory(thread)
add_subdirectory(tcp)
add_subdirectory(serialize)

# 添加资源文件
qt5_add_resources(RES res.qrc)

if(ANDROID)
  add_library(ddz-network-client SHARED
    ${PROJECT_SOURCES}
  )
else()
  add_executable(ddz-network-client
    ${PROJECT_SOURCES}
    ${RES}
  )
endif()

target_link_libraries(ddz-network-client PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    card windows control player strategy thread
)
