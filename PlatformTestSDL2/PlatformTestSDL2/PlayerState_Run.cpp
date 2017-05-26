#include "PlayerState_Run.h"
#include <iostream>
PlayerState_Run::PlayerState_Run()
{

}
PlayerState_Run::~PlayerState_Run()
{

}

void PlayerState_Run::Enter(Player& player)
{
    std::cout << "Enter Run" << std::endl;
}
void PlayerState_Run::Exit()
{
    std::cout << "Exit Run" << std::endl;
}
PlayerState* PlayerState_Run::GetInput(Player& player, PlayerActions action, InputType type)
{
    if (type == InputType::RELEASED)
    {
        switch(action)
        {
        case PlayerActions::MOVE_LEFT:
            return Transition(player, new PlayerState_Idle());
            break;
        case PlayerActions::MOVE_RIGHT:
            return Transition(player, new PlayerState_Idle());
            break;
        default:
            break;
        }
    }
    return nullptr;
}
void PlayerState_Run::Update(Player& player)
{

}