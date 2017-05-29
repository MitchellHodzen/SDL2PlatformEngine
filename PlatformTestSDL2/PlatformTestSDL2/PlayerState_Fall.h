#pragma once
#include "PlayerState_Airborne.h"
//#include "Player.h"

class PlayerState_Fall: public PlayerState_Airborne
{
public:
	PlayerState_Fall();
	~PlayerState_Fall();
	void Enter(Player& player);
    void Exit();
	PlayerState* GetInput(Player& player, PlayerActions action, InputType type);
    PlayerState* Update(Player& player, std::vector<Entity*> entityList);
};