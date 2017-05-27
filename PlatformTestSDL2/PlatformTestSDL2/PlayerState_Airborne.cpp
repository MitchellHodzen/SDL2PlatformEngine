#include "PlayerState_Airborne.h"

void PlayerState_Airborne::Update(Player& player, std::vector<Entity*> entityList)
{
    if (!movingHorizontal)
    {
        player.ApplyHorizontalFriction();
    }
	player.ApplyGravity();
	player.ApplyInternalForces();
	player.HandleWallSliding();
	
	player.MoveHorizontal(entityList);
	player.MoveVertical(entityList);
}
PlayerState* PlayerState_Airborne::GetInput(Player& player, PlayerActions action, InputType type)
{
    if (type != InputType::RELEASED)
    {
        switch(action)
        {
        case PlayerActions::MOVE_LEFT:
            player.Accelerate(Direction::LEFT);
            movingHorizontal = true;
            break;
        case PlayerActions::MOVE_RIGHT:
            player.Accelerate(Direction::RIGHT);
            movingHorizontal = true;
            break;
        default:
            break;
        }
    }
    if (type == InputType::RELEASED)
    {
        if (action == PlayerActions::MOVE_LEFT || action == PlayerActions::MOVE_RIGHT)
        {
            movingHorizontal = false;
        }
    }
    return nullptr;
}