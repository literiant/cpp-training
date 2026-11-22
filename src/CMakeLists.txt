# 定义变量 INCLUDE，值为项目根目录下的 include 文件夹路径
SET(INCLUDE ${CMAKE_SOURCE_DIR}/include)

# 自动搜集当前目录下所有 .cpp 文件，存入 SOURCE 变量
FILE(GLOB SOURCE "*.cpp")

# 从 SOURCE 列表里移除 Main.cpp（大写M）
LIST(REMOVE_ITEM SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp)
# 从 SOURCE 列表里移除 main.cpp（小写m）
LIST(REMOVE_ITEM SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# 添加编译选项：-Wall 开启大部分警告
ADD_COMPILE_OPTIONS("-Wall")
# 添加编译选项：-Werror 把所有警告直接当成错误，编译失败
ADD_COMPILE_OPTIONS("-Werror")

# 用筛选后的 cpp 文件，编译生成库，库名 training
ADD_LIBRARY(training ${SOURCE})

# 给 training 库设置头文件查找目录
# PUBLIC：依赖这个库的其他目标，也会自动继承这个 include 路径
TARGET_INCLUDE_DIRECTORIES(training PUBLIC "${INCLUDE}")