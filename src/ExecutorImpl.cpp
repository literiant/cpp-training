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

namespace
{
// 左转（逆时针）：E -> N -> W -> S -> E
char TurnLeft(char heading) noexcept
{
    switch (heading)
    {
    case 'E':
        return 'N';
    case 'N':
        return 'W';
    case 'W':
        return 'S';
    case 'S':
        return 'E';
    default:
        return heading;
    }
}

// 右转（顺时针）：E -> S -> W -> N -> E
char TurnRight(char heading) noexcept
{
    switch (heading)
    {
    case 'E':
        return 'S';
    case 'S':
        return 'W';
    case 'W':
        return 'N';
    case 'N':
        return 'E';
    default:
        return heading;
    }
}
}  // namespace

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const auto command : commands)
    {
        switch (command)
        {
        case 'M':
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
            break;
        case 'L':
            // L 指令：左转
            pose.heading = TurnLeft(pose.heading);
            break;
        case 'R':
            // R 指令：右转
            pose.heading = TurnRight(pose.heading);
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