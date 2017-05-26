#include "PlayerState_Idle.h"
#include <iostream>
PlayerState_Idle::PlayerState_Idle()
{

}
PlayerState_Idle::~PlayerState_Idle()
{

}

void PlayerState_Idle::Enter(Player& player)
{
    std::cout << "Enter Idle" << std::endl;
}
void PlayerState_Idle::Exit()
{
    std::cout << "Exit Idle" << std::endl;
}
PlayerState* PlayerState_Idle::GetInput(Player& player, PlayerActions action, InputType type)
{
    if (type != InputType::RELEASED)
    {
        switch(action)
        {
        case PlayerActions::MOVE_LEFT:
            return Transition(player, new PlayerState_Run());
            break;
        case PlayerActions::MOVE_RIGHT:
            return Transition(player, new PlayerState_Run());
            break;
        default:
            break;
        }
    }
    return nullptr;
}
void PlayerState_Idle::Update(Player& player)
{

}
