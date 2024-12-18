#!/bin/bash

# 清理 CMake 生成的缓存文件和构建文件
echo "Cleaning CMake build files..."

# 删除 CMake 产生的缓存文件和构建目录
rm -rf CMakeCache.txt CMakeFiles cmake_install.cmake Makefile

# 可选：如果你想要删除构建目录中的所有文件（例如 build 目录），可以使用以下命令：
# rm -rf build/

# 如果你有其他特定目录需要清理，可以继续添加它们
# rm -rf path/to/other/files/

echo "CMake build files cleaned successfully."
