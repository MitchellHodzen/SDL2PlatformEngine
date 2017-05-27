#pragma once
#include "PlayerState.h"

class PlayerState_Grounded: public PlayerState
{
public:
	PlayerState_Grounded(){}
	virtual ~PlayerState_Grounded(){}
	virtual void Enter(Player& player){}
    virtual void Exit(){}
	virtual PlayerState* GetInput(Player& player, PlayerActions action, InputType type){return nullptr;}
    virtual void Update(Player& player, float deltaTime){}
};