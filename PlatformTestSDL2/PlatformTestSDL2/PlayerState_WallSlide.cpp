#include "PlayerState_WallSlide.h"

#include "PlayerState_Fall.h"
#include "PlayerState_Idle.h"
#include "PlayerState_WallJump.h"
PlayerState_WallSlide::PlayerState_WallSlide(Direction direction)
{
    currentDirection = direction;
}
PlayerState_WallSlide::~PlayerState_WallSlide()
{

}

void PlayerState_WallSlide::Enter(Player& player)
{
    //std::cout << "Enter WallSlide" << std::endl;
    player.SetAnimation(Animations::PlayerAnimations::WallSlide);
}
void PlayerState_WallSlide::Exit()
{
    //std::cout << "Exit WallSlide" << std::endl;
}

PlayerState* PlayerState_WallSlide::Update(Player& player, std::vector<Entity*> entityList)
{
	player.ApplyGravity();
	player.ApplyInternalForces();
	player.HandleWallSliding(currentDirection);

    player.SetVelocityY(player.GetWallSlideSpeed());
	
    player.MoveHorizontal(entityList);

    if (player.MoveVertical(entityList) == Direction::BOTTOM)
    {
        return Transition(player, new PlayerState_Idle());
    }
    
    return nullptr;

}
PlayerState* PlayerState_WallSlide::GetInput(Player& player, PlayerActions action, InputType type)
{
    if (type != InputType::RELEASED)
    {
        switch(action)
        {
        case PlayerActions::MOVE_LEFT:
            if (currentDirection != Direction::LEFT)
            {
                return Transition(player, new PlayerState_Fall());
            }
            break;
        case PlayerActions::MOVE_RIGHT:
            if (currentDirection != Direction::RIGHT)
            {
                return Transition(player, new PlayerState_Fall());
            }
            break;
        default:
            break;
        }
    }
    if (type == InputType::PRESSED)
    {
        switch(action)
        {
        case PlayerActions::JUMP:
            return Transition(player, new PlayerState_WallJump(currentDirection));
        }
    }
    if (type == InputType::RELEASED)
    {
        switch(action)
        {
        case PlayerActions::MOVE_LEFT:
            if (currentDirection == Direction::LEFT)
            {
                return Transition(player, new PlayerState_Fall());
            }
            break;
        case PlayerActions::MOVE_RIGHT:
            if (currentDirection == Direction::RIGHT)
            {
                return Transition(player, new PlayerState_Fall());
            }
            break;
        }
    }
    return nullptr;
}