#pragma once
#include "PlayerState_Jump.h"

class PlayerState_WallJump: public PlayerState_Jump
{
public:
	PlayerState_WallJump(Direction direction);
	~PlayerState_WallJump();
	void Enter(Player& player);
    void Exit();
	PlayerState* GetInput(Player& player, PlayerActions action, InputType type);
    PlayerState* Update(Player& player, std::vector<Entity*> entityList);
protected:
	Direction startDirection;
};