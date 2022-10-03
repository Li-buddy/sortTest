# CMakeList.txt: sortTest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.10)

project (sortTest)

include_directories("${PROJECT_SOURCE_DIR}/include")

AUX_SOURCE_DIRECTORY(./  DIR_SRCS)

#生成可执行文件
ADD_EXECUTABLE(sortTest  ${DIR_SRCS})

# TODO: 如有需要，请添加测试并安装目标。
