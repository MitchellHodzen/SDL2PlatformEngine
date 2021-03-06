#pragma once
#include "PlayerState_Grounded.h"

class PlayerState_Idle: public PlayerState_Grounded
{
public:
	PlayerState_Idle();
	~PlayerState_Idle();
	void Enter(Player& player);
    void Exit();
	PlayerState* GetInput(Player& player, PlayerActions action, InputType type);
    PlayerState* Update(Player& player, std::vector<Entity*> entityList);
};