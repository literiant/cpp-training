#include "ExecutorImpl.hpp"

#include <new>

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const auto command : commands)
    {
        if (command != 'M')
        {
            continue;
        }

        // M 指令：沿当前朝向前进一格
        switch (pose.heading)
        {
        case 'N':
            ++pose.y;
            break;
        case 'S':
            --pose.y;
            break;
        case 'E':
            ++pose.x;
            break;
        case 'W':
            --pose.x;
            break;
        default:
            break;
        }
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas