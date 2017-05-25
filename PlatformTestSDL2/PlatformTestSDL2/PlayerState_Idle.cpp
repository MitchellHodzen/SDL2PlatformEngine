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
    //Exit
}
void PlayerState_Idle::GetInput(Player& player, PlayerActions action, InputType type)
{

}
void PlayerState_Idle::Update(Player& player)
{

}
