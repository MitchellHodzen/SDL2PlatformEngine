#pragma once
#include "PlayerState.h"
#include "Player.h"
#include "PlayerState_Airborne.h"
class PlayerState_Grounded: public PlayerState
{
public:
	PlayerState_Grounded(){}
	virtual ~PlayerState_Grounded(){}
	virtual void Enter(Player& player){}
    virtual void Exit(){}
	virtual PlayerState* GetInput(Player& player, PlayerActions action, InputType type);
    virtual void Update(Player& player, std::vector<Entity*> entityList);
};