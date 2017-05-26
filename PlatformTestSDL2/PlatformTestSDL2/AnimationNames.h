#pragma once
namespace Animations
{
    enum class AnimationType {WallSlide, Fall, Jump, Idle, Run};
    namespace PlayerAnimations
    {
        const AnimationType WallSlide = AnimationType::WallSlide;
        const AnimationType Fall = AnimationType::Fall;
        const AnimationType Jump = AnimationType::Jump;
        const AnimationType Idle = AnimationType::Idle;
        const AnimationType Run = AnimationType::Run;
    };
};