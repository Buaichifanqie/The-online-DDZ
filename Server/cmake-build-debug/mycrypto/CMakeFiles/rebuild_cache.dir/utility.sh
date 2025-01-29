set -e

cd /cygdrive/d/DDZ-network/Server/cmake-build-debug/mycrypto
/cygdrive/c/Users/kongwenshuo/AppData/Local/JetBrains/CLion2024.1/cygwin_cmake/bin/cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
