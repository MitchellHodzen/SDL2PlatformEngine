#pragma once
#include "PlayerState_Grounded.h"
#include "Player.h"

#include "PlayerState_Idle.h"
class PlayerState_Run: public PlayerState_Grounded
{
public:
	PlayerState_Run(bool runningRight);
	~PlayerState_Run();
	void Enter(Player& player);
    void Exit();
	PlayerState* GetInput(Player& player, PlayerActions action, InputType type);
    void Update(Player& player, float deltaTime);
	void SetDirection(bool runningRight);
private:
	bool runningRight = true;
};