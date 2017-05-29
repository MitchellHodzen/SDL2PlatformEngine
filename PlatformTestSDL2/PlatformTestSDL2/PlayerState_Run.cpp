#include "PlayerState_Run.h"

//Transition Classes:
#include "PlayerState_Idle.h"

PlayerState_Run::PlayerState_Run(Direction direction)
{
    currentDirection = direction;
}
PlayerState_Run::~PlayerState_Run()
{

}

void PlayerState_Run::Enter(Player& player)
{
    //std::cout << "Enter Run" << std::endl;
    player.SetAnimation(Animations::PlayerAnimations::Run);
}
void PlayerState_Run::Exit()
{
    //std::cout << "Exit Run" << std::endl;
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
    return PlayerState_Grounded::GetInput(player, action, type);
}
PlayerState* PlayerState_Run::Update(Player& player, std::vector<Entity*> entityList)
{
    player.Accelerate(currentDirection);
    return PlayerState_Grounded::Update(player, entityList);
}