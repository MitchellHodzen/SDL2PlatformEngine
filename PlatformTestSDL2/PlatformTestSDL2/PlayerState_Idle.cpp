#include "PlayerState_Idle.h"

//Transition Classes:
#include "PlayerState_Run.h"

PlayerState_Idle::PlayerState_Idle()
{

}
PlayerState_Idle::~PlayerState_Idle()
{

}

void PlayerState_Idle::Enter(Player& player)
{
    //std::cout << "Enter Idle" << std::endl;
    player.SetAnimation(Animations::PlayerAnimations::Idle);
}
void PlayerState_Idle::Exit()
{
    //std::cout << "Exit Idle" << std::endl;
}
PlayerState* PlayerState_Idle::GetInput(Player& player, PlayerActions action, InputType type)
{
    if (type != InputType::RELEASED)
    {
        switch(action)
        {
        case PlayerActions::MOVE_LEFT:
            return Transition(player, new PlayerState_Run(Direction::LEFT));
            break;
        case PlayerActions::MOVE_RIGHT:
            return Transition(player, new PlayerState_Run(Direction::RIGHT));
            break;
        default:
            break;
        }
    }
    return PlayerState_Grounded::GetInput(player, action, type);
}
PlayerState* PlayerState_Idle::Update(Player& player, std::vector<Entity*> entityList)
{
    player.ApplyHorizontalFriction();
    return PlayerState_Grounded::Update(player, entityList);
}
