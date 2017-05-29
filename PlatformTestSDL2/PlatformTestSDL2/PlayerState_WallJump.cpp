#include "PlayerState_WallJump.h"

//Transition Classes:
#include "PlayerState_Fall.h"

PlayerState_WallJump::PlayerState_WallJump(Direction direction)
{
    startDirection = direction;
}
PlayerState_WallJump::~PlayerState_WallJump()
{

}

void PlayerState_WallJump::Enter(Player& player)
{
    //std::cout << "Enter WallJump" << std::endl;
    player.SetAnimation(Animations::PlayerAnimations::Jump);
    if (startDirection == Direction::RIGHT)
	{
        player.SetNewVelocityX(-player.GetMaxJumpSpeed());
	}
	else
	{
		player.SetNewVelocityX(player.GetMaxJumpSpeed());
	}
}
void PlayerState_WallJump::Exit()
{
    //std::cout << "Exit WallJump" << std::endl;
}

PlayerState* PlayerState_WallJump::Update(Player& player, std::vector<Entity*> entityList)
{
    
    return PlayerState_Jump::Update(player, entityList);

}
PlayerState* PlayerState_WallJump::GetInput(Player& player, PlayerActions action, InputType type)
{
    return PlayerState_Jump::GetInput(player, action, type);
}