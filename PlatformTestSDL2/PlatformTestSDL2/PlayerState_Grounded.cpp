#include "PlayerState_Grounded.h"

#include "PlayerState_Jump.h"
#include "PlayerState_Fall.h"
PlayerState* PlayerState_Grounded::Update(Player& player, std::vector<Entity*> entityList)
{
	player.ApplyGravity();
	player.ApplyInternalForces();
	//player.HandleWallSliding();
	
	player.MoveHorizontal(entityList);
	player.MoveVertical(entityList);
    if (player.GetVelocityY() > 0)
    {
        return Transition(player, new PlayerState_Fall());
    }
    return nullptr;

}

PlayerState* PlayerState_Grounded::GetInput(Player& player, PlayerActions action, InputType type)
{
    if (type == InputType::PRESSED)
    {
        switch(action)
        {
        case PlayerActions::JUMP:
            return Transition(player, new PlayerState_Jump());
            break;
        default:
            break;
        }
    }
    return nullptr;
}