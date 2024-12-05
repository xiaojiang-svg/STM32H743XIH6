# 设置CMake版本要求
cmake_minimum_required(VERSION 3.20)

# 设置项目名称和语言
project(stm32h743_N_OS C CXX)

# 设置C++和C标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

#设置编译选项
set(CMAKE_C_FLAGS "-Wall -Wextra -O0")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O0")

# 设置头文件路径
include_directories(${PROJECT_SOURCE_DIR}/CMSIS ${PROJECT_SOURCE_DIR}/CMSIS/CLock ${PROJECT_SOURCE_DIR}/CMSIS/Compiler ${PROJECT_SOURCE_DIR}/CMSIS/Core ${PROJECT_SOURCE_DIR}/CMSIS/Interrupt ${PROJECT_SOURCE_DIR}/Drivers/Inc ${PROJECT_SOURCE_DIR}/FATFS/Inc ${PROJECT_SOURCE_DIR}/Include/App ${PROJECT_SOURCE_DIR}/Include/Interrupt ${PROJECT_SOURCE_DIR}/Lib/hal_conf ${PROJECT_SOURCE_DIR}/Lib/Inc)



# 外部库
# link_directories()

# 生成可执行文件
file(GLOB_RECURSE Src ${PROJECT_SOURCE_DIR}/Inc/*.c ${PROJECT_SOURCE_DIR}/CMSIS/*.c ${PROJECT_SOURCE_DIR}/Drivers/*.c ${PROJECT_SOURCE_DIR}/FATFS/*.c ${PROJECT_SOURCE_DIR}/Include/*.c ${PROJECT_SOURCE_DIR}/Lib/*.c ${PROJECT_SOURCE_DIR}/Startup/*.c)
add_executable(proc ${Src})

# 链接额外库
# target_link_libraries()

# 生成compile_commands.json文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置编译输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)