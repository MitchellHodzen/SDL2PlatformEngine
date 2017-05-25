#pragma once
#include "PlayerState.h"
#include "Player.h"

class PlayerState_Idle: public PlayerState
{
public:
	PlayerState_Idle();
	~PlayerState_Idle();
	void Enter(Player& player);
    void Exit();
	void GetInput(Player& player, PlayerActions action, InputType type);
    void Update(Player& player);
};