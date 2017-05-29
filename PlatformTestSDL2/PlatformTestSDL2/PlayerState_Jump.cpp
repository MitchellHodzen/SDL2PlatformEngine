#include "PlayerState_Jump.h"

//Transition Classes:
#include "PlayerState_Fall.h"

PlayerState_Jump::PlayerState_Jump()
{
    jumpTimer = 0;
    maxJumpTime = 0.2f * 1000.0f;
}
PlayerState_Jump::~PlayerState_Jump()
{

}

void PlayerState_Jump::Enter(Player& player)
{
    //std::cout << "Enter Jump" << std::endl;
    player.SetAnimation(Animations::PlayerAnimations::Jump);
}
void PlayerState_Jump::Exit()
{
    //std::cout << "Exit Jump" << std::endl;
}

PlayerState* PlayerState_Jump::Update(Player& player, std::vector<Entity*> entityList)
{
    jumpTimer += player.GetCurrentFrameTime() - player.GetLastFrameTime();
	if (jumpTimer >= maxJumpTime)
	{
		return Transition(player, new PlayerState_Fall());
	}

    if (!PlayerState_Airborne::movingHorizontal)
    {
        player.ApplyHorizontalFriction();
    }
	player.ApplyGravity();
	player.ApplyInternalForces();
	//player.HandleWallSliding();
	
	player.MoveHorizontal(entityList);
    
    return PlayerState_Airborne::Update(player, entityList);

}
PlayerState* PlayerState_Jump::GetInput(Player& player, PlayerActions action, InputType type)
{
    if (type != InputType::RELEASED)
    {
        switch(action)
        {
        case PlayerActions::JUMP:
			player.SetNewVelocityY(-player.GetMaxJumpSpeed());
            break;
        default:
            break;
        }
    }
    if (type == InputType::RELEASED)
    {
        switch(action)
        {
        case PlayerActions::JUMP:
            return Transition(player, new PlayerState_Fall());
        }
    }
    return PlayerState_Airborne::GetInput(player, action, type);
}