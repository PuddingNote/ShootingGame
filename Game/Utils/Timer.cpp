#include "Timer.h"

Timer::Timer(float targetTime)
{

}

void Timer::Tick(float deltaTime)
{
    elapsedTime += deltaTime;
}

void Timer::Reset()
{
    elapsedTime = 0.0f;
}

bool Timer::IsTimeout() const
{
    return elapsedTime >= targetTime;
}

void Timer::SetTargetTime(float newTargetTime)
{
    targetTime = newTargetTime;
}