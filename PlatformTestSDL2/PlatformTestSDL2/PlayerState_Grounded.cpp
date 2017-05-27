#include "PlayerState_Grounded.h"
#include <iostream>
void PlayerState_Grounded::Update(Player& player, std::vector<Entity*> entityList)
{
	player.ApplyGravity();
	player.ApplyInternalForces();
	player.HandleWallSliding();
	
	player.MoveHorizontal(entityList);
	player.MoveVertical(entityList);

}

PlayerState* PlayerState_Grounded::GetInput(Player& player, PlayerActions action, InputType type)
{
    if (type == InputType::PRESSED)
    {
        switch(action)
        {
        case PlayerActions::JUMP:
            std::cout<<"Jumping now"<<std::endl;
            return Transition(player, new PlayerState_Airborne());
            break;
        default:
            break;
        }
    }
    return nullptr;
}