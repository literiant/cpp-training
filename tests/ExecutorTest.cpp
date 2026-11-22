#include <gtest/gtest.h>

#include <memory>
#include <tuple>

#include "Executor.hpp"

namespace adas
{
// 重载 Pose 的 == 运算符，方便GTest断言对比Pose对象
bool operator==(const Pose& lhs, const Pose& rhs)
{
    // tie把三个成员打包成tuple，直接比较
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}

// 测试用例：没有执行任何指令时，Executor 返回初始姿态
TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // given：准备环境，创建Executor，初始姿态 (x=0,y=0,朝向E东)
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when：空，不执行任何移动指令

    // then：断言查询到的姿态和初始姿态一致
    const Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());

    // when

    // then
    const Pose target({0, 0,'N'});
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas