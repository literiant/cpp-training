# 指定最低CMake版本要求，低于3.0的cmake无法构建
cmake_minimum_required(VERSION 3.0)

# 定义项目名 cpp-training，版本号 0.1.0
PROJECT(cpp-training VERSION 0.1.0)

# 指定C++标准为C++17
SET(CMAKE_CXX_STANDARD 17)

# 设置C++编译选项：
# -Wno-deprecated-declarations：不警告废弃接口
# -Wall：开启大部分警告
# -Werror：所有警告直接当成编译错误（严格检查）
# -Wnon-virtual-dtor：类有虚函数但析构不是虚函数时告警
# -Woverloaded-virtual：虚函数重载隐藏时告警
SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -Wall -Werror -Wnon-virtual-dtor -Woverloaded-virtual")

# 开启CTest测试框架，后续可以用 ctest 跑用例
ENABLE_TESTING()

# 进入src子目录，执行里面的CMakeLists.txt（业务源码）
ADD_SUBDIRECTORY(src)
# 进入tests子目录，执行里面的CMakeLists.txt（测试代码）
ADD_SUBDIRECTORY(tests)