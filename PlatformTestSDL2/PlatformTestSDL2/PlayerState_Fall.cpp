#include "PlayerState_Fall.h"

//Transition Classes:
#include "PlayerState_WallSlide.h"

PlayerState_Fall::PlayerState_Fall()
{

}
PlayerState_Fall::~PlayerState_Fall()
{

}

void PlayerState_Fall::Enter(Player& player)
{
    //std::cout << "Enter Fall" << std::endl;
}
void PlayerState_Fall::Exit()
{
    //std::cout << "Exit Fall" << std::endl;
}

PlayerState* PlayerState_Fall::Update(Player& player, std::vector<Entity*> entityList)
{
    if (player.GetVelocityY() > 0)
    {
        player.SetAnimation(Animations::PlayerAnimations::Fall);
    }

    if (!PlayerState_Airborne::movingHorizontal)
    {
        player.ApplyHorizontalFriction();
    }
	player.ApplyGravity();
	player.ApplyInternalForces();
	//player.HandleWallSliding();

    Direction collisionDirection = player.MoveHorizontal(entityList);
    if (player.GetVelocityY() > 0)
    {
        if (collisionDirection == Direction::LEFT)
        {
            return Transition(player, new PlayerState_WallSlide(collisionDirection));
        }
        if (collisionDirection == Direction::RIGHT)
        {
            return Transition(player, new PlayerState_WallSlide(collisionDirection));
        }
    }
    return PlayerState_Airborne::Update(player, entityList);

}
PlayerState* PlayerState_Fall::GetInput(Player& player, PlayerActions action, InputType type)
{
    if (type != InputType::RELEASED)
    {
        switch(action)
        {
        case PlayerActions::JUMP:
			//player.SetNewVelocityY(-player.GetMaxJumpSpeed());
            break;
        default:
            break;
        }
    }
    return PlayerState_Airborne::GetInput(player, action, type);
}