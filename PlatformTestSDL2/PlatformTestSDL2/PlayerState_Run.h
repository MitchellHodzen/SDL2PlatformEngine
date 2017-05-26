#pragma once
#include "PlayerState.h"
#include "Player.h"

#include "PlayerState_Idle.h"
class PlayerState_Run: public PlayerState
{
public:
	PlayerState_Run();
	~PlayerState_Run();
	void Enter(Player& player);
    void Exit();
	PlayerState* GetInput(Player& player, PlayerActions action, InputType type);
    void Update(Player& player);
};